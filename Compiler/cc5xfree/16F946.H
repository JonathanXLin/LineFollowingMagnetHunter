// HEADER FILE
#ifndef ICD2_DEBUG
 #pragma chip PIC16F946, core 14, code 8192, ram 32 : 0x1FF

#else /* ICD2_DEBUG */
 #pragma chip PIC16F946, core 14, code 0x1F00, ram 32 : 0x1FF
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char ICD2R1 @ 0x70;
 char reservedICD2[11] @ 0x165;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging

#endif

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_gen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0222

#pragma wideConstData

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
#pragma char ANSEL   @ 0x91
#pragma char PR2     @ 0x92
#pragma char SSPADD  @ 0x93
#pragma char SSPSTAT @ 0x94
#pragma char WPUB    @ 0x95
#pragma char IOCB    @ 0x96
#pragma char CMCON1  @ 0x97
#pragma char TXSTA   @ 0x98
#pragma char SPBRG   @ 0x99

#pragma char CMCON0  @ 0x9C
#pragma char VRCON   @ 0x9D
#pragma char ADRESL  @ 0x9E
#pragma char ADCON1  @ 0x9F

#pragma char WDTCON  @ 0x105

#pragma char LCDCON  @ 0x107
#pragma char LCDPS   @ 0x108
#pragma char LVDCON  @ 0x109

#pragma char EEDATA  @ 0x10C
#pragma char EEDATL  @ 0x10C
#pragma char EEADR   @ 0x10D
#pragma char EEADRL  @ 0x10D
#pragma char EEDATH  @ 0x10E
#pragma char EEADRH  @ 0x10F
#pragma char LCDDATA0 @ 0x110
#pragma char LCDDATA1 @ 0x111
#pragma char LCDDATA2 @ 0x112
#pragma char LCDDATA3 @ 0x113
#pragma char LCDDATA4 @ 0x114
#pragma char LCDDATA5 @ 0x115
#pragma char LCDDATA6 @ 0x116
#pragma char LCDDATA7 @ 0x117
#pragma char LCDDATA8 @ 0x118
#pragma char LCDDATA9 @ 0x119
#pragma char LCDDATA10 @ 0x11A
#pragma char LCDDATA11 @ 0x11B
#pragma char LCDSE0  @ 0x11C
#pragma char LCDSE1  @ 0x11D
#pragma char LCDSE2  @ 0x11E

#pragma char TRISF   @ 0x185

#pragma char TRISG   @ 0x187
#pragma char PORTF   @ 0x188
#pragma char PORTG   @ 0x189

#pragma char EECON1  @ 0x18C
#pragma char EECON2  @ 0x18D

#pragma char LCDDATA12 @ 0x190
#pragma char LCDDATA13 @ 0x191
#pragma char LCDDATA14 @ 0x192
#pragma char LCDDATA15 @ 0x193
#pragma char LCDDATA16 @ 0x194
#pragma char LCDDATA17 @ 0x195
#pragma char LCDDATA18 @ 0x196
#pragma char LCDDATA19 @ 0x197
#pragma char LCDDATA20 @ 0x198
#pragma char LCDDATA21 @ 0x199
#pragma char LCDDATA22 @ 0x19A
#pragma char LCDDATA23 @ 0x19B
#pragma char LCDSE3  @ 0x19C
#pragma char LCDSE4  @ 0x19D
#pragma char LCDSE5  @ 0x19E

#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  CCP1IF  @ PIR1.2
#pragma bit  SSPIF   @ PIR1.3
#pragma bit  TXIF    @ PIR1.4
#pragma bit  RCIF    @ PIR1.5
#pragma bit  ADIF    @ PIR1.6
#pragma bit  EEIF    @ PIR1.7

#pragma bit  CCP2IF  @ PIR2.0
#pragma bit  LVDIF   @ PIR2.2
#pragma bit  LCDIF   @ PIR2.4
#pragma bit  C1IF    @ PIR2.5
#pragma bit  C2IF    @ PIR2.6
#pragma bit  OSFIF   @ PIR2.7

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  T1GE    @ T1CON.6
#pragma bit  T1GINV  @ T1CON.7

