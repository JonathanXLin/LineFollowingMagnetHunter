// HEADER FILE
#pragma chip PIC16C554, core 14, code  512, ram 32 : 0x6F
#define INT_bank0_style

#pragma config_def 0x0111

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTA, PORTB;
  char OPTION, TRISA, TRISB;
  char PCLATH, INTCON;
  bit PS0, PS1, PS2, PSA, T0SE, T0CS, INTEDG, RBPU_;
  bit Carry, DC, Zero_, PD, TO, RP0, RP1, IRP;
  bit RBIF, INTF, T0IF, RBIE, INTE, T0IE, GIE;
  bit PA0, PA1;  // PCLATH
*/

#pragma char PCON    @ 0x8E

#pragma bit  POR_    @ 0x8E.1

#pragma bit  RA0     @ 5.0
#pragma bit  RA1     @ 5.1
#pragma bit  RA2     @ 5.2
#pragma bit  RA3     @ 5.3
#pragma bit  RA4     @ 5.4

#pragma bit  RB0     @ 6.0
#pragma bit  RB1     @ 6.1
#pragma bit  RB2     @ 6.2
#pragma bit  RB3     @ 6.3
#pragma bit  RB4     @ 6.4
#pragma bit  RB5     @ 6.5
#pragma bit  RB6     @ 6.6
#pragma bit  RB7     @ 6.7

#pragma bit  TRISA0  @ 0x85.0
#pragma bit  TRISA1  @ 0x85.1
#pragma bit  TRISA2  @ 0x85.2
#pragma bit  TRISA3  @ 0x85.3
#pragma bit  TRISA4  @ 0x85.4

#pragma bit  TRISB0  @ 0x86.0
#pragma bit  TRISB1  @ 0x86.1
#pragma bit  TRISB2  @ 0x86.2
#pragma bit  TRISB3  @ 0x86.3
#pragma bit  TRISB4  @ 0x86.4
#pragma bit  TRISB5  @ 0x86.5
#pragma bit  TRISB6  @ 0x86.6
#pragma bit  TRISB7  @ 0x86.7
