// HEADER FILE
#pragma chip PIC16HV540, core 12, code 512, ram 7 : 0x1F

#pragma stackLevels 4

#pragma config_def 0x0000

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTA, PORTB;
  char OPTION, TRISA, TRISB;
  bit Carry, DC, Zero_, PD, TO, PA0, PA1, PA2;
  bit FSR_5, FSR_6;
*/

#pragma char OPTION2 @ TRISC

#pragma bit PCF @ STATUS.7

#pragma bit RA0 @ PORTA.0
#pragma bit RA1 @ PORTA.1
#pragma bit RA2 @ PORTA.2
#pragma bit RA3 @ PORTA.3

#pragma bit RB0 @ PORTB.0
#pragma bit RB1 @ PORTB.1
#pragma bit RB2 @ PORTB.2
#pragma bit RB3 @ PORTB.3
#pragma bit RB4 @ PORTB.4
#pragma bit RB5 @ PORTB.5
#pragma bit RB6 @ PORTB.6
#pragma bit RB7 @ PORTB.7

