// HEADER FILE
#pragma chip PIC16C925, core 14, code 4096, ram 32 : 0xFF /1 /3
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_gen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x1111

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

#pragma char PORTC   @ 7
#pragma char PORTD   @ 8
#pragma char PORTE   @ 9

#pragma char PIR1    @ 12

#pragma char TMR1L   @ 14
#pragma char TMR1H   @ 15
#pragma char T1CON   @ 16
#pragma char TMR2    @ 17
#pragma char T2CON   @ 18
#pragma char SSPBUF  @ 19
#pragma char SSPCON  @ 20
#pragma char CCPR1L  @ 21
#pragma char CCPR1H  @ 22
#pragma char CCP1CON @ 23

#pragma char ADRESH  @ 30
#pragma char ADCON0  @ 31

#pragma char TRISC   @ 0x87
#pragma char TRISD   @ 0x88
#pragma char TRISE   @ 0x89

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E

#pragma char PR2     @ 0x92
#pragma char SSPADD  @ 0x93
#pragma char SSPSTAT @ 0x94

#pragma char ADRESL  @ 0x9E
#pragma char ADCON1  @ 0x9F

#pragma char PORTF   @ 0x107
#pragma char PORTG   @ 0x108

#pragma char PMCON1  @ 0x10C
#pragma char LCDSE   @ 0x10D
#pragma char LCDPS   @ 0x10E
#pragma char LCDCON  @ 0x10F
#pragma char LCDD00  @ 0x110
#pragma char LCDD01  @ 0x111
#pragma char LCDD02  @ 0x112
#pragma char LCDD03  @ 0x113
#pragma char LCDD04  @ 0x114
#pragma char LCDD05  @ 0x115
#pragma char LCDD06  @ 0x116
#pragma char LCDD07  @ 0x117
#pragma char LCDD08  @ 0x118
#pragma char LCDD09  @ 0x119
#pragma char LCDD10  @ 0x11A
#pragma char LCDD11  @ 0x11B
#pragma char LCDD12  @ 0x11C
#pragma char LCDD13  @ 0x11D
#pragma char LCDD14  @ 0x11E
#pragma char LCDD15  @ 0x11F

#pragma char TRISF   @ 0x187
#pragma char TRISG   @ 0x188

#pragma char PMDATA  @ 0x18C
#pragma char PMADR   @ 0x18D
#pragma char PMDATH  @ 0x18E
#pragma char PMADRH  @ 0x18F


#pragma bit  PEIE    @ 11.6  mapped_into_all_banks

#pragma bit  TMR1IF  @ 12.0
#pragma bit  TMR2IF  @ 12.1
#pragma bit  CCP1IF  @ 12.2
#pragma bit  SSPIF   @ 12.3
#pragma bit  ADIF    @ 12.6
#pragma bit  LCDIF   @ 12.7

#pragma bit  TMR1ON  @ 16.0
#pragma bit  TMR1CS  @ 16.1
#pragma bit  T1SYNC_ @ 16.2
#pragma bit  T1OSCEN @ 16.3
#pragma bit  T1CKPS0 @ 16.4
#pragma bit  T1CKPS1 @ 16.5

#pragma bit  T2CKPS0 @ 18.0
#pragma bit  T2CKPS1 @ 18.1
#pragma bit  TMR2ON  @ 18.2
#pragma bit  TOUTPS0 @ 18.3
#pragma bit  TOUTPS1 @ 18.4
#pragma bit  TOUTPS2 @ 18.5
#pragma bit  TOUTPS3 @ 18.6

#pragma bit  SSPM0   @ 20.0
#pragma bit  SSPM1   @ 20.1
#pragma bit  SSPM2   @ 20.2
#pragma bit  SSPM3   @ 20.3
#pragma bit  CKP     @ 20.4
#pragma bit  SSPEN   @ 20.5
#pragma bit  SSPOV   @ 20.6
#pragma bit  WCOL    @ 20.7

#pragma bit  CCP1M0  @ 23.0
#pragma bit  CCP1M1  @ 23.1
#pragma bit  CCP1M2  @ 23.2
#pragma bit  CCP1M3  @ 23.3
#pragma bit  CCP1Y   @ 23.4
#pragma bit  CCP1X   @ 23.5

#pragma bit  ADON    @ 31.0
#pragma bit  GO      @ 31.2
#pragma bit  CHS0    @ 31.3
#pragma bit  CHS1    @ 31.4
#pragma bit  CHS2    @ 31.5
#pragma bit  ADCS0   @ 31.6
#pragma bit  ADCS1   @ 31.7

#pragma bit  TMR1IE  @ 0x8C.0
#pragma bit  TMR2IE  @ 0x8C.1
#pragma bit  CCP1IE  @ 0x8C.2
#pragma bit  SSPIE   @ 0x8C.3
#pragma bit  ADIE    @ 0x8C.6
#pragma bit  LCDIE   @ 0x8C.7

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1

#pragma bit  BF      @ 0x94.0
#pragma bit  UA      @ 0x94.1
#pragma bit  RW_     @ 0x94.2
#pragma bit  S       @ 0x94.3
#pragma bit  P       @ 0x94.4
#pragma bit  DA_     @ 0x94.5
#pragma bit  CKE     @ 0x94.6
#pragma bit  SMP     @ 0x94.7

#pragma bit  PCFG0   @ 0x9F.0
#pragma bit  PCFG1   @ 0x9F.1
#pragma bit  PCFG2   @ 0x9F.2

#pragma bit  RD      @ 0x10C.0

#pragma bit  SE0     @ 0x10D.0
#pragma bit  SE5     @ 0x10D.1
#pragma bit  SE9     @ 0x10D.2
#pragma bit  SE12    @ 0x10D.3
#pragma bit  SE16    @ 0x10D.4
#pragma bit  SE20    @ 0x10D.5
#pragma bit  SE27    @ 0x10D.6
#pragma bit  SE29    @ 0x10D.7

#pragma bit  LP0     @ 0x10E.0
#pragma bit  LP1     @ 0x10E.1
#pragma bit  LP2     @ 0x10E.2
#pragma bit  LP3     @ 0x10E.3

#pragma bit  LMUX0   @ 0x10F.0
#pragma bit  LMUX1   @ 0x10F.1
#pragma bit  CS0     @ 0x10F.2
#pragma bit  CS1     @ 0x10F.3
#pragma bit  VGEN    @ 0x10F.4
#pragma bit  SLPEN   @ 0x10F.6
#pragma bit  LCDEN   @ 0x10F.7
