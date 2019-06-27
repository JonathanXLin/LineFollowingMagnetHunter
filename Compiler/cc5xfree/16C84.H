// HEADER FILE
#pragma chip PIC16C84, core 14, code 1024, ram 12 : 0x2F mapped_into_bank_1

#define INT_min_style

#pragma config_def 0x0011

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

#pragma char EEDATA  @ 8
#pragma char EEADR   @ 9

#pragma char EECON1  @ 0x88
#pragma char EECON2  @ 0x89

#pragma bit  EEIE    @ 11.6 mapped_into_bank_1

#pragma bit  RD      @ 0x88.0
#pragma bit  WR      @ 0x88.1
#pragma bit  WREN    @ 0x88.2
#pragma bit  WRERR   @ 0x88.3
#pragma bit  EEIF    @ 0x88.4
