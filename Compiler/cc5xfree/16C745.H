// HEADER FILE
#pragma chip PIC16C745, core 14, code 8192, ram 32 : 0x1DF
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks
#pragma ramdef 0x1A0 : 0x1B7 remove
#pragma ramdef 0x1B8 : 0x1DF remove // 40 byte USB Buffer (dual port RAM)

#define INT_gen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x0110

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
#pragma char PIR2    @ 0x0D
#pragma char TMR1L   @ 0x0E
#pragma char TMR1H   @ 0x0F
#pragma char T1CON   @ 0x10
#pragma char TMR2    @ 0x11
#pragma char T2CON   @ 0x12

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
#pragma char ADRES   @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRISC   @ 0x87

#pragma char PIE1    @ 0x8C
#pragma char PIE2    @ 0x8D
#pragma char PCON    @ 0x8E

#pragma char PR2     @ 0x92

#pragma char TXSTA   @ 0x98
#pragma char SPBRG   @ 0x99

#pragma char ADCON1  @ 0x9F

#pragma char UIR     @ 0x190
#pragma char UIE     @ 0x191
#pragma char UEIR    @ 0x192
#pragma char UEIE    @ 0x193
#pragma char USTAT   @ 0x194
#pragma char UCTRL   @ 0x195
#pragma char UADDR   @ 0x196
#pragma char USWSTAT @ 0x197
#pragma char UEP0    @ 0x198
#pragma char UEP1    @ 0x199
#pragma char UEP2    @ 0x19A

#pragma char BD0OST  @ 0x1A0
#pragma char BD0OBC  @ 0x1A1
#pragma char BD0OAL  @ 0x1A2

#pragma char BD0IST  @ 0x1A4
#pragma char BD0IBC  @ 0x1A5
#pragma char BD0IAL  @ 0x1A6

#pragma char BD1OST  @ 0x1A8
#pragma char BD1OBC  @ 0x1A9
#pragma char BD1OAL  @ 0x1AA

#pragma char BD1IST  @ 0x1AC
#pragma char BD1IBC  @ 0x1AD
#pragma char BD1IAL  @ 0x1AE

#pragma char BD2OST  @ 0x1B0
#pragma char BD2OBC  @ 0x1B1
#pragma char BD2OAL  @ 0x1B2

#pragma char BD2IST  @ 0x1B4
#pragma char BD2IBC  @ 0x1B5
#pragma char BD2IAL  @ 0x1B6


#pragma bit  PEIE    @ INTCON.6

#pragma bit  TMR1IF  @ PIR1.0
#pragma bit  TMR2IF  @ PIR1.1
#pragma bit  CCP1IF  @ PIR1.2
#pragma bit  USBIF   @ PIR1.3
#pragma bit  TXIF    @ PIR1.4
#pragma bit  RCIF    @ PIR1.5
#pragma bit  ADIF    @ PIR1.6

#pragma bit  CCP2IF  @ PIR2.0

#pragma bit  TMR1ON  @ T1CON.0
#pragma bit  TMR1CS  @ T1CON.1
#pragma bit  T1SYNC_ @ T1CON.2
#pragma bit  T1OSCEN @ T1CON.3
#pragma bit  T1CKPS0 @ T1CON.4
#pragma bit  T1CKPS1 @ T1CON.5

#pragma bit  T2CKPS0 @ T2CON.0
#pragma bit  T2CKPS1 @ T2CON.1
#pragma bit  TMR2ON  @ T2CON.2
#pragma bit  TOUTPS0 @ T2CON.3
#pragma bit  TOUTPS1 @ T2CON.4
#pragma bit  TOUTPS2 @ T2CON.5
#pragma bit  TOUTPS3 @ T2CON.6

#pragma bit  CCP1M0  @ CCP1CON.0
#pragma bit  CCP1M1  @ CCP1CON.1
#pragma bit  CCP1M2  @ CCP1CON.2
#pragma bit  CCP1M3  @ CCP1CON.3
#pragma bit  DC1B0   @ CCP1CON.4
#pragma bit  DC1B1   @ CCP1CON.5

#pragma bit  RX9D    @ RCSTA.0
#pragma bit  OERR    @ RCSTA.1
#pragma bit  FERR    @ RCSTA.2
#pragma bit  CREN    @ RCSTA.4
#pragma bit  SREN    @ RCSTA.5
#pragma bit  RX9     @ RCSTA.6
#pragma bit  SPEN    @ RCSTA.7

#pragma bit  CCP2M0  @ CCP2CON.0
#pragma bit  CCP2M1  @ CCP2CON.1
#pragma bit  CCP2M2  @ CCP2CON.2
#pragma bit  CCP2M3  @ CCP2CON.3
#pragma bit  DC2B0   @ CCP2CON.4
#pragma bit  DC2B1   @ CCP2CON.5

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
#pragma bit  USBIE   @ PIE1.3
#pragma bit  TXIE    @ PIE1.4
#pragma bit  RCIE    @ PIE1.5
#pragma bit  ADIE    @ PIE1.6

#pragma bit  CCP2IE  @ PIE2.0

#pragma bit  BOR_    @ PCON.0
#pragma bit  POR_    @ PCON.1

#pragma bit  TX9D    @ TXSTA.0
#pragma bit  TRMT    @ TXSTA.1
#pragma bit  BRGH    @ TXSTA.2
#pragma bit  SYNC    @ TXSTA.4
#pragma bit  TXEN    @ TXSTA.5
#pragma bit  TX9     @ TXSTA.6
#pragma bit  CSRC    @ TXSTA.7

#pragma bit  PCFG0   @ ADCON1.0
#pragma bit  PCFG1   @ ADCON1.1
#pragma bit  PCFG2   @ ADCON1.2
