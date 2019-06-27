#pragma chip PIC16F873A
// define device

/*
;**********************************************************************
;
;    Filename:	    mte220.c
;    Date:          Oct 24, 2006
;    File Version:  3.5
;
;    Author:        C.C.W. Hulls & D.L. Wight
;
;    Copyright (c) C.C.W. Hulls, P.Eng and D.L. Wight, 2005.
;    This software can be used and modified by students, staff and
;    faculty members at the University of Waterloo for teaching or
;    research purposes, provided the authors are acknowledged.
;
;**********************************************************************
;
;    Files required:
;
;**********************************************************************
;
;    History:
;
;    3.5  Oct 24/06  Changes made by C. Caradima and K. Luscott
;		     Customized SERVO_1_MS, SERVO_LEFT_STOP,SERVO_RIGHT_STOP, 
;                    SERVO_2_MS
;                    Replaced SERVO_1_5_MS with SERVO_LEFT_STOP,SERVO_RIGHT_STOP
;                    because the two motors stop for different on-time values of the pwm signal.
;                    Calculated # of ticks are based on a tick duration of 0.4us.
; 
;    3.4  Nov 23/05  Disabled weak pull-ups on Port B (causing problems
;					 with the push button).
;    3.3  Nov 23/05  Added wait (using tight polling) for button push;
;    3.2  Nov 22/05  Added encoder counting; zero encoder count function;
;    3.1  Nov 12/05  Added macros to turn on and off LED; add delay
;                    function which provides instruction counted ~0.5ms
;                    delay; added servo motor macros; general code cleanup;
;    3.0  Nov  7/05  Main code split into separate file that loads the
;                    functions needed for MTE 220
;
;    2.0  Nov  5/05  Ported to C;
;
;    1.1  Oct 25/05  Changed the phase of right servo to be midway
;                    through the entire cycle; enable peripheral interrupts
;                    as part of interrupt initialization
;    1.0  Oct 24/05  Original release
;
;**********************************************************************
;**********************************************************************
;
;    Description:
;
;   ADC conversion is implemented for all 5 analog ports.  The ports are
;   selected using:
;     IR sensor difference for line following  ADC_IR_SENSOR
;     microphone                               ADC_SOUND
;     Hall effect sensor for magnetic field    ADC_HALL_EFFECT
;     themister sensor                         ADC_THERMAL
;     motor current                            ADC_MOTOR_CURRENT
;   Conversion synchronization is handled using polling.  Although the
;   ADC produces a 10-bit value, the two LSB are dropped to give an 8-bit
;   unsigned value representing 0V to 5V.
;
;   Timing for the servos is handled using Timer 0 and Timer 1.  Timer 0
;   is used for timing out the entire cycle.  It is set for 1:2 prescale,
;   which means it times out after 256 counts and generates an interrupt
;   every ~0.2ms.  The total servo cycle is 18ms, but this is divided into
;   two parts of 9 ms each, corresponding to 44 Timer 0 interrupts.  At the
;   start of the first phase of the cycle the left servo output is set high
;   and Timer 1 is set for the desired left servo time.  At the start of the
;   second phase of the cycle the right servo output is set high and Timer 1
;   is set for the desired right servo time.
;
;   Timer 1 is used to turn off the servos.  It is a 16-bit timer than
;   generates an interrupt when the unsigned timer rolls over.  When the
;   servos are turned on, the counter for timer 1 is set so that the desired
;   length of time is given by the remaining number of ticks until 0xFF -> 0x00.
;   At 1:1 prescale, each tick is approximately 0.475 us as measured on the
;   scope. The length of time to execute instructions is NOT taken into account
;   by the servo timing.  Latency from servicing another interrupt is NOT
;   taken into account.  So there is the potential for the latency to vary,
;   and for it to be longer than expected.  
;
;   To turn on and off the LED is only one line of code.  Rather than provide
;   a function which would incur the overhead of a function call (which the
;   compiler will not inline as an optimization), turning on and off the LEDs
;   is handled using a macro #define.
;
;   The encoders are checked every 9ms (when the servo cycle is started for
;   either the left or the right servo.  If a transition to high has occurred,
;   then the encoder count is incremented.  The counts are unsigned 16 bit
;   numbers so will rollover at 65535+1.
;
;   A push of the button is checked for using tight polling.  Debouncing is
;   handled in software by simply verifying that the signal is still high after
;   0.125ms.
;
;**********************************************************************
;
;    Notes:
;
;   The file sample2.c that comes with the PIC CC5X compiler from 
;   B Knudsen Data was used as a template for this code.
;
;   Refer to the respective PICmicro data sheet for additional
;   information on the instruction set.
;
;   Refer to the PICmicro Mid-Range MCU Family Reference Manual for
;   more details on writing the software.
;
;**********************************************************************
*/
#include "int16CXX.h"  // device dependent interrupt definitions

