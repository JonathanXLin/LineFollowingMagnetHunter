// HEADER FILE
#pragma chip PIC16C642, core 14, code 4096, ram 32 : 0xFF
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_midgen_style
#define INT_rambank  0   /* bank 0 */

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

#pragma char PORTC   @ 7
#pragma char PIR1    @ 12
#pragma char CMCON   @ 31

#pragma char TRISC   @ 0x87
#pragma char PIE1    @ 0x8C
#pragma char PCON    @ 0x8E
#pragma char VRCON   @ 0x9F

#pragma bit  PEIE    @ 11.6  mapped_into_bank_1

#pragma bit  CMIF    @ 12.6

#pragma bit  CM0     @ 31.0
#pragma bit  CM1     @ 31.1
#pragma bit  CM2     @ 31.2
#pragma bit  CIS     @ 31.3
#pragma bit  C1OUT   @ 31.6
#pragma bit  C2OUT   @ 31.7

#pragma bit  CMIE    @ 0x8C.6

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1
#pragma bit  PER_    @ 0x8E.2
#pragma bit  MPEEN   @ 0x8E.7

#pragma bit  VR0     @ 0x9F.0
#pragma bit  VR1     @ 0x9F.1
#pragma bit  VR2     @ 0x9F.2
#pragma bit  VR3     @ 0x9F.3
#pragma bit  VRR     @ 0x9F.5
#pragma bit  VROE    @ 0x9F.6
#pragma bit  VREN    @ 0x9F.7
