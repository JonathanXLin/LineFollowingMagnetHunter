/*
  STATE MACHINES AND SOFTWARE TIMERS
  ==================================

  State machines are useful when many signals have to
  be handled independent.

  STATE MACHINE 1:
      key debouncing: key accepted when stable for 50
      millisec.

  STATE MACHINE 2:
      generates a pattern on PIN 1 and PIN 2 when key
      is pressed:

      PIN 1:    |^^^^^^^^^^^^^^^^^|__________ _ _ _ _

      PIN 2:    _______|^^^^^|_______________ _ _ _ _

                |      |     |    |         |
                0      60    100  130       500  millisec.

  SOFTWARE TIMERS:
      timer 1 is assigned to finite state machine 1
      timer 2 is assigned to finite state machine 2

  Note: The timing assumes a 4 MHz oscillator
*/

/*  IO-CONFIGURATION: */
#define  Konfig_portA  0x01  /* xxxx 0001, 0=Output */
#define  Init_portA    0x00  /* 0000 0000 */

#define  Konfig_portB  0x00  /* 0000 0000, 0=Output */
#define  Init_portB    0x00  /* 0000 0000 */
/*
    Port   I/O   Name

    A.0    I     key
    A.1    O     -
    A.2    O     -
    A.3    O     -

    B.0    O     PIN1
    B.1    O     PIN2
    B.2    O     -
    B.3    O     -
    B.4    O     -
    B.5    O     -
    B.6    O     -
    B.7    O     -
*/
#pragma  bit  key     @ PORTA.0
#pragma  bit  PIN1    @ PORTB.0
#pragma  bit  PIN2    @ PORTB.1

#define Delay_1  ( 60 - 0 )
#define Delay_2  (100 - 60)
#define Delay_3  (130 - 100)
#define Delay_4  (500 - 130)

#define   OPEN        1
#define   PRESSING    2
#define   PRESSED     3
#define   OPENING     4

#define   READY       1
#define   STEP1       2
#define   STEP2       3
#define   STEP3       4
#define   STEP4       5

char previousTMR0, subClock;
char timer1, timer2L, timer2H;
bit timeout1, timeout2;
char state1, state2;
bit keyState;

void timerTick( void)
/*
 - decrements active timers
 - 4 MHz oscillator
 - period: 1 millisec. (prescaler divide by 8)
 - subClock: 0 .. 125
*/
{
    char sample, incr;

    sample = TMR0;  /* sampling the timer */
    incr = sample - previousTMR0;
    previousTMR0 = sample;

    subClock -= incr;

    if ( !Carry)  {
        /* new 1 millisec. tick */
        subClock += 125;

        if ( !timeout1)  {
            timer1 -= 1;
            if ( timer1 == 255)
                timeout1 = 1;
        }
        if ( !timeout2)  {
            if ( -- timer2L == 255)  {
                if ( -- timer2H == 255)
                    timeout2 = 1;
            }
        }
    }
}

#define startTimer1( count)  {  \
    timer1 = count;             \
    timeout1 = 0;               \
}

#define startTimer2( count)  {  \
    timer2L = (count) % 256;    \
    timer2H = (count) / 256;    \
    timeout2 = 0;               \
}

void fsm1( void)
{
    switch ( state1)  {   /* state machine 1 */
      case OPEN:
        if ( key)  {
            startTimer1( 50);
            state1 = PRESSING;
        }
        break;

      case PRESSING:
        if ( key == 0)
            state1 = OPEN;
        else if ( timeout1)  {
            keyState = 1;
            state1 = PRESSED;
        }
        break;

      case PRESSED:
        if ( key == 0)  {
            startTimer1( 50);
            state1 = OPENING;
        }
        break;

      case OPENING:
        if ( key)
            state1 = PRESSED;
        else if ( timeout1)  {
            keyState = 0;
            state1 = OPEN;
        }
        break;
    }
}

void fsm2( void)
{
    switch ( state2)  {   /* state machine 2 */
      case READY:
        if ( keyState == 1)  {
            PIN1 = 1;
            startTimer2( Delay_1);
            state2 = STEP1;
        }
        break;

      case STEP1:
        if ( timeout2)  {
            PIN2 = 1;
            startTimer2( Delay_2);
            state2 = STEP2;
        }
        break;

      case STEP2:
        if ( timeout2)  {
            PIN2 = 0;
            startTimer2( Delay_3);
            state2 = STEP3;
        }
        break;

      case STEP3:
        if ( timeout2)  {
            PIN1 = 0;
            startTimer2( Delay_4);
            state2 = STEP4;
        }
        break;

      case STEP4:
        if ( timeout2)
            state2 = READY;
        break;
    }
}

void main ( void)
{
    /* initialize */
    PORTA = Init_portA;
    TRISA = Konfig_portA;
    PORTB = Init_portB;
    TRISB = Konfig_portB;
    timeout1 = 1;
    timeout2 = 1;
    state1 = READY;
    state2 = OPEN;
    keyState = 0;
    OPTION = 2;  /* prescaler divide by 8 */

    while (1)  {
        timerTick();   /* decrement timers */
        /* Not more than 1 (2) millisec.
           between each call to timerTick() */

        /* .. sample analog channels */
        /* .. do other IO communication */
        /* .. do global processing and testing */
        fsm1();
        fsm2();
        /* next loop */
    }
}
