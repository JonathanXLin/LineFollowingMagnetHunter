// HEADER FILE
#pragma chip PIC16C64A, core 14, code 2048, ram 32 : 0xBF

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

#pragma char PORTC   @ 7
#pragma char PORTD   @ 8
#pragma char PORTE   @ 9

#pragma char PIR1    @ 12
#pragma char TMR1L   @ 14
#pragma char TMR1H   @ 15
#pragma char T1CON   @ 16
#pragma char TMR2    @ 17
#pragma char T2CON   @ 18
#pragma char SSPBUF  @ 19
#pragma char SSPCON  @ 20
#pragma char CCPR1L  @ 21
#pragma char CCPR1H  @ 22
#pragma char CCP1CON @ 23

#pragma char TRISC   @ 0x87
#pragma char TRISD   @ 0x88
#pragma char TRISE   @ 0x89

#pragma char PIE1    @ 0x8C
#pragma char PCON    @ 0x8E

#pragma char PR2     @ 0x92
#pragma char SSPADD  @ 0x93
#pragma char SSPSTAT @ 0x94

#pragma bit  PEIE    @ 11.6  mapped_into_bank_1

#pragma bit  TMR1IF  @ 12.0
#pragma bit  TMR2IF  @ 12.1
#pragma bit  CCP1IF  @ 12.2
#pragma bit  SSPIF   @ 12.3
#pragma bit  PSPIF   @ 12.7

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

#pragma bit  SSPM0   @ 20.0
#pragma bit  SSPM1   @ 20.1
#pragma bit  SSPM2   @ 20.2
#pragma bit  SSPM3   @ 20.3
#pragma bit  CKP     @ 20.4
#pragma bit  SSPEN   @ 20.5
#pragma bit  SSPOV   @ 20.6
#pragma bit  WCOL    @ 20.7

#pragma bit  CCP1M0  @ 23.0
#pragma bit  CCP1M1  @ 23.1
#pragma bit  CCP1M2  @ 23.2
#pragma bit  CCP1M3  @ 23.3
#pragma bit  CCP1Y   @ 23.4
#pragma bit  CCP1X   @ 23.5

#pragma bit  PSPMODE @ 0x89.4
#pragma bit  IBOV    @ 0x89.5
#pragma bit  OBF     @ 0x89.6
#pragma bit  IBF     @ 0x89.7

#pragma bit  TMR1IE  @ 0x8C.0
#pragma bit  TMR2IE  @ 0x8C.1
#pragma bit  CCP1IE  @ 0x8C.2
#pragma bit  SSPIE   @ 0x8C.3
#pragma bit  PSPIE   @ 0x8C.7

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1

#pragma bit  BF      @ 0x94.0
#pragma bit  UA      @ 0x94.1
#pragma bit  RW_     @ 0x94.2
#pragma bit  S       @ 0x94.3
#pragma bit  P       @ 0x94.4
#pragma bit  DA_     @ 0x94.5

