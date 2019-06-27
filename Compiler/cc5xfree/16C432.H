// HEADER FILE
#pragma chip PIC16C432, core 14, code 2048, ram 32 : 0xBF
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_com_style
#define INT_rambank  0   /* bank 0 */

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

#pragma char CMCON   @ 0x1F

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E

#pragma char LININTF @ 0x90

#pragma char VRCON   @ 0x9F

#pragma bit  RA0     @ PORTA.0
#pragma bit  LINRX   @ PORTA.1
#pragma bit  RA2     @ PORTA.2
#pragma bit  RA3     @ PORTA.3
#pragma bit  RA4     @ PORTA.4

#pragma bit  RB0     @ PORTB.0
#pragma bit  RB1     @ PORTB.1
#pragma bit  RB2     @ PORTB.2
#pragma bit  RB3     @ PORTB.3
#pragma bit  RB4     @ PORTB.4
#pragma bit  RB5     @ PORTB.5
#pragma bit  RB6     @ PORTB.6
#pragma bit  RB7     @ PORTB.7

#pragma bit  PEIE    @ INTCON.6

#pragma bit  CMIF    @ PIR1.6

#pragma bit  CM0     @ CMCON.0
#pragma bit  CM1     @ CMCON.1
#pragma bit  CM2     @ CMCON.2
#pragma bit  CIS     @ CMCON.3
#pragma bit  C1OUT   @ CMCON.6
#pragma bit  C2OUT   @ CMCON.7

#pragma bit  TRISA0  @ TRISA.0
#pragma bit  TLINRX  @ TRISA.1
#pragma bit  TRISA2  @ TRISA.2
#pragma bit  TRISA3  @ TRISA.3
#pragma bit  TRISA4  @ TRISA.4

#pragma bit  TRISB0  @ TRISB.0
#pragma bit  TRISB1  @ TRISB.1
#pragma bit  TRISB2  @ TRISB.2
#pragma bit  TRISB3  @ TRISB.3
#pragma bit  TRISB4  @ TRISB.4
#pragma bit  TRISB5  @ TRISB.5
#pragma bit  TRISB6  @ TRISB.6
#pragma bit  TRISB7  @ TRISB.7

#pragma bit  CMIE    @ PIE1.6

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  LINVDD  @ LININTF.0
#pragma bit  LINTX   @ LININTF.2

#pragma bit  VR0     @ VRCON.0
#pragma bit  VR1     @ VRCON.1
#pragma bit  VR2     @ VRCON.2
#pragma bit  VR3     @ VRCON.3
#pragma bit  VRR     @ VRCON.5
#pragma bit  VROE    @ VRCON.6
#pragma bit  VREN    @ VRCON.7
