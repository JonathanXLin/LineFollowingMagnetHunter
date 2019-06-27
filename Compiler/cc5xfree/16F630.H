// HEADER FILE
#ifndef ICD2_DEBUG
 #pragma chip PIC16F630, core 14, code 1024, ram 32 : 0x5F mapped_into_bank_1

#else
 #pragma chip PIC16F630, core 14, code 0x300, ram 32 : 0x5F mapped_into_bank_1
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char reservedICD2[12] @ 0x54;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging

#endif

#define INT_min_style

#pragma config_def 0x1222

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTA;
  char OPTION, TRISA;
  char PCLATH, INTCON;
  bit PS0, PS1, PS2, PSA, T0SE, T0CS, INTEDG, RBPU_;
  bit Carry, DC, Zero_, PD, TO, RP0, RP1, IRP;
  bit RBIF, INTF, T0IF, RBIE, INTE, T0IE, GIE;
  bit PA0, PA1;  // PCLATH
*/

#pragma char PORTC   @ 7

#pragma char PIR1    @ 12

#pragma char TMR1L   @ 14
#pragma char TMR1H   @ 15
#pragma char T1CON   @ 16

#pragma char CMCON   @ 25

#pragma char TRISC   @ 0x87

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E

#pragma char OSCCAL  @ 0x90

#pragma char WPUA    @ 0x95
#pragma char IOCA    @ 0x96

#pragma char VRCON   @ 0x99
#pragma char EEDAT   @ 0x9A
#pragma char EEADR   @ 0x9B
#pragma char EECON1  @ 0x9C
#pragma char EECON2  @ 0x9D

#pragma bit  RAIF    @ 11.0  mapped_into_all_banks
#pragma bit  RAIE    @ 11.3  mapped_into_all_banks
#pragma bit  PEIE    @ 11.6  mapped_into_all_banks

#pragma bit  TMR1IF  @ 12.0
#pragma bit  CMIF    @ 12.3
#pragma bit  EEIF    @ 12.7

#pragma bit  TMR1ON  @ 16.0
#pragma bit  TMR1CS  @ 16.1
#pragma bit  T1SYNC_ @ 16.2
#pragma bit  T1OSCEN @ 16.3
#pragma bit  T1CKPS0 @ 16.4
#pragma bit  T1CKPS1 @ 16.5
#pragma bit  T1GE    @ 16.6

#pragma bit  CM0     @ 25.0
#pragma bit  CM1     @ 25.1
#pragma bit  CM2     @ 25.2
#pragma bit  CIS     @ 25.3
#pragma bit  CINV    @ 25.4
#pragma bit  COUT    @ 25.6

#pragma bit  TRISA0  @ 0x85.0
#pragma bit  TRISA1  @ 0x85.1
#pragma bit  TRISA2  @ 0x85.2
#pragma bit  TRISA3  @ 0x85.3
#pragma bit  TRISA4  @ 0x85.4
#pragma bit  TRISA5  @ 0x85.5

#pragma bit  TRISC0  @ 0x87.0
#pragma bit  TRISC1  @ 0x87.1
#pragma bit  TRISC2  @ 0x87.2
#pragma bit  TRISC3  @ 0x87.3
#pragma bit  TRISC4  @ 0x87.4
#pragma bit  TRISC5  @ 0x87.5

#pragma bit  TMR1IE  @ 0x8C.0
#pragma bit  CMIE    @ 0x8C.3
#pragma bit  EEIE    @ 0x8C.7

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1

#pragma bit  CAL0    @ 0x90.2
#pragma bit  CAL1    @ 0x90.3
#pragma bit  CAL2    @ 0x90.4
#pragma bit  CAL3    @ 0x90.5
#pragma bit  CAL4    @ 0x90.6
#pragma bit  CAL5    @ 0x90.7

#pragma bit  WPUA0   @ 0x95.0
#pragma bit  WPUA1   @ 0x95.1
#pragma bit  WPUA2   @ 0x95.2
#pragma bit  WPUA4   @ 0x95.4
#pragma bit  WPUA5   @ 0x95.5

#pragma bit  IOCA0   @ 0x96.0
#pragma bit  IOCA1   @ 0x96.1
#pragma bit  IOCA2   @ 0x96.2
#pragma bit  IOCA3   @ 0x96.3
#pragma bit  IOCA4   @ 0x96.4
#pragma bit  IOCA5   @ 0x96.5

#pragma bit  VR0     @ 0x99.0
#pragma bit  VR1     @ 0x99.1
#pragma bit  VR2     @ 0x99.2
#pragma bit  VR3     @ 0x99.3
#pragma bit  VRR     @ 0x99.5
#pragma bit  VREN    @ 0x99.7

#pragma bit  RD      @ 0x9C.0
#pragma bit  WR      @ 0x9C.1
#pragma bit  WREN    @ 0x9C.2
#pragma bit  WRERR   @ 0x9C.3
