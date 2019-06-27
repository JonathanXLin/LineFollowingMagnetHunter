// HEADER FILE
#pragma chip PIC16C712, core 14, code 1024, ram 32 : 0xBF

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

#pragma char DATACCP @ 7

#pragma char PIR1    @ 12

#pragma char TMR1L   @ 14
#pragma char TMR1H   @ 15
#pragma char T1CON   @ 16
#pragma char TMR2    @ 17
#pragma char T2CON   @ 18

#pragma char CCPR1L  @ 21
#pragma char CCPR1H  @ 22
#pragma char CCP1CON @ 23

#pragma char ADRES   @ 30
#pragma char ADCON0  @ 31

#pragma char TRISCCP @ 0x87

#pragma char PIE1    @ 0x8C
#pragma char PCON    @ 0x8E

#pragma char PR2     @ 0x92

#pragma char ADCON1  @ 0x9F

#pragma bit  DT1CK   @ 7.0
#pragma bit  DCCP    @ 7.2

#pragma bit  PEIE    @ 11.6  mapped_into_bank_1

#pragma bit  TMR1IF  @ 12.0
#pragma bit  TMR2IF  @ 12.1
#pragma bit  CCP1IF  @ 12.2
#pragma bit  ADIF    @ 12.6

#pragma bit  TMR1ON  @ 16.0
#pragma bit  TMR1CS  @ 16.1
#pragma bit  T1SYNC_ @ 16.2
#pragma bit  T1OSCEN @ 16.3
#pragma bit  T1CKPS0 @ 16.4
#pragma bit  T1CKPS1 @ 16.5

#pragma bit  T2CKPS0 @ 18.0
#pragma bit  T2CKPS1 @ 18.1
#pragma bit  TMR2ON  @ 18.2
#pragma bit  TOUTPS0 @ 18.3
#pragma bit  TOUTPS1 @ 18.4
#pragma bit  TOUTPS2 @ 18.5
#pragma bit  TOUTPS3 @ 18.6

#pragma bit  CCP1M0  @ 23.0
#pragma bit  CCP1M1  @ 23.1
#pragma bit  CCP1M2  @ 23.2
#pragma bit  CCP1M3  @ 23.3
#pragma bit  DC1B0   @ 23.4
#pragma bit  DC1B1   @ 23.5

#pragma bit  ADON    @ 31.0
#pragma bit  GO      @ 31.2
#pragma bit  CHS0    @ 31.3
#pragma bit  CHS1    @ 31.4
#pragma bit  CHS2    @ 31.5
#pragma bit  ADCS0   @ 31.6
#pragma bit  ADCS1   @ 31.7

#pragma bit  TT1CK   @ 0x87.0
#pragma bit  TCCP    @ 0x87.2

#pragma bit  TMR1IE  @ 0x8C.0
#pragma bit  TMR2IE  @ 0x8C.1
#pragma bit  CCP1IE  @ 0x8C.2
#pragma bit  ADIE    @ 0x8C.6

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1

#pragma bit  PCFG0   @ 0x9F.0
#pragma bit  PCFG1   @ 0x9F.1
#pragma bit  PCFG2   @ 0x9F.2
