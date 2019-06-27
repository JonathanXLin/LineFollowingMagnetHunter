// HEADER FILE
#pragma chip PIC16C711, core 14, code 1024, ram 12 : 0x4F mapped_into_bank_1

#define INT_min_style

#pragma config_def 0x1111

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

#pragma char ADCON0 @     8
#pragma char ADRES  @     9 mapped_into_bank_1

#pragma char PCON   @  0x87
#pragma char ADCON1 @  0x88

#pragma bit  ADON   @   8.0
#pragma bit  ADIF   @   8.1
#pragma bit  GO     @   8.2
#pragma bit  CHS0   @   8.3
#pragma bit  CHS1   @   8.4
#pragma bit  ADCS0  @   8.6
#pragma bit  ADCS1  @   8.7

#pragma bit  BOR_   @ 0x87.0
#pragma bit  POR_   @ 0x87.1

#pragma bit  PCFG0  @ 0x88.0
#pragma bit  PCFG1  @ 0x88.1

#pragma bit  ADIE   @  11.6 mapped_into_bank_1
