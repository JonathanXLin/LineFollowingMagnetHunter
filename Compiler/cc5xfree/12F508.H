// HEADER FILE
#pragma chip PIC12F508, core 12, code 511, ram 7 : 0x1F
// NOTE: last code location is omitted  ^--

#pragma resetVector 0

#pragma config_def 0x0011

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR;
  char OPTION;
  bit Carry, DC, Zero_, PD, TO, PA0, PA1, PA2;
  bit FSR_5, FSR_6;
*/

#pragma char OSCCAL @ 5
#pragma char GPIO   @ 6
#pragma char TRISGPIO @ TRISB

#pragma bit GPWUF @ STATUS.7

#pragma bit GP0   @ GPIO.0
#pragma bit GP1   @ GPIO.1
#pragma bit GP2   @ GPIO.2
#pragma bit GP3   @ GPIO.3
#pragma bit GP4   @ GPIO.4
#pragma bit GP5   @ GPIO.5
