// HEADER FILE
#pragma chip PIC16F57, core 12, code 2048, ram 8 : 0x7F

#pragma config_def 0x0011

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTA, PORTB;
  char OPTION, TRISA, TRISB;
  char PORTC, TRISC;
  bit Carry, DC, Zero_, PD, TO, PA0, PA1, PA2;
  bit FSR_5, FSR_6;
*/

#pragma bit RA0   @ 5.0
#pragma bit RA1   @ 5.1
#pragma bit RA2   @ 5.2
#pragma bit RA3   @ 5.3

#pragma bit RB0   @ 6.0
#pragma bit RB1   @ 6.1
#pragma bit RB2   @ 6.2
#pragma bit RB3   @ 6.3
#pragma bit RB4   @ 6.4
#pragma bit RB5   @ 6.5
#pragma bit RB6   @ 6.6
#pragma bit RB7   @ 6.7

#pragma bit RC0   @ 7.0
#pragma bit RC1   @ 7.1
#pragma bit RC2   @ 7.2
#pragma bit RC3   @ 7.3
#pragma bit RC4   @ 7.4
#pragma bit RC5   @ 7.5
#pragma bit RC6   @ 7.6
#pragma bit RC7   @ 7.7
