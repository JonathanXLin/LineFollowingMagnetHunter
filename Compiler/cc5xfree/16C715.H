// HEADER FILE
#pragma chip PIC16C715, core 14, code 2048, ram 32 : 0xBF

#define INT_med_style

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

#pragma char PIR1    @ 12
#pragma char ADRES   @ 30
#pragma char ADCON0  @ 31

#pragma char PIE1    @ 0x8C
#pragma char PCON    @ 0x8E
#pragma char ADCON1  @ 0x9F

#pragma bit  PEIE    @ 11.6  mapped_into_bank_1

#pragma bit  ADIF    @ 12.6

#pragma bit  ADON    @ 31.0
#pragma bit  GO      @ 31.2
#pragma bit  CHS0    @ 31.3
#pragma bit  CHS1    @ 31.4
#pragma bit  CHS2    @ 31.5
#pragma bit  ADCS0   @ 31.6
#pragma bit  ADCS1   @ 31.7

#pragma bit  ADIE    @ 0x8C.6

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1
#pragma bit  PER_    @ 0x8E.2
#pragma bit  MPEEN   @ 0x8E.7

#pragma bit  PCFG0   @ 0x9F.0
#pragma bit  PCFG1   @ 0x9F.1
