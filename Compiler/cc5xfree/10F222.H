// HEADER FILE
#pragma chip PIC10F222, core 12, code 511, ram 9 : 0x1F
// NOTE: last code location is omitted  ^--

#pragma resetVector 0

#pragma config_def 0x0010

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR;
  char OPTION;
  bit Carry, DC, Zero_, PD, TO;
*/

#pragma char OSCCAL @ 5
#pragma char GPIO   @ 6
#pragma char ADCON0 @ 7
#pragma char ADRES  @ 8

#pragma char TRISGPIO @ TRISB

#pragma bit GPWUF @ STATUS.7

#pragma bit FOSC4 @ OSCCAL.0

#pragma bit GP0   @ GPIO.0
#pragma bit GP1   @ GPIO.1
#pragma bit GP2   @ GPIO.2
#pragma bit GP3   @ GPIO.3

#pragma bit ADON  @ ADCON0.0
#pragma bit GO    @ ADCON0.1
#pragma bit CHS0  @ ADCON0.2
#pragma bit CHS1  @ ADCON0.3
#pragma bit ANS0  @ ADCON0.6
#pragma bit ANS1  @ ADCON0.7

#pragma bit GPPU_ @ OPTION.6
#pragma bit GPWU_ @ OPTION.7
