// HEADER FILE
#if !defined ICD_DEBUG  &&  !defined ICD2_DEBUG
 #pragma chip PIC16F747, core 14, code 4096, ram 32 : 0x1FF

#elif defined ICD2_DEBUG
 #pragma chip PIC16F747, core 14, code 0xF00, ram 32 : 0x1FF
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char ICD2R1 @ 0x70;
 char reservedICD2[11] @ 0x165;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging

#else  /* ICD_DEBUG */
 #pragma chip PIC16F747, core 14, code 0xF00, ram 32 : 0x1FF
 // NOTE: last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS FOR DEBUGGING
 #pragma char ICDR1 @ 0x70
 #pragma char ICDR2 @ 0x1EB
 #pragma char ICDR3 @ 0x1EC
 #pragma char ICDR4 @ 0x1ED
 #pragma char ICDR5 @ 0x1EE
 #pragma char ICDR6 @ 0x1EF

 #pragma stackLevels 7   // reserve one level for debugging

 #pragma cdata[0] = /*NOP*/ 0x0000  // startup instruction
 #pragma resetVector 1    // change to address 1

#endif

#pragma ramdef 0x110 : 0x11F
#pragma ramdef 0x190 : 0x19F
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_gen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0118

#pragma config_reg2 0x2008

#pragma wideConstData r

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

#pragma char PORTC   @ 0x07
#pragma char PORTD   @ 0x08
#pragma char PORTE   @ 0x09

#pragma char PIR1    @ 0x0C
#pragma char PIR2    @ 0x0D
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
#pragma char RCSTA   @ 0x18
#pragma char TXREG   @ 0x19
#pragma char RCREG   @ 0x1A
#pragma char CCPR2L  @ 0x1B
#pragma char CCPR2H  @ 0x1C
#pragma char CCP2CON @ 0x1D
#pragma char ADRESH  @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISC   @ 0x87
#pragma char TRISD   @ 0x88
#pragma char TRISE   @ 0x89

#pragma char PIE1    @ 0x8C
#pragma char PIE2    @ 0x8D
#pragma char PCON    @ 0x8E
#pragma char OSCCON  @ 0x8F
#pragma char OSCTUNE @ 0x90
#pragma char SSPCON2 @ 0x91
#pragma char PR2     @ 0x92
#pragma char SSPADD  @ 0x93
#pragma char SSPSTAT @ 0x94
#pragma char CCPR3L  @ 0x95
#pragma char CCPR3H  @ 0x96
#pragma char CCP3CON @ 0x97
#pragma char TXSTA   @ 0x98
#pragma char SPBRG   @ 0x99

#pragma char ADCON2  @ 0x9B
#pragma char CMCON   @ 0x9C
#pragma char CVRCON  @ 0x9D
#pragma char ADRESL  @ 0x9E
#pragma char ADCON1  @ 0x9F

#pragma char WDTCON  @ 0x105

#pragma char LVDCON  @ 0x109

#pragma char PMDATA  @ 0x10C
#pragma char PMADR   @ 0x10D
#pragma char PMDATH  @ 0x10E
#pragma char PMADRH  @ 0x10F

#pragma char PMCON1  @ 0x18C

#pragma bit  RE0     @ PORTE.0
#pragma bit  RE1     @ PORTE.1
#pragma bit  RE2     @ PORTE.2
#pragma bit  RE3     @ PORTE.3

#pragma bit  INT0IF  @ INTCON.1
#pragma bit  TMR0IF  @ INTCON.2
#pragma bit  INT0IE  @ INTCON.4
#pragma bit  TMR0IE  @ INTCON.5
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  CCP1IF  @ PIR1.2
#pragma bit  SSPIF   @ PIR1.3
#pragma bit  TXIF    @ PIR1.4
#pragma bit  RCIF    @ PIR1.5
#pragma bit  ADIF    @ PIR1.6
#pragma bit  PSPIF   @ PIR1.7

#pragma bit  CCP2IF  @ PIR2.0
#pragma bit  CCP3IF  @ PIR2.1
#pragma bit  BCLIF   @ PIR2.3
#pragma bit  LVDIF   @ PIR2.5
#pragma bit  CMIF    @ PIR2.6
#pragma bit  OSFIF   @ PIR2.7

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  T1RUN   @ T1CON.6

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

#pragma bit  RX9D    @ RCSTA.0
#pragma bit  OERR    @ RCSTA.1
#pragma bit  FERR    @ RCSTA.2
#pragma bit  ADDEN   @ RCSTA.3
#pragma bit  CREN    @ RCSTA.4
#pragma bit  SREN    @ RCSTA.5
#pragma bit  RX9     @ RCSTA.6
#pragma bit  SPEN    @ RCSTA.7