//;**********************************************************************
// embed configuration data - DO NOT CHANGE THIS VALUE
#pragma config = 0x3FFA

//;**********************************************************************
// function prototypes
void Timer0_ISR(void);
void Timer1_ISR(void);

//;**********************************************************************
// constant declarations
#define	SERVO_CYCLE	0x2C	// 88 * 0.2ms = 18 ms for entire servo cycle
				// value of 88 was measured on the scope
				// will use half cycle value for 2 phases

#define	ADC_IR_SENSOR	0x00	// AN0
#define	ADC_SOUND	0x08	// AN1
#define	ADC_HALL_EFFECT	0x10	// AN2
#define	ADC_THERMAL	0x18	// AN3
#define	ADC_MOTOR_CURRENT	0x20	// AN4

/* F05 settings
 #define SERVO_1MS	(uns16)2115  // 2115 ticks for 1 ms
 #define SERVO_1_5MS	(uns16)3172  // 3172 ticks for 1.5 ms
 #define SERVO_2MS	(uns16)4230  // 4230 ticks for 2 ms
*/

// F06 settings (to be customized by each group)
#define SERVO_1MS	(uns16)2500  // 2500 ticks for 1 ms
#define SERVO_LEFT_STOP	(uns16)3750  // 3750 ticks for 1.5 ms
#define SERVO_RIGHT_STOP (uns16)3750  // 3750 ticks for 1.5 ms
#define SERVO_2MS	(uns16)5000  // 5000 ticks for 2 ms


//;**********************************************************************
// global variable declarations used by ISRs

uns8 servo_status;	// current status of servos
			// bit 0 overall control 1=on
			// bit 1 phase of servo cycle 0=1st, 1=2nd

uns8 cycle_clock;	// # intervals Timer 0 intervals left in the cycle
uns16 servoLeft;	// # ticks the left servo is on in 1st cycle phase
uns16 servoRight;	// # ticks the right servo is on in 2nd cycle phase

uns16 encoderL_A;	// encoder counts
uns16 encoderL_B;
uns16 encoderR_A;
uns16 encoderR_B;
uns8  prevEncoder;      // encoder state at last check

//;**********************************************************************
// assign names to register bits
bit	RC0 @ PORTC.0;
bit	RC1 @ PORTC.1;
bit	RC2 @ PORTC.2;
bit	pushButton @ PORTB.0;

bit     servo_on_bit @ servo_status.0;
bit	servo_phase_bit @ servo_status.1;

//;**********************************************************************

// define macros

//;**********************************************************************
// Turn on and off the LED
#define  OnLED \
    RC0 = 1;
#define  OffLED \
    RC0 = 0;

// Turn servos on and off
#define  UseServos \
    servo_on_bit = 1;
#define  LeftServoOn \
    SetLeft(SERVO_1MS);
#define  LeftServoOff \
    SetLeft(SERVO_LEFT_STOP);
#define  RightServoOn \
    SetRight(SERVO_2MS);
#define  RightServoOff \
    SetRight(SERVO_RIGHT_STOP);
