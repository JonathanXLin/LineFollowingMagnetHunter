// HEADER FILE
#pragma chip PIC16C505, core 12, code 1023, ram 8 : 0x7F
// NOTE: last code location is omitted   ^--

#pragma resetVector 0

#pragma config_def 0x0022

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTA, PORTB;
  char OPTION, TRISA, TRISB;
  bit Carry, DC, Zero_, PD, TO, PA0, PA1, PA2;
  bit FSR_5, FSR_6;
*/

#pragma char OSCCAL @ 5

#pragma bit RBWUF @ 3.7

#pragma bit CAL0  @ 5.2
#pragma bit CAL1  @ 5.3
#pragma bit CAL2  @ 5.4
#pragma bit CAL3  @ 5.5
#pragma bit CAL4  @ 5.6
#pragma bit CAL5  @ 5.7

#pragma bit RB0   @ 6.0
#pragma bit RB1   @ 6.1
#pragma bit RB2   @ 6.2
#pragma bit RB3   @ 6.3
#pragma bit RB4   @ 6.4
#pragma bit RB5   @ 6.5

#pragma bit RC0   @ 7.0
#pragma bit RC1   @ 7.1
#pragma bit RC2   @ 7.2
#pragma bit RC3   @ 7.3
#pragma bit RC4   @ 7.4
#pragma bit RC5   @ 7.5
