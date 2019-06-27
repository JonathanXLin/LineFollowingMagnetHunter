// HEADER FILE
#pragma chip PIC16C717, core 14, code 2048, ram 32 : 0x17F
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_lgen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x1222

#pragma wideConstData p

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

#pragma char ADRESH  @ 30
#pragma char ADCON0  @ 31

#pragma char PIE1    @ 0x8C
#pragma char PIE2    @ 0x8D
#pragma char PCON    @ 0x8E

#pragma char SSPCON2 @ 0x91
#pragma char PR2     @ 0x92
#pragma char SSPADD  @ 0x93
#pragma char SSPSTAT @ 0x94
#pragma char WPUB    @ 0x95
#pragma char IOCB    @ 0x96
#pragma char P1DEL   @ 0x97

#pragma char REFCON  @ 0x9B
#pragma char LVDCON  @ 0x9C
#pragma char ANSEL   @ 0x9D
#pragma char ADRESL  @ 0x9E
#pragma char ADCON1  @ 0x9F

#pragma char PMDATL  @ 0x10C
#pragma char PMADRL  @ 0x10D
#pragma char PMDATH  @ 0x10E
#pragma char PMADRH  @ 0x10F

#pragma char PMCON1  @ 0x18C


#pragma bit  RA0     @ 5.0
#pragma bit  RA1     @ 5.1
#pragma bit  RA2     @ 5.2
#pragma bit  RA3     @ 5.3
#pragma bit  RA4     @ 5.4
#pragma bit  RA5     @ 5.5
#pragma bit  RA6     @ 5.6
#pragma bit  RA7     @ 5.7

#pragma bit  RB0     @ 6.0
#pragma bit  RB1     @ 6.1
#pragma bit  RB2     @ 6.2
#pragma bit  RB3     @ 6.3
#pragma bit  RB4     @ 6.4
#pragma bit  RB5     @ 6.5
#pragma bit  RB6     @ 6.6
#pragma bit  RB7     @ 6.7

#pragma bit  PEIE    @ 11.6  mapped_into_all_banks

#pragma bit  TMR1IF  @ 12.0
#pragma bit  TMR2IF  @ 12.1
#pragma bit  CCP1IF  @ 12.2
#pragma bit  SSPIF   @ 12.3
#pragma bit  ADIF    @ 12.6

#pragma bit  BCLIF   @ 13.3
#pragma bit  LVDIF   @ 13.7

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
#pragma bit  DC1B0   @ 23.4
#pragma bit  DC1B1   @ 23.5
#pragma bit  PWM1M0  @ 23.6
#pragma bit  PWM1M1  @ 23.7

#pragma bit  ADON    @ 31.0
#pragma bit  CHS3    @ 31.1
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
#pragma bit  ADIE    @ 0x8C.6

#pragma bit  BCLIE   @ 0x8D.3
#pragma bit  LVDIE   @ 0x8D.7

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1
#pragma bit  OSCF    @ 0x8E.3

#pragma bit  SEN     @ 0x91.0
#pragma bit  RSEN    @ 0x91.1
#pragma bit  PEN     @ 0x91.2
#pragma bit  RCEN    @ 0x91.3
#pragma bit  ACKEN   @ 0x91.4
#pragma bit  ACKDT   @ 0x91.5
#pragma bit  ACKSTAT @ 0x91.6
#pragma bit  GCEN    @ 0x91.7

#pragma bit  BF      @ 0x94.0
#pragma bit  UA      @ 0x94.1
#pragma bit  RW_     @ 0x94.2
#pragma bit  S       @ 0x94.3
#pragma bit  P       @ 0x94.4
#pragma bit  DA_     @ 0x94.5
#pragma bit  CKE     @ 0x94.6
#pragma bit  SMP     @ 0x94.7

#pragma bit  VRLOEN  @ 0x9B.4
#pragma bit  VRHOEN  @ 0x9B.5
#pragma bit  VRLEN   @ 0x9B.6
#pragma bit  VRHEN   @ 0x9B.7

#pragma bit  LVV0    @ 0x9C.0
#pragma bit  LVV1    @ 0x9C.1
#pragma bit  LVV2    @ 0x9C.2
#pragma bit  LVV3    @ 0x9C.3
#pragma bit  LVDEN   @ 0x9C.4
#pragma bit  BGST    @ 0x9C.5

#pragma bit  VCFG0   @ 0x9F.4
#pragma bit  VCFG1   @ 0x9F.5
#pragma bit  VCFG2   @ 0x9F.6
#pragma bit  ADFM    @ 0x9F.7

#pragma bit  RD      @ 0x18C.0
