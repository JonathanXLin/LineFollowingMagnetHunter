// HEADER FILE
#pragma chip PIC16C433, core 14, code 2048, ram 32 : 0xBF
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_com_style
#define INT_rambank  0   /* bank 0 */

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

#pragma char ADRES   @ 0x1E
#pragma char ADCON0  @ 0x1F

#pragma char TRIS    @ 0x85

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E
#pragma char OSCCAL  @ 0x8F

#pragma char ADCON1  @ 0x9F

#pragma bit  GP0     @ GPIO.0
#pragma bit  GP1     @ GPIO.1
#pragma bit  GP2     @ GPIO.2
#pragma bit  GP3     @ GPIO.3
#pragma bit  GP4     @ GPIO.4
#pragma bit  GP5     @ GPIO.5
#pragma bit  LINRX   @ GPIO.6
#pragma bit  LINTX   @ GPIO.7

#pragma bit  GPIF    @ INTCON.0
#pragma bit  GPIE    @ INTCON.3
#pragma bit  PEIE    @ INTCON.6

#pragma bit  ADIF    @ PIR1.6

#pragma bit  ADON    @ ADCON0.0
#pragma bit  GO      @ ADCON0.2
#pragma bit  CHS0    @ ADCON0.3
#pragma bit  CHS1    @ ADCON0.4
#pragma bit  ADCS0   @ ADCON0.6
#pragma bit  ADCS1   @ ADCON0.7

#pragma bit  ADIE    @ PIE1.6

#pragma bit  POR_    @ PCON.1

#pragma bit  CALSLW  @ OSCCAL.2
#pragma bit  CALFST  @ OSCCAL.3
#pragma bit  CAL0    @ OSCCAL.4
#pragma bit  CAL1    @ OSCCAL.5
#pragma bit  CAL2    @ OSCCAL.6
#pragma bit  CAL3    @ OSCCAL.7

#pragma bit  PCFG0   @ ADCON1.0
#pragma bit  PCFG1   @ ADCON1.1
#pragma bit  PCFG2   @ ADCON1.2
