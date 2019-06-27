// HEADER FILE
#pragma chip PIC12F510, core 12, code 1023, ram 10 : 0x3F
// NOTE: last code location is omitted   ^--

#pragma resetVector 0

#pragma config_def 0x0010

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR;
  char OPTION;
  bit Carry, DC, Zero_, PD, TO, PA0;
  bit FSR_5, FSR_6;
*/

#pragma char OSCCAL  @ 5
#pragma char GPIO    @ 6
#pragma char CM1CON0 @ 7
#pragma char ADCON0  @ 8
#pragma char ADRES   @ 9

#pragma char TRISGPIO @ TRISB

#pragma bit  CWUF     @ STATUS.6
#pragma bit  GPWUF    @ STATUS.7

#pragma bit  GP0      @ GPIO.0
#pragma bit  GP1      @ GPIO.1
#pragma bit  GP2      @ GPIO.2
#pragma bit  GP3      @ GPIO.3
#pragma bit  GP4      @ GPIO.4
#pragma bit  GP5      @ GPIO.5

#pragma bit  C1WU_    @ CM1CON0.0
#pragma bit  C1PREF   @ CM1CON0.1
#pragma bit  C1NREF   @ CM1CON0.2
#pragma bit  C1ON     @ CM1CON0.3
#pragma bit  C1T0CS_  @ CM1CON0.4
#pragma bit  C1POL    @ CM1CON0.5
#pragma bit  C1OUTEN_ @ CM1CON0.6
#pragma bit  C1OUT    @ CM1CON0.7

#pragma bit  ADON     @ ADCON0.0
#pragma bit  GO       @ ADCON0.1
#pragma bit  CHS0     @ ADCON0.2
#pragma bit  CHS1     @ ADCON0.3
#pragma bit  ADCS0    @ ADCON0.4
#pragma bit  ADCS1    @ ADCON0.5
#pragma bit  ANS0     @ ADCON0.6
#pragma bit  ANS1     @ ADCON0.7
