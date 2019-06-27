// HEADER FILE
#pragma chip PIC16F72, core 14, code 2048, ram 32 : 0xFF /0 /3
#pragma ramdef  0x40 : 0x7F mapped_into_all_banks

#define INT_lgen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x1111

#pragma wideConstData p

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR;
  char OPTION;
  char PCLATH, INTCON;
  bit PS0, PS1, PS2, PSA, T0SE, T0CS, INTEDG, RBPU_;
  bit Carry, DC, Zero_, PD, TO, RP0, RP1, IRP;
  bit RBIF, INTF, T0IF, RBIE, INTE, T0IE, GIE;
  bit PA0, PA1;  // PCLATH
*/

#pragma char PORTC   @ 0x07

#pragma char PIR1    @ 0x0C

#pragma char TMR1L   @ 0x0E
#pragma char TMR1H   @ 0x0F
#pragma char T1CON   @ 0x10
#pragma char TMR2    @ 0x11
#pragma char T2CON   @ 0x12
#pragma char SSPBUF  @ 0x13
#pragma char SSPCON  @ 0x14
#pragma char CCPR1L  @ 0x15
#pragma char CCPR1H  @ 0x16
#pragma char CCP1CON @ 0x17

#pragma char ADRES   @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISC   @ 0x87

#pragma char PIE1    @ 0x8C
#pragma char PCON    @ 0x8E

#pragma char PR2     @ 0x92
#pragma char SSPADD  @ 0x93
#pragma char SSPSTAT @ 0x94

#pragma char ADCON1  @ 0x9F

#pragma char PMDATL  @ 0x10C
#pragma char PMADRL  @ 0x10D
#pragma char PMDATH  @ 0x10E
#pragma char PMADRH  @ 0x10F

#pragma char PMCON1  @ 0x18C



#pragma bit  TMR0IF  @ INTCON.2
#pragma bit  TMR0IE  @ INTCON.5
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  CCP1IF  @ PIR1.2
#pragma bit  SSPIF   @ PIR1.3
#pragma bit  ADIF    @ PIR1.6

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5

#pragma bit  T2CKPS0 @ T2CON.0
#pragma bit  T2CKPS1 @ T2CON.1
#pragma bit  TMR2ON  @ T2CON.2
#pragma bit  TOUTPS0 @ T2CON.3
#pragma bit  TOUTPS1 @ T2CON.4
#pragma bit  TOUTPS2 @ T2CON.5
#pragma bit  TOUTPS3 @ T2CON.6

#pragma bit  SSPM0   @ SSPCON.0
#pragma bit  SSPM1   @ SSPCON.1
#pragma bit  SSPM2   @ SSPCON.2
#pragma bit  SSPM3   @ SSPCON.3
#pragma bit  CKP     @ SSPCON.4
#pragma bit  SSPEN   @ SSPCON.5
#pragma bit  SSPOV   @ SSPCON.6
#pragma bit  WCOL    @ SSPCON.7

#pragma bit  CCP1M0  @ CCP1CON.0
#pragma bit  CCP1M1  @ CCP1CON.1
#pragma bit  CCP1M2  @ CCP1CON.2
#pragma bit  CCP1M3  @ CCP1CON.3
#pragma bit  CCP1Y   @ CCP1CON.4
#pragma bit  CCP1X   @ CCP1CON.5

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.2
#pragma bit  CHS0    @ ADCON0.3
#pragma bit  CHS1    @ ADCON0.4
#pragma bit  CHS2    @ ADCON0.5
#pragma bit  ADCS0   @ ADCON0.6
#pragma bit  ADCS1   @ ADCON0.7

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  CCP1IE  @ PIE1.2
#pragma bit  SSPIE   @ PIE1.3
#pragma bit  ADIE    @ PIE1.6

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  BF      @ SSPSTAT.0
#pragma bit  UA      @ SSPSTAT.1
#pragma bit  RW_     @ SSPSTAT.2
#pragma bit  S       @ SSPSTAT.3
#pragma bit  P       @ SSPSTAT.4
#pragma bit  DA_     @ SSPSTAT.5
#pragma bit  CKE     @ SSPSTAT.6
#pragma bit  SMP     @ SSPSTAT.7

#pragma bit  PCFG0   @ ADCON1.0
#pragma bit  PCFG1   @ ADCON1.1
#pragma bit  PCFG2   @ ADCON1.2

#pragma bit  RD      @ PMCON1.0
