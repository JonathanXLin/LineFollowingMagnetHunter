// HEADER FILE
#ifndef ICD2_DEBUG
 #pragma chip PIC16F785, core 14, code 2048, ram 32 : 0xBF /1 /3

#else
 #pragma chip PIC16F785, core 14, code 0x700, ram 32 : 0xBF /1 /3
 // last 256 locations are reserved for debugging
 // special 28-pin device for ICD 2 debugging

 //RESERVED RAM LOCATIONS
 char ICD2R1 @ 0x70;
 char reservedICD2[11] @ 0x65;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging

#endif

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_lgen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0222

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

#pragma char PIR1    @ 0x0C

#pragma char TMR1L   @ 0x0E
#pragma char TMR1H   @ 0x0F
#pragma char T1CON   @ 0x10
#pragma char TMR2    @ 0x11
#pragma char T2CON   @ 0x12
#pragma char CCPR1L  @ 0x13
#pragma char CCPR1H  @ 0x14
#pragma char CCP1CON @ 0x15

#pragma char WDTCON  @ 0x18

#pragma char ADRESH  @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISC   @ 0x87

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E
#pragma char OSCCON  @ 0x8F
#pragma char OSCTUNE @ 0x90
#pragma char ANSEL0  @ 0x91
#pragma char PR2     @ 0x92
#pragma char ANSEL1  @ 0x93

#pragma char WPUA    @ 0x95
#pragma char IOCA    @ 0x96

#pragma char REFCON  @ 0x98
#pragma char VRCON   @ 0x99
#pragma char EEDATA  @ 0x9A
#pragma char EEADR   @ 0x9B
#pragma char EECON1  @ 0x9C
#pragma char EECON2  @ 0x9D
#pragma char ADRESL  @ 0x9E
#pragma char ADCON1  @ 0x9F

#pragma char PWMCON1 @ 0x110
#pragma char PWMCON0 @ 0x111
#pragma char PWMCLK  @ 0x112
#pragma char PWMPH1  @ 0x113
#pragma char PWMPH2  @ 0x114

#pragma char CM1CON0 @ 0x119
#pragma char CM2CON0 @ 0x11A
#pragma char CM2CON1 @ 0x11B
#pragma char OPA1CON @ 0x11C
#pragma char OPA2CON @ 0x11D

#pragma bit  RAIF    @ INTCON.0
#pragma bit  RAIE    @ INTCON.3
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  OSFIF   @ PIR1.2
#pragma bit  C1IF    @ PIR1.3
#pragma bit  C2IF    @ PIR1.4
#pragma bit  CCP1IF  @ PIR1.5
#pragma bit  ADIF    @ PIR1.6
#pragma bit  EEIF    @ PIR1.7

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  TMR1GE  @ T1CON.6
#pragma bit  T1GINV  @ T1CON.7

#pragma bit  TMR2ON  @ T2CON.2

#pragma bit  CCP1M0  @ CCP1CON.0
#pragma bit  CCP1M1  @ CCP1CON.1
#pragma bit  CCP1M2  @ CCP1CON.2
#pragma bit  CCP1M3  @ CCP1CON.3
#pragma bit  DC1B0   @ CCP1CON.4
#pragma bit  DC1B1   @ CCP1CON.5

#pragma bit  SWDTEN  @ WDTCON.0

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  CHS3    @ ADCON0.5
#pragma bit  VCFG    @ ADCON0.6
#pragma bit  ADFM    @ ADCON0.7

#pragma bit  RAPU_   @ OPTION_REG.7

#pragma bit  TRISA0  @ TRISA.0
#pragma bit  TRISA1  @ TRISA.1
#pragma bit  TRISA2  @ TRISA.2
#pragma bit  TRISA3  @ TRISA.3
#pragma bit  TRISA4  @ TRISA.4
#pragma bit  TRISA5  @ TRISA.5

#pragma bit  TRISB4  @ TRISB.4
#pragma bit  TRISB5  @ TRISB.5
#pragma bit  TRISB6  @ TRISB.6
#pragma bit  TRISB7  @ TRISB.7

#pragma bit  TRISC0  @ TRISC.0
#pragma bit  TRISC1  @ TRISC.1
#pragma bit  TRISC2  @ TRISC.2
#pragma bit  TRISC3  @ TRISC.3
#pragma bit  TRISC4  @ TRISC.4
#pragma bit  TRISC5  @ TRISC.5
#pragma bit  TRISC6  @ TRISC.6
#pragma bit  TRISC7  @ TRISC.7

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  OSFIE   @ PIE1.2
#pragma bit  C1IE    @ PIE1.3
#pragma bit  C2IE    @ PIE1.4
#pragma bit  CCP1IE  @ PIE1.5
#pragma bit  ADIE    @ PIE1.6
#pragma bit  EEIE    @ PIE1.7

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1
#pragma bit  SBOREN  @ PCON.4

#pragma bit  SCS     @ OSCCON.0
#pragma bit  LTS     @ OSCCON.1
#pragma bit  HTS     @ OSCCON.2
#pragma bit  OSTS    @ OSCCON.3

#pragma bit  CVROE   @ REFCON.1
#pragma bit  VROE    @ REFCON.2
#pragma bit  VREN    @ REFCON.3
#pragma bit  VRBB    @ REFCON.4
#pragma bit  BGST    @ REFCON.5

#pragma bit  VR0     @ VRCON.0
#pragma bit  VR1     @ VRCON.1
#pragma bit  VR2     @ VRCON.2
#pragma bit  VR3     @ VRCON.3
#pragma bit  VRR     @ VRCON.5
#pragma bit  C2VREN  @ VRCON.6
#pragma bit  C1VREN  @ VRCON.7

#pragma bit  RD      @ EECON1.0
#pragma bit  WR      @ EECON1.1
#pragma bit  WREN    @ EECON1.2
#pragma bit  WRERR   @ EECON1.3

#pragma bit  ADCS0   @ ADCON1.4
#pragma bit  ADCS1   @ ADCON1.5
#pragma bit  ADCS2   @ ADCON1.6

#pragma bit  COMOD0  @ PWMCON1.5
#pragma bit  COMOD1  @ PWMCON1.6
#pragma bit  OVRLP   @ PWMCON1.7

#pragma bit  PASEN   @ PWMCON0.6
#pragma bit  PRSEN   @ PWMCON0.7

#pragma bit  PWMASE  @ PWMCLK.7

#pragma bit  C1R     @ CM1CON0.2
#pragma bit  C1SP    @ CM1CON0.3
#pragma bit  C1POL   @ CM1CON0.4
#pragma bit  C1OE    @ CM1CON0.5
#pragma bit  C1OUT   @ CM1CON0.6
#pragma bit  C1ON    @ CM1CON0.7

#pragma bit  C2R     @ CM2CON0.2
#pragma bit  C2SP    @ CM2CON0.3
#pragma bit  C2POL   @ CM2CON0.4
#pragma bit  C2OE    @ CM2CON0.5
#pragma bit  C2OUT   @ CM2CON0.6
#pragma bit  C2ON    @ CM2CON0.7

#pragma bit  C2SYNC  @ CM2CON1.0
#pragma bit  T1GSS   @ CM2CON1.1
#pragma bit  MC2OUT  @ CM2CON1.6
#pragma bit  MC1OUT  @ CM2CON1.7
