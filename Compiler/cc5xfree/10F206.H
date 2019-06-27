// HEADER FILE
#pragma chip PIC10F206, core 12, code 511, ram 8 : 0x1F
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
#pragma char CMCON0 @ 7

#pragma char TRISGPIO @ TRISB

#pragma bit CWUF  @ STATUS.6
#pragma bit GPWUF @ STATUS.7

#pragma bit FOSC4 @ OSCCAL.0

#pragma bit GP0   @ GPIO.0
#pragma bit GP1   @ GPIO.1
#pragma bit GP2   @ GPIO.2
#pragma bit GP3   @ GPIO.3

#pragma bit CWU_     @ CMCON0.0
#pragma bit CPREF    @ CMCON0.1
#pragma bit CNREF    @ CMCON0.2
#pragma bit CMPON    @ CMCON0.3
#pragma bit CMPT0CS_ @ CMCON0.4
#pragma bit POL      @ CMCON0.5
#pragma bit COUTEN_  @ CMCON0.6
#pragma bit CMPOUT   @ CMCON0.7
