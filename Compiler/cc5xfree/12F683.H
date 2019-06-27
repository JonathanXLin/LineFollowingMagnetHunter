// HEADER FILE
#ifndef ICD2_DEBUG
 #pragma chip PIC12F683, core 14, code 2048, ram 32 : 0xBF

#else
 #pragma chip PIC12F683, core 14, code 0x700, ram 32 : 0xBF
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char ICD2R1 @ 0x70;
 char reservedICD2[11] @ 0x65;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging

#endif

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_com_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0222

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

#pragma char GPIO    @ 0x05

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
#pragma char CMCON0  @ 0x19
#pragma char CMCON1  @ 0x1A

#pragma char ADRESH  @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISIO  @ 0x85

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E
#pragma char OSCCON  @ 0x8F
#pragma char OSCTUNE @ 0x90

#pragma char PR2     @ 0x92

#pragma char WPU     @ 0x95
#pragma char IOC     @ 0x96

#pragma char VRCON   @ 0x99
#pragma char EEDAT   @ 0x9A
#pragma char EEADR   @ 0x9B
#pragma char EECON1  @ 0x9C
#pragma char EECON2  @ 0x9D
#pragma char ADRESL  @ 0x9E
#pragma char ANSEL   @ 0x9F

#pragma bit  GPIF    @ INTCON.0
#pragma bit  GPIE    @ INTCON.3
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  OSFIF   @ PIR1.2
#pragma bit  CMIF    @ PIR1.3
#pragma bit  CCP1IF  @ PIR1.5
#pragma bit  ADIF    @ PIR1.6
#pragma bit  EEIF    @ PIR1.7

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  T1GE    @ T1CON.6
#pragma bit  T1GINV  @ T1CON.7

#pragma bit  TMR2ON  @ T2CON.2

#pragma bit  CCP1M0  @ CCP1CON.0
#pragma bit  CCP1M1  @ CCP1CON.1
#pragma bit  CCP1M2  @ CCP1CON.2
#pragma bit  CCP1M3  @ CCP1CON.3
#pragma bit  DC1B0   @ CCP1CON.4
#pragma bit  DC1B1   @ CCP1CON.5

#pragma bit  SWDTEN  @ WDTCON.0

#pragma bit  CM0     @ CMCON0.0
#pragma bit  CM1     @ CMCON0.1
#pragma bit  CM2     @ CMCON0.2
#pragma bit  CIS     @ CMCON0.3
#pragma bit  CINV    @ CMCON0.4
#pragma bit  COUT    @ CMCON0.6

#pragma bit  CMSYNC  @ CMCON1.0
#pragma bit  T1GSS   @ CMCON1.1

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  VCFG    @ ADCON0.6
#pragma bit  ADFM    @ ADCON0.7

#pragma bit  TRISIO0 @ TRISIO.0
#pragma bit  TRISIO1 @ TRISIO.1
#pragma bit  TRISIO2 @ TRISIO.2
#pragma bit  TRISIO3 @ TRISIO.3
#pragma bit  TRISIO4 @ TRISIO.4
#pragma bit  TRISIO5 @ TRISIO.5

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TMR2IE  @ PIE1.1
#pragma bit  OSFIE   @ PIE1.2
#pragma bit  CMIE    @ PIE1.3
#pragma bit  CCP1IE  @ PIE1.5
#pragma bit  ADIE    @ PIE1.6
#pragma bit  EEIE    @ PIE1.7

#pragma bit  BOD_    @ PCON.0
#pragma bit  POR_    @ PCON.1
#pragma bit  SBODEN  @ PCON.4
#pragma bit  ULPWUE  @ PCON.5

#pragma bit  SCS     @ OSCCON.0
#pragma bit  LTS     @ OSCCON.1
#pragma bit  HTS     @ OSCCON.2
#pragma bit  OSTS    @ OSCCON.3

#pragma bit  WPU0    @ WPU.0
#pragma bit  WPU1    @ WPU.1
#pragma bit  WPU2    @ WPU.2
#pragma bit  WPU4    @ WPU.4
#pragma bit  WPU5    @ WPU.5

#pragma bit  VR0     @ VRCON.0
#pragma bit  VR1     @ VRCON.1
#pragma bit  VR2     @ VRCON.2
#pragma bit  VR3     @ VRCON.3
#pragma bit  VRR     @ VRCON.5
#pragma bit  VREN    @ VRCON.7

#pragma bit  RD      @ EECON1.0
#pragma bit  WR      @ EECON1.1
#pragma bit  WREN    @ EECON1.2
#pragma bit  WRERR   @ EECON1.3

#pragma bit  ANS0    @ ANSEL.0
#pragma bit  ANS1    @ ANSEL.1
#pragma bit  ANS2    @ ANSEL.2
#pragma bit  ANS3    @ ANSEL.3
#pragma bit  ADCS0   @ ANSEL.4
#pragma bit  ADCS1   @ ANSEL.5
#pragma bit  ADCS2   @ ANSEL.6
