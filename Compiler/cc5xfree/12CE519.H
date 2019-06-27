// HEADER FILE
#pragma chip PIC12CE519, core 12, code 1023, ram 7 : 0x3F
// NOTE: last code location is omitted    ^--

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
#pragma char TRIS   @ TRISB

#pragma bit GPWUF @ 3.7

#pragma bit CAL0  @ 5.2
#pragma bit CAL1  @ 5.3
#pragma bit CAL2  @ 5.4
#pragma bit CAL3  @ 5.5
#pragma bit CAL4  @ 5.6
#pragma bit CAL5  @ 5.7

#pragma bit GP0   @ 6.0
#pragma bit GP1   @ 6.1
#pragma bit GP2   @ 6.2
#pragma bit GP3   @ 6.3
#pragma bit GP4   @ 6.4
#pragma bit GP5   @ 6.5
#pragma bit SDA   @ 6.6
#pragma bit SCL   @ 6.7
