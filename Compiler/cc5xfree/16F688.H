// HEADER FILE
#if !defined ICD2_DEBUG
 #pragma chip PIC16F688, core 14, code 4096, ram 32 : 0x17F

#else /* ICD2_DEBUG */
 #pragma chip PIC16F688, core 14, code 0xF00, ram 32 : 0x17F
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
  char INDF, TMR0, PCL, STATUS, FSR, PORTA;
  char OPTION, TRISA;
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
#pragma char BAUDCTL @ 0x11
#pragma char SPBRGH  @ 0x12
#pragma char SPBRG   @ 0x13
#pragma char RCREG   @ 0x14
#pragma char TXREG   @ 0x15
#pragma char TXSTA   @ 0x16
#pragma char RCSTA   @ 0x17
#pragma char WDTCON  @ 0x18
#pragma char CMCON0  @ 0x19
#pragma char CMCON1  @ 0x1A

#pragma char ADRESH  @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISC   @ 0x87

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E
#pragma char OSCCON  @ 0x8F
#pragma char OSCTUNE @ 0x90
#pragma char ANSEL   @ 0x91

#pragma char WPUA    @ 0x95
#pragma char IOCA    @ 0x96
#pragma char EEDATH  @ 0x97
#pragma char EEADRH  @ 0x98
#pragma char VRCON   @ 0x99
#pragma char EEDATA  @ 0x9A
#pragma char EEADR   @ 0x9B
#pragma char EECON1  @ 0x9C
#pragma char EECON2  @ 0x9D
#pragma char ADRESL  @ 0x9E
#pragma char ADCON1  @ 0x9F

#pragma bit  RAIF    @ INTCON.0
#pragma bit  RAIE    @ INTCON.3
#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TXIF    @ PIR1.1
#pragma bit  OSFIF   @ PIR1.2
#pragma bit  C1IF    @ PIR1.3
#pragma bit  C2IF    @ PIR1.4
#pragma bit  RCIF    @ PIR1.5
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

#pragma bit  ABDEN   @ BAUDCTL.0
#pragma bit  WUE     @ BAUDCTL.1
#pragma bit  BRG16   @ BAUDCTL.3
#pragma bit  SCKP    @ BAUDCTL.4
#pragma bit  RCIDL   @ BAUDCTL.6
#pragma bit  ABDOVF  @ BAUDCTL.7

#pragma bit  TX9D    @ TXSTA.0
#pragma bit  TRMT    @ TXSTA.1
#pragma bit  BRGH    @ TXSTA.2
#pragma bit  SENDB   @ TXSTA.3
#pragma bit  SYNC    @ TXSTA.4
#pragma bit  TXEN    @ TXSTA.5
#pragma bit  TX9     @ TXSTA.6
#pragma bit  CSRC    @ TXSTA.7

#pragma bit  RX9D    @ RCSTA.0
#pragma bit  OERR    @ RCSTA.1
#pragma bit  FERR    @ RCSTA.2
#pragma bit  ADDEN   @ RCSTA.3
#pragma bit  CREN    @ RCSTA.4
#pragma bit  SREN    @ RCSTA.5
#pragma bit  RX9     @ RCSTA.6
#pragma bit  SPEN    @ RCSTA.7

#pragma bit  SWDTEN  @ WDTCON.0

#pragma bit  CM0     @ CMCON0.0
#pragma bit  CM1     @ CMCON0.1
#pragma bit  CM2     @ CMCON0.2
#pragma bit  CIS     @ CMCON0.3
#pragma bit  C1INV   @ CMCON0.4
#pragma bit  C2INV   @ CMCON0.5
#pragma bit  C1OUT   @ CMCON0.6
#pragma bit  C2OUT   @ CMCON0.7

#pragma bit  C2SYNC  @ CMCON1.0
#pragma bit  T1GSS   @ CMCON1.1

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.1
#pragma bit  CHS0    @ ADCON0.2
#pragma bit  CHS1    @ ADCON0.3
#pragma bit  CHS2    @ ADCON0.4
#pragma bit  VCFG    @ ADCON0.6
#pragma bit  ADFM    @ ADCON0.7

#pragma bit  RAPU_   @ OPTION_REG.7

#pragma bit  TRISA0  @ TRISA.0
#pragma bit  TRISA1  @ TRISA.1
#pragma bit  TRISA2  @ TRISA.2
#pragma bit  TRISA3  @ TRISA.3
#pragma bit  TRISA4  @ TRISA.4
#pragma bit  TRISA5  @ TRISA.5

#pragma bit  TRISC0  @ TRISC.0
#pragma bit  TRISC1  @ TRISC.1
#pragma bit  TRISC2  @ TRISC.2
#pragma bit  TRISC3  @ TRISC.3
#pragma bit  TRISC4  @ TRISC.4
#pragma bit  TRISC5  @ TRISC.5

#pragma bit  TMR1IE  @ PIE1.0
#pragma bit  TXIE    @ PIE1.1
#pragma bit  OSFIE   @ PIE1.2
#pragma bit  C1IE    @ PIE1.3
#pragma bit  C2IE    @ PIE1.4
#pragma bit  RCIE    @ PIE1.5
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
#pragma bit  EEPGD   @ EECON1.7

#pragma bit  ADCS0   @ ADCON1.4
#pragma bit  ADCS1   @ ADCON1.5
#pragma bit  ADCS2   @ ADCON1.6
