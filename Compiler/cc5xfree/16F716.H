// HEADER FILE
#if !defined ICD2_DEBUG
 #pragma chip PIC16F716, core 14, code 2048, ram 32 : 0xBF

#else /* ICD2_DEBUG */
 #pragma chip PIC16F716, core 14, code 0x700, ram 32 : 0xBF
 // last 256 locations are reserved for debugging

 //RESERVED RAM LOCATIONS
 char ICD2R1 @ 0x70;
 char reservedICD2[11] @ 0x65;  // reserved RAM for ICD2

 #pragma stackLevels 7   // reserve one level for debugging

#endif

#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_com_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

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

#pragma char PIR1    @ 0x0C

#pragma char TMR1L   @ 0x0E
#pragma char TMR1H   @ 0x0F
#pragma char T1CON   @ 0x10
#pragma char TMR2    @ 0x11
#pragma char T2CON   @ 0x12

#pragma char CCPR1L  @ 0x15
#pragma char CCPR1H  @ 0x16
#pragma char CCP1CON @ 0x17
#pragma char PWM1CON @ 0x18
#pragma char ECCPAS  @ 0x19

#pragma char ADRES   @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E

#pragma char PR2     @ 0x92

#pragma char ADCON1  @ 0x9F


#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  CCP1IF  @ PIR1.2
#pragma bit  ADIF    @ PIR1.6

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5

#pragma bit  TMR2ON  @ T2CON.2

#pragma bit  CCP1M0  @ CCP1CON.0
#pragma bit  CCP1M1  @ CCP1CON.1
#pragma bit  CCP1M2  @ CCP1CON.2
#pragma bit  CCP1M3  @ CCP1CON.3
#pragma bit  DC1B0   @ CCP1CON.4
#pragma bit  DC1B1   @ CCP1CON.5
#pragma bit  P1M0    @ CCP1CON.6
#pragma bit  P1M1    @ CCP1CON.7

#pragma bit  PRSEN   @ PWM1CON.7

#pragma bit  PSSBD0  @ ECCPAS.0
#pragma bit  PSSBD1  @ ECCPAS.1
#pragma bit  PSSAC0  @ ECCPAS.2
#pragma bit  PSSAC1  @ ECCPAS.3
#pragma bit  ECCPAS0 @ ECCPAS.4
#pragma bit  ECCPAS2 @ ECCPAS.6
#pragma bit  ECCPASE @ ECCPAS.7

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
#pragma bit  ADIE    @ PIE1.6

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  PCFG0   @ ADCON1.0
#pragma bit  PCFG1   @ ADCON1.1
#pragma bit  PCFG2   @ ADCON1.2
