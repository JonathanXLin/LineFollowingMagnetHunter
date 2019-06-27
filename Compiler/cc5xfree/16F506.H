// HEADER FILE
#pragma chip PIC16F506, core 12, code 1023, ram 0x0D : 0x7F
// NOTE: last code location is omitted   ^--

#pragma resetVector 0

#pragma config_def 0x0022

/* Predefined:
  char W;
  char INDF, TMR0, PCL, STATUS, FSR, PORTB, PORTC;
  char OPTION, TRISB, TRISC;
  bit Carry, DC, Zero_, PD, TO, PA0;
  bit FSR_5, FSR_6;
*/

#pragma char OSCCAL  @ 5

#pragma char CM1CON0 @ 8
#pragma char ADCON0  @ 9
#pragma char ADRES   @ 10
#pragma char CM2CON0 @ 11
#pragma char VRCON   @ 12

#pragma bit  CWUF     @ STATUS.6
#pragma bit  RBWUF    @ STATUS.7

#pragma bit  C1WU_    @ CM1CON0.0
#pragma bit  C1PREF   @ CM1CON0.1
#pragma bit  C1NREF   @ CM1CON0.2
#pragma bit  C1ON     @ CM1CON0.3
#pragma bit  C1T0CS_  @ CM1CON0.4
#pragma bit  C1POL    @ CM1CON0.5
#pragma bit  C1OUTEN_ @ CM1CON0.6
#pragma bit  C1OUT    @ CM1CON0.7

#pragma bit  ADON     @ ADCON0.0
#pragma bit  GO       @ ADCON0.1
#pragma bit  CHS0     @ ADCON0.2
#pragma bit  CHS1     @ ADCON0.3
#pragma bit  ADCS0    @ ADCON0.4
#pragma bit  ADCS1    @ ADCON0.5
#pragma bit  ANS0     @ ADCON0.6
#pragma bit  ANS1     @ ADCON0.7

#pragma bit  C2WU_    @ CM2CON0.0
#pragma bit  C2PREF1  @ CM2CON0.1
#pragma bit  C2NREF   @ CM2CON0.2
#pragma bit  C2ON     @ CM2CON0.3
#pragma bit  C2PREF2  @ CM2CON0.4
#pragma bit  C2POL    @ CM2CON0.5
#pragma bit  C2OUTEN_ @ CM2CON0.6
#pragma bit  C2OUT    @ CM2CON0.7

#pragma bit  VR0     @ VRCON.0
#pragma bit  VR1     @ VRCON.1
#pragma bit  VR2     @ VRCON.2
#pragma bit  VR3     @ VRCON.3
#pragma bit  VRR     @ VRCON.5
#pragma bit  VROE    @ VRCON.6
#pragma bit  VREN    @ VRCON.7