#define  BothServosOn \
    SetLeft(SERVO_1MS); \
    SetRight(SERVO_2MS);
#define  BothServosOff \
    SetLeft(SERVO_LEFT_STOP); \
    SetRight(SERVO_RIGHT_STOP);
#define Stop \
    BothServosOff
#define GoForward \
    BothServosOn
#define GoLeft \
    LeftServoOff \
    RightServoOn
#define GoRight \
    RightServoOff \
    LeftServoOn

//;**********************************************************************

// DO NOT, under any circumstances, remove dummy, put any code in
// between the dummy function and the start of the ISR, or put any code
// above this point.  The dummy function forces the ISR to be at address
// 0x04 since we cannot use pragma origin with the PIC programmer as it
// is currently written.

void dummy(void)
{
    nop();
    nop();
}

//#pragma origin 4   // start address of interrupt routine

interrupt generalISR(void)
{
    uns8 w_temp, status_temp; // variables used for context saving

    int_save_registers    // W, STATUS (and PCLATH if required)

    // GIE is left clear since don't need to be re-entrant

    // check Timer1 first so will have higher priority
    if ( TMR1IF )
    {
        Timer1_ISR();  // call Timer1 handler
        TMR1IF = 0;  // reset flag
    }

    // really should check status of Timer0 interrupt mask since flag will set on
    // overflow even if mask is clear
    else if ( T0IF )
    {
        if (servo_on_bit)  // check if servos in use
            Timer0_ISR();  // call Timer0 handler
        T0IF = 0;  // reset flag
    }

    // should really have an error handler here

    // context restore at end of interrupt
    int_restore_registers // W, STATUS (and PCLATH if required)
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           Timer0_ISR
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   cycle_clock, servoLeft, servoRight, PORTC,
;                       TIMER1H, TIMER1L, T1CON
;   Description:        Service Timer 0 interrupt for servos
;
;   Synopsis:           If the cycle is restarting, reset the cycle
;                       clock and turn on left or right servo and Timer 1
;                       with left or right servo timing depending on
;                       the phase of the cycle.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void Timer0_ISR(void)
{
    uns8 encoderValue, encoderClick;

    if (--cycle_clock)  // decrement cycle clock
        return;  // cycle is not finished

    if (servo_phase_bit)
    {
        // right servo
        servo_phase_bit = 0;
        TMR1H = servoRight.high8;  // set up timer 1 with right servo's cycle
        TMR1L = servoRight.low8;
        TMR1ON = 1;  // turn on timer 1
        RC2 = 1;  // turn right servo on
    }
    else
    {
        // left servo
        servo_phase_bit = 1;
        TMR1H = servoLeft.high8;  // set up timer 1 with left servo's cycle
        TMR1L = servoLeft.low8;
        TMR1ON = 1;  // turn on timer 1
        RC1 = 1;  // turn left servo on
    }

    cycle_clock = SERVO_CYCLE;  // reset cycle count

    // check encoders
    encoderValue = PORTB & 0x36;  // mask off non-encoder bits
    encoderClick = ~prevEncoder & encoderValue;  // which bits have changed to one
    if (encoderClick.1 != 0)  // increment encoder if changed to a one
        encoderR_A++;
    if (encoderClick.2 != 0)
        encoderR_B++;
    if (encoderClick.4 != 0)
        encoderL_B++;
    if (encoderClick.5 != 0)
        encoderL_A++;
    prevEncoder = encoderValue;  // set previous encoders to be current
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           Timer1_ISR
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   TMR1, PORTC
;   Description:        Service Timer 1 interrupt for servos
;
;   Synopsis:           Turn off servos and turn off timer1.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void Timer1_ISR(void)
{
    TMR1ON = 0;  // turn off timer 1

    RC1 = 0;  // left servo off
    RC2 = 0;  // right servo off
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           PortInit
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   PORTA, PORTB, PORTC, TRISA, TRISB, TRISC
;   Description:        Initialize I/O ports A, B, and C
;
;   Synopsis:           Initialize the output data latches and set
;                       the data directions as follows:
;
;   PORT     BIT  PIN NAME & FUNC DESC.              I/O      INIT
;   -------  ---  ---------------------------------  -------- ----
;   Port A:   0   AN0 - IR_range sensor              (input)  1
;             1   AN1 - sound                        (input)  1
;             2   AN2 - Hall effect sensor           (input)  1
;             3   AN3 - thermal sensor               (input)  1
;             4   RA4 - expansion                    (input)  1 (for now)
;             5   AN4 - motor current                (input)  1
;             6   Not used                                    x
;             7   Not used                                    x
;
;   Port B:   0   RB0/INT0 - push button             (input)  1
;             1   RB1 - encoder right B              (input)  1
;             2   RB2 - encoder right A              (input)  1
;             3   PGM - programmer enabled           (input)  1
;                 Low voltage ICSP programming (LVP) is enabled by
;                 default which disables RB3 I/O function
;             4   RB4 - encoder left B               (input)  1
;             5   RB5 - encoder left A               (input)  1
;             6   PGC - serial programming clock     (input)  1
;             7   PGD - serial programming data      (input)  1
;
;   Port C:   0   RC0 - LED on/off                   (output) 0
;             1   RC1 - servo motor left             (output) 0
;             2   RC2 - servo motor right            (output) 0
;             3   SCL - I2C clock                    (input)  1
;             4   SDA - I2C data                     (input)  1
;             5   RC5 - expansion                    (input)  1 (for now)
;             6   RC6 - sonar xmit                   (input)  1 (for now)
;             7   RC5 - sonar rcv                    (input)  1
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void PortInit(void)
{
// Intialize the I/O port data latches

    PORTA = 0;  // Clear the Port A output data latches
    PORTB = 0;  // Clear the Port B output data latches
    PORTC = 0;  // Clear the Port C output data latches


    // Set the data direction (input/output) for the pins on each I/O port

    TRISA = 0xFF;  // Set Port A I/O to B'1111 1111' (1=input)

    TRISB = 0xFF;  // Set Port B I/O to B'1111 1111' (1=input)

    TRISC = 0xF8;  // Set Port C I/O to B'1111 1000' (1=input)

}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           ADCInit
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   ADCON1
;   Description:        Initialize the ADC
;
;   Synopsis:           Configure the ADCs as AN0-AN4.  The result is
;                       left justified in ADRESH, with 2-bits in ADRESL.
;                       Since we are going to drop the low bits, left
;                       justification makes this step easier.  The
;                       internal RC oscillator will be used for timing.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void ADCInit(void)
{

    // set ADC configuration

    ADCON1 = 0b00000010;  // left justified, internal RC oscillator,
			    // port control as 5 ports, Vref+=Vdd,
			    // Vref-=Vss
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           ZeroEncoderCount
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   encoderL_A, encoderL_B, encoderR_A,
;                       encoderR_B, prevEncoder
;   Description:        Clear the encoder counts.
;
;   Synopsis:           All encoder count variables are set to be zero.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void ZeroEncoderCount(void)
{
    encoderL_A = 0;   // clear counts
    encoderL_B = 0;
    encoderR_A = 0;
    encoderR_B = 0;
    prevEncoder = 0;  // initially all are assumed to be off
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           ServoInit
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   PORTC, encoderL_A, encoderL_B, encoderR_A,
;                       encoderR_B, prevEncoder
;   Description:        Initialize servos to be off
;
;   Synopsis:           RC1 and RC2 control the left and right servos.
;                       The direction of Port C is initialized by PortInit.
;                       This routine ensures the servos are off, and clears
;                       the status so they stay off until requested.  The
;                       encoder counts are initialized to be zero.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void ServoInit(void)
{
    RC1 = 0;  // turn left servo off
    RC2 = 0;  // turn right servo off

    servo_status = 0;  // status is off, first half of phase

    servoLeft = 0;  // clear servo control registers
    servoRight = 0;

    ZeroEncoderCount();
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           SetLeft
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   servoLeft
;   Description:        Calculate left servo timer values.
;
;   Synopsis:           Timer 1 ticks are measured to be ~0.475us on the
;                       scope.  Timer 1 interrupts when the 16-bit counter
;                       rolls over.  So, the value in servoL is
;                       65536 - number of ticks.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void SetLeft(uns16 numTick)
{
    // calculate value to count up from for the number of ticks
    servoLeft = ((uns16)0xFFFF - numTick);
    servoLeft++;
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           SetRight
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   servoRight
;   Description:        Calculate right servo timer values.
;
;   Synopsis:           Timer 1 ticks are measured to be ~0.475us on the
;                       scope.  Timer 1 interrupts when the 16-bit counter
;                       rolls over.  So, the value in servoL is
;                       65536 - number of ticks.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void SetRight(uns16 numTick)
{
    // calculate value to count up from for the number of ticks
    servoRight = ((uns16)0xFFFF - numTick);
    servoRight++;
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           TimerInit
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   OPTION_REG, T1CON, cycle_clock
;   Description:        Initialize Timer0 and Timer 1
;
;   Synopsis:           Timer 0 is used for timing the cycle for the
;                       servos.  At 1:2 it rolls over every 0.2 ms.  Timer 0
;                       is used to measure out the entire cycle.  Timer 1
;                       is used to produce the servo "on" pulse.  It is
;                       set for 1:1 prescale so each tick is 0.25 us.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void TimerInit(void)
{
    TMR0 = 0;  // clear Timer 0 register

    OPTION_REG = 0b10000000;  // internal clock, timer 0, 1:2 prescale, Port B pull ups disabled

    T1CON = 0b00000000;  // 1:1 prescale, oscillator off, internal clock,
                           // Timer 1 stopped

    // reset servo cycle clock to be 1 so will restart cycle once servos on
    cycle_clock = 1;
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           InterruptInit
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   INTCON, PEIE
;   Description:        Initialize interrupts
;
;   Synopsis:           At present timer 0 and timer 1 are the only
;                       interrupts in use.  Interrupts are turned off,
;                       and flags are cleared.  Then the timer0 mask and 
;                       timer1 mask are enabled and interrupts are turned on.
;                       Note however, that timer1 is stopped on
;                       initialization.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void InterruptInit(void)
{
    INTCON = 0;  // disable interrupts, clear flags

    T0IE = 1;  // enable Timer0 interrupts
    PEIE = 1;  // enable peripheral interrupts (used by Timer 1)

    TMR1IE = 1;  // enable Timer1 interrupts

    GIE = 1;  // enable interupts
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           Initialization
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   PORTA, PORTB, PORTC, TRISA, TRISB, TRISC,
;                       OPTION_REG,left_clock, right_clock,
;                       INTCON
;   Description:        Initialize the system after a reset
;
;   Synopsis:           Call the desired initialization functions.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void Initialization(void)
{

    PortInit();		// Initialize I/O ports A, B, and C
    ADCInit();		// Initialize the ADC

    ServoInit();	// initialize servos
    TimerInit();        // initialize Timer0 and Timer1 for servo timing
    InterruptInit();	//initialize Timer0 and Timer 1 interrupts
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           AnalogConvert
;   Inputs:             ADC_channel
;   Outputs:            8 bit analog value
;   Global Variables:   ADCON0
;   Description:        Get the analog value on the channel specified.
;
;   Synopsis:           Configure the ADCs as AN0-AN4.  The result is
;                       left justified in ADRESH, with 2-bits in ADRESL.
;                       Since we are going to drop the low 6-bits, left
;                       justification makes this step easier.  The
;                       internal RC oscillator will be used for timing.
;
;                       First the desired channel is selected.  Then a
;                       wait is added to make sure the sample and hold
;                       capacitor is fully charged.  The timing should
;                       be slightly greater than 60us of wait, which
;                       hopefully is enough for full scale.  Then
;                       conversion is started.  The function polls using
;                       a tight polling loop for end of conversion.
;                       Polling is used because it is simpler and there
;                       isn't a lot else going on in the system at the
;                       moment.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
uns8 AnalogConvert(uns8 ADC_channel)
{

    // initialize converter
    ADCON0 = 0b11000001 | ADC_channel;  // internal RC oscillator and power
                                        // up ADC, set channel as desired
    
    // wait for sample and hold capacitor to charge
    // For 10 MHz clock, the clock period is 0.1 us, instruction cycle is 4 periods
    // 1 Instruction cycle = 0.4 us, so for 60 us, 150 instruction cycles needed

    uns8 tw = 29;  // 2 cycles for initialization

    do ; while (--tw > 0);  // 5 * 28 cycles (iteration) + 3 cycle (last cycle)

    // start conversion
    GO = 1;

    // polling loop to wait for conversion complete
    while ( GO == 1 ) ;

    // get high 8 bits of conversion
    return ADRESH;
}


/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           Delay
;   Inputs:             count (value between 1 and 255, 0 is forced to 1)
;   Outputs:            none
;   Global Variables:   none
;   Description:        Wait approximately count * 0.5 us
;
;   Synopsis:           For 10 MHz clock, the clock period is 0.1 us,
;                       the instruction cycle is 4 periods or 0.4 us.
;                       Call and return = 4 cycles
;                       Parameter check = usually 4 cycles
;                       Inner loop = 2 + 5 * 248 + 4 = 1245 cycles
;                       Outer loop = (5 + 1246) * (count-1) + (4 + 1246) cycles
;                       Total = 1251 * count + 7 cycles
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void Delay(uns8 count)
{
    // 2 cycles for call + 3 cycles parameter passing + 2 cycles for return

    if (count == 0) count = 1;  // usually 4 cycles, but 5 if count was zero

    do
    {
        uns8 tw = 249;  // 2 cycles for initialization
        do ; while (--tw > 0);  // 5 * 248 cycles (iteration) + 3 cycle (last)
    }
    while (--count > 0);  // (5 + 1245) * (count-1) + (4 + 1245) cycle
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           LongDelay
;   Inputs:             count (value between 1 and 65535, 0 is forced to 1)
;   Outputs:            none
;   Global Variables:   none
;   Description:        Wait approximately count * 0.125 ms
;
;   Synopsis:           For 10 MHz clock, the clock period is 0.1 us,
;                       the instruction cycle is 4 periods or 0.4 us.
;                       Call and return = 9 cycles
;                       Parameter check = usually 7 cycles
;                       Call Delay =  312757 cycles
;                       Loop = 312768 * (count - 1) + 312767
;                       Total = 312768 * count + 12 cycles
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void LongDelay(uns16 count)
{
    // 2 cycles for call + 4 or 5 cycles parameter passing + 2 cycles for return

    if (count == 0) count = 1;  // usually 7 cycles, but 9 if count was zero

    do
    {
        Delay(250);  // 312757 cycles + 1
    }
    while (--count > 0);  // (11 + 312757) * (count-1) + (10 + 312757) cycle
}

/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;   Function:           WaitForButton
;   Inputs:             none
;   Outputs:            none
;   Global Variables:   none
;   Description:        Wait until the button has been pushed.
;
;   Synopsis:           The button input is polled using a tight polling
;                       loop until a one is detected.  Debouncing is
;                       handled in software as the button will only
;                       be considered pushed if the signal is still high
;                       after 0.125ms.  Note that the function doesn't
;                       check for a button release, so calling it too
;                       quickly will result in pushes being double
;                       counted.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
void WaitForButton(void)
{
    uns8 done;

    done = 0;  // not done
    do
    {
        while (pushButton == 0) ;  // tight poll for button push

        Delay(255);  // debounce
        if (pushButton == 1)
            done = 1;
    }
    while (done == 0);
}
