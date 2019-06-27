// HEADER FILE
#pragma chip PIC12CE674, core 14, code 2048, ram 32 : 0xBF
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

#pragma char GPIO    @ 5
#pragma char PIR1    @ 12
#pragma char ADRES   @ 30
#pragma char ADCON0  @ 31

#pragma char TRIS    @ 0x85
#pragma char PIE1    @ 0x8C
#pragma char PCON    @ 0x8E
#pragma char OSCCAL  @ 0x8F
#pragma char ADCON1  @ 0x9F


#pragma bit  GP0     @ 5.0
#pragma bit  GP1     @ 5.1
#pragma bit  GP2     @ 5.2
#pragma bit  GP3     @ 5.3
#pragma bit  GP4     @ 5.4
#pragma bit  GP5     @ 5.5
#pragma bit  SDA     @ 5.6
#pragma bit  SCL     @ 5.7

#pragma bit  GPIF    @ 11.0  mapped_into_bank_1
#pragma bit  GPIE    @ 11.3  mapped_into_bank_1
#pragma bit  PEIE    @ 11.6  mapped_into_bank_1

#pragma bit  ADIF    @ 12.6

#pragma bit  ADON    @ 31.0
#pragma bit  GO      @ 31.2
#pragma bit  CHS0    @ 31.3
#pragma bit  CHS1    @ 31.4
#pragma bit  ADCS0   @ 31.6
#pragma bit  ADCS1   @ 31.7

#pragma bit  GPPU_   @ 0x81.7

#pragma bit  ADIE    @ 0x8C.6

#pragma bit  POR_    @ 0x8E.1

#pragma bit  CAL0    @ 0x8F.2
#pragma bit  CAL1    @ 0x8F.3
#pragma bit  CAL2    @ 0x8F.4
#pragma bit  CAL3    @ 0x8F.5
#pragma bit  CAL4    @ 0x8F.6
#pragma bit  CAL5    @ 0x8F.7

#pragma bit  PCFG0   @ 0x9F.0
#pragma bit  PCFG1   @ 0x9F.1
#pragma bit  PCFG2   @ 0x9F.2