#pragma bit  TMR2ON  @ T2CON.2

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
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  VCFG0   @ ADCON0.5
#pragma bit  VCFG1   @ ADCON0.6
#pragma bit  ADFM    @ ADCON0.7

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  CCP1IE  @ PIE1.2
#pragma bit  SSPIE   @ PIE1.3
#pragma bit  TXIE    @ PIE1.4
#pragma bit  RCIE    @ PIE1.5
#pragma bit  ADIE    @ PIE1.6
#pragma bit  EEIE    @ PIE1.7

#pragma bit  CCP2IE  @ PIE2.0
#pragma bit  LVDIE   @ PIE2.2
#pragma bit  LCDIE   @ PIE2.4
#pragma bit  C1IE    @ PIE2.5
#pragma bit  C2IE    @ PIE2.6
#pragma bit  OSFIE   @ PIE2.7

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1
#pragma bit  SBOREN  @ PCON.4

#pragma bit  SCS     @ OSCCON.0
#pragma bit  LTS     @ OSCCON.1
#pragma bit  HTS     @ OSCCON.2
#pragma bit  OSTS    @ OSCCON.3

#pragma bit  BF      @ SSPSTAT.0
#pragma bit  UA      @ SSPSTAT.1
#pragma bit  RW_     @ SSPSTAT.2
#pragma bit  S       @ SSPSTAT.3
#pragma bit  P       @ SSPSTAT.4
#pragma bit  DA_     @ SSPSTAT.5
#pragma bit  CKE     @ SSPSTAT.6
#pragma bit  SMP     @ SSPSTAT.7

#pragma bit  C2SYNC  @ CMCON1.0
#pragma bit  T1GSS   @ CMCON1.1

#pragma bit  TX9D    @ TXSTA.0
#pragma bit  TRMT    @ TXSTA.1
#pragma bit  BRGH    @ TXSTA.2
#pragma bit  SYNC    @ TXSTA.4
#pragma bit  TXEN    @ TXSTA.5
#pragma bit  TX9     @ TXSTA.6
#pragma bit  CSRC    @ TXSTA.7

#pragma bit  CM0     @ CMCON0.0
#pragma bit  CM1     @ CMCON0.1
#pragma bit  CM2     @ CMCON0.2
#pragma bit  CIS     @ CMCON0.3
#pragma bit  C1INV   @ CMCON0.4
#pragma bit  C2INV   @ CMCON0.5
#pragma bit  C1OUT   @ CMCON0.6
#pragma bit  C2OUT   @ CMCON0.7

#pragma bit  VR0     @ VRCON.0
#pragma bit  VR1     @ VRCON.1
#pragma bit  VR2     @ VRCON.2
#pragma bit  VR3     @ VRCON.3
#pragma bit  VRR     @ VRCON.5
#pragma bit  VREN    @ VRCON.7

#pragma bit  ADCS0   @ ADCON1.4
#pragma bit  ADCS1   @ ADCON1.5
#pragma bit  ADCS2   @ ADCON1.6

#pragma bit  SWDTEN  @ WDTCON.0

#pragma bit  LMUX0   @ LCDCON.0
#pragma bit  LMUX1   @ LCDCON.1
#pragma bit  CS0     @ LCDCON.2
#pragma bit  CS1     @ LCDCON.3
#pragma bit  VLCDEN  @ LCDCON.4
#pragma bit  WERR    @ LCDCON.5
#pragma bit  SLPEN   @ LCDCON.6
#pragma bit  LCDEN   @ LCDCON.7

#pragma bit  LP0     @ LCDPS.0
#pragma bit  LP1     @ LCDPS.1
#pragma bit  LP2     @ LCDPS.2
#pragma bit  LP3     @ LCDPS.3
#pragma bit  WA      @ LCDPS.4
#pragma bit  LCDA    @ LCDPS.5
#pragma bit  BIASMD  @ LCDPS.6
#pragma bit  WFT     @ LCDPS.7

#pragma bit  LVDEN   @ LVDCON.4
#pragma bit  IRVST   @ LVDCON.5

#pragma bit  RD      @ EECON1.0
#pragma bit  WR      @ EECON1.1
#pragma bit  WREN    @ EECON1.2
#pragma bit  WRERR   @ EECON1.3
#pragma bit  EEPGD   @ EECON1.7
