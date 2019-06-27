// HEADER FILE
#ifndef ICD2_DEBUG
 #pragma chip PIC12F675, core 14, code 1024, ram 32 : 0x5F mapped_into_bank_1

#else
 #pragma chip PIC12F675, core 14, code 0x300, ram 32 : 0x5F mapped_into_bank_1
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char reservedICD2[12] @ 0x54;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging

#endif

#define INT_min_style

#pragma config_def 0x1222

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
#pragma char CMCON   @ 0x19
#pragma char ADRESH  @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISIO  @ 0x85
#pragma char PIE1    @ 0x8C
#pragma char PCON    @ 0x8E
#pragma char OSCCAL  @ 0x90
#pragma char WPU     @ 0x95
#pragma char IOCB    @ 0x96
#pragma char VRCON   @ 0x99
#pragma char EEDATA  @ 0x9A
#pragma char EEADR   @ 0x9B
#pragma char EECON1  @ 0x9C
#pragma char EECON2  @ 0x9D
#pragma char ADRESL  @ 0x9E
#pragma char ANSEL   @ 0x9F


#pragma bit  GPIO0   @ GPIO.0
#pragma bit  GPIO1   @ GPIO.1
#pragma bit  GPIO2   @ GPIO.2
#pragma bit  GPIO3   @ GPIO.3
#pragma bit  GPIO4   @ GPIO.4
#pragma bit  GPIO5   @ GPIO.5

#pragma bit  GPIF    @ INTCON.0
#pragma bit  GPIE    @ INTCON.3
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  CMIF    @ PIR1.3
#pragma bit  ADIF    @ PIR1.6
#pragma bit  EEIF    @ PIR1.7

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5
#pragma bit  TMR1GE  @ T1CON.6

#pragma bit  CM0     @ CMCON.0
#pragma bit  CM1     @ CMCON.1
#pragma bit  CM2     @ CMCON.2
#pragma bit  CIS     @ CMCON.3
#pragma bit  CINV    @ CMCON.4
#pragma bit  COUT    @ CMCON.6

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  VCFG    @ ADCON0.6
#pragma bit  ADFM    @ ADCON0.7

#pragma bit  TRIS0   @ TRISIO.0
#pragma bit  TRIS1   @ TRISIO.1
#pragma bit  TRIS2   @ TRISIO.2
#pragma bit  TRIS3   @ TRISIO.3
#pragma bit  TRIS4   @ TRISIO.4
#pragma bit  TRIS5   @ TRISIO.5

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  CMIE    @ PIE1.3
#pragma bit  ADIE    @ PIE1.6
#pragma bit  EEIE    @ PIE1.7

#pragma bit  BOD_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  CAL0    @ OSCCAL.2
#pragma bit  CAL1    @ OSCCAL.3
#pragma bit  CAL2    @ OSCCAL.4
#pragma bit  CAL3    @ OSCCAL.5
#pragma bit  CAL4    @ OSCCAL.6
#pragma bit  CAL5    @ OSCCAL.7

#pragma bit  WPU0    @ WPU.0
#pragma bit  WPU1    @ WPU.1
#pragma bit  WPU2    @ WPU.2
#pragma bit  WPU4    @ WPU.4
#pragma bit  WPU5    @ WPU.5

#pragma bit  IOCB0   @ IOCB.0
#pragma bit  IOCB1   @ IOCB.1
#pragma bit  IOCB2   @ IOCB.2
#pragma bit  IOCB3   @ IOCB.3
#pragma bit  IOCB4   @ IOCB.4
#pragma bit  IOCB5   @ IOCB.5

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

