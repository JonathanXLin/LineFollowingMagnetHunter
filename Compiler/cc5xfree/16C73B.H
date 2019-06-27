// HEADER FILE
#pragma chip PIC16C73B, core 14, code 4096, ram 32 : 0xFF

#define INT_max_style

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
#pragma char PIR2    @ 13
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
#pragma char RCSTA   @ 24
#pragma char TXREG   @ 25
#pragma char RCREG   @ 26
#pragma char CCPR2L  @ 27
#pragma char CCPR2H  @ 28
#pragma char CCP2CON @ 29
#pragma char ADRES   @ 30
#pragma char ADCON0  @ 31

#pragma char TRISC   @ 0x87

#pragma char PIE1    @ 0x8C
#pragma char PIE2    @ 0x8D
#pragma char PCON    @ 0x8E

#pragma char PR2     @ 0x92
#pragma char SSPADD  @ 0x93
#pragma char SSPSTAT @ 0x94

#pragma char TXSTA   @ 0x98
#pragma char SPBRG   @ 0x99

#pragma char ADCON1  @ 0x9F

#pragma bit  PEIE    @ 11.6  mapped_into_bank_1

#pragma bit  TMR1IF  @ 12.0
#pragma bit  TMR2IF  @ 12.1
#pragma bit  CCP1IF  @ 12.2
#pragma bit  SSPIF   @ 12.3
#pragma bit  TXIF    @ 12.4
#pragma bit  RCIF    @ 12.5
#pragma bit  ADIF    @ 12.6

#pragma bit  CCP2IF  @ 13.0

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

#pragma bit  RX9D    @ 24.0
#pragma bit  OERR    @ 24.1
#pragma bit  FERR    @ 24.2
#pragma bit  CREN    @ 24.4
#pragma bit  SREN    @ 24.5
#pragma bit  RX9     @ 24.6
#pragma bit  SPEN    @ 24.7

#pragma bit  CCP2M0  @ 29.0
#pragma bit  CCP2M1  @ 29.1
#pragma bit  CCP2M2  @ 29.2
#pragma bit  CCP2M3  @ 29.3
#pragma bit  CCP2Y   @ 29.4
#pragma bit  CCP2X   @ 29.5

#pragma bit  ADON    @ 31.0
#pragma bit  GO      @ 31.2
#pragma bit  CHS0    @ 31.3
#pragma bit  CHS1    @ 31.4
#pragma bit  CHS2    @ 31.5
#pragma bit  ADCS0   @ 31.6
#pragma bit  ADCS1   @ 31.7

#pragma bit  TMR1IE  @ 0x8C.0
#pragma bit  TMR2IE  @ 0x8C.1
#pragma bit  CCP1IE  @ 0x8C.2
#pragma bit  SSPIE   @ 0x8C.3
#pragma bit  TXIE    @ 0x8C.4
#pragma bit  RCIE    @ 0x8C.5
#pragma bit  ADIE    @ 0x8C.6

#pragma bit  CCP2IE  @ 0x8D.0

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1

#pragma bit  BF      @ 0x94.0
#pragma bit  UA      @ 0x94.1
#pragma bit  RW_     @ 0x94.2
#pragma bit  S       @ 0x94.3
#pragma bit  P       @ 0x94.4
#pragma bit  DA_     @ 0x94.5
#pragma bit  CKE     @ 0x94.6
#pragma bit  SMP     @ 0x94.7

#pragma bit  TX9D    @ 0x98.0
#pragma bit  TRMT    @ 0x98.1
#pragma bit  BRGH    @ 0x98.2
#pragma bit  SYNC    @ 0x98.4
#pragma bit  TXEN    @ 0x98.5
#pragma bit  TX9     @ 0x98.6
#pragma bit  CSRC    @ 0x98.7

#pragma bit  PCFG0   @ 0x9F.0
#pragma bit  PCFG1   @ 0x9F.1
#pragma bit  PCFG2   @ 0x9F.2
