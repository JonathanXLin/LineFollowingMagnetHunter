// HEADER FILE
#pragma chip PIC16F505, core 12, code 1023, ram 8 : 0x7F
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

#pragma bit RBWUF @ STATUS.7

#pragma bit RB0   @ PORTB.0
#pragma bit RB1   @ PORTB.1
#pragma bit RB2   @ PORTB.2
#pragma bit RB3   @ PORTB.3
#pragma bit RB4   @ PORTB.4
#pragma bit RB5   @ PORTB.5

#pragma bit RC0   @ PORTC.0
#pragma bit RC1   @ PORTC.1
#pragma bit RC2   @ PORTC.2
#pragma bit RC3   @ PORTC.3
#pragma bit RC4   @ PORTC.4
#pragma bit RC5   @ PORTC.5