#pragma bit  CCP2M0  @ CCP2CON.0
#pragma bit  CCP2M1  @ CCP2CON.1
#pragma bit  CCP2M2  @ CCP2CON.2
#pragma bit  CCP2M3  @ CCP2CON.3
#pragma bit  CCP2Y   @ CCP2CON.4
#pragma bit  CCP2X   @ CCP2CON.5

#pragma bit  ADON    @ ADCON0.0
#pragma bit  CHS3    @ ADCON0.1
#pragma bit  GO      @ ADCON0.2
#pragma bit  CHS0    @ ADCON0.3
#pragma bit  CHS1    @ ADCON0.4
#pragma bit  CHS2    @ ADCON0.5
#pragma bit  ADCS0   @ ADCON0.6
#pragma bit  ADCS1   @ ADCON0.7

#pragma bit  PSPMODE @ TRISE.4
#pragma bit  IBOV    @ TRISE.5
#pragma bit  OBF     @ TRISE.6
#pragma bit  IBF     @ TRISE.7

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  CCP1IE  @ PIE1.2
#pragma bit  SSPIE   @ PIE1.3
#pragma bit  TXIE    @ PIE1.4
#pragma bit  RCIE    @ PIE1.5
#pragma bit  ADIE    @ PIE1.6
#pragma bit  PSPIE   @ PIE1.7

#pragma bit  CCP2IE  @ PIE2.0
#pragma bit  CCP3IE  @ PIE2.1
#pragma bit  BCLIE   @ PIE2.3
#pragma bit  LVDIE   @ PIE2.5
#pragma bit  CMIE    @ PIE2.6
#pragma bit  OSFIE   @ PIE2.7

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1
#pragma bit  SBOREN  @ PCON.2

#pragma bit  SCS0    @ OSCCON.0
#pragma bit  SCS1    @ OSCCON.1
#pragma bit  IOFS    @ OSCCON.2
#pragma bit  OSTS    @ OSCCON.3

#pragma bit  SEN     @ SSPCON2.0
#pragma bit  RSEN    @ SSPCON2.1
#pragma bit  PEN     @ SSPCON2.2
#pragma bit  RCEN    @ SSPCON2.3
#pragma bit  ACKEN   @ SSPCON2.4
#pragma bit  ACKDT   @ SSPCON2.5
#pragma bit  ACKSTAT @ SSPCON2.6
#pragma bit  GCEN    @ SSPCON2.7

#pragma bit  BF      @ SSPSTAT.0
#pragma bit  UA      @ SSPSTAT.1
#pragma bit  RW_     @ SSPSTAT.2
#pragma bit  S       @ SSPSTAT.3
#pragma bit  P       @ SSPSTAT.4
#pragma bit  DA_     @ SSPSTAT.5
#pragma bit  CKE     @ SSPSTAT.6
#pragma bit  SMP     @ SSPSTAT.7

#pragma bit  CCP3M0  @ CCP3CON.0
#pragma bit  CCP3M1  @ CCP3CON.1
#pragma bit  CCP3M2  @ CCP3CON.2
#pragma bit  CCP3M3  @ CCP3CON.3
#pragma bit  CCP3Y   @ CCP3CON.4
#pragma bit  CCP3X   @ CCP3CON.5

#pragma bit  TX9D    @ TXSTA.0
#pragma bit  TRMT    @ TXSTA.1
#pragma bit  BRGH    @ TXSTA.2
#pragma bit  SYNC    @ TXSTA.4
#pragma bit  TXEN    @ TXSTA.5
#pragma bit  TX9     @ TXSTA.6
#pragma bit  CSRC    @ TXSTA.7

#pragma bit  ACQT0   @ ADCON2.3
#pragma bit  ACQT1   @ ADCON2.4
#pragma bit  ACQT2   @ ADCON2.5

#pragma bit  CM0     @ CMCON.0
#pragma bit  CM1     @ CMCON.1
#pragma bit  CM2     @ CMCON.2
#pragma bit  CIS     @ CMCON.3
#pragma bit  C1INV   @ CMCON.4
#pragma bit  C2INV   @ CMCON.5
#pragma bit  C1OUT   @ CMCON.6
#pragma bit  C2OUT   @ CMCON.7

#pragma bit  CVR0    @ CVRCON.0
#pragma bit  CVR1    @ CVRCON.1
#pragma bit  CVR2    @ CVRCON.2
#pragma bit  CVR3    @ CVRCON.3
#pragma bit  CVRR    @ CVRCON.5
#pragma bit  CVROE   @ CVRCON.6
#pragma bit  CVREN   @ CVRCON.7

#pragma bit  VCFG0   @ ADCON1.4
#pragma bit  VCFG1   @ ADCON1.5
#pragma bit  ADCS2   @ ADCON1.6
#pragma bit  ADFM    @ ADCON1.7

#pragma bit  SWDTEN  @ WDTCON.0

#pragma bit  LVDEN   @ LVDCON.4
#pragma bit  IRVST   @ LVDCON.5

#pragma bit  RD      @ PMCON1.0
