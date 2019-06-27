// HEADER FILE
#pragma chip PIC14000, core 14, code 0xFC0, ram 32 : 0xFF
// NOTE: last 64 code locations are omitted

#define INT_max_style

#pragma config_def 0x0114

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

#pragma char PIR1    @ 12

#pragma char ADTMRL  @ 14
#pragma char ADTMRH  @ 15

#pragma char I2CBUF  @ 19
#pragma char I2CCON  @ 20
#pragma char ADCAPL  @ 21
#pragma char ADCAPH  @ 22

#pragma char ADCON0  @ 31

#pragma char TRISC   @ 0x87
#pragma char TRISD   @ 0x88

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E
#pragma char SLPCON  @ 0x8F

#pragma char I2CADD  @ 0x93
#pragma char I2CSTAT @ 0x94

#pragma char PREFA   @ 0x9B
#pragma char PREFB   @ 0x9C
#pragma char CMCON   @ 0x9D
#pragma char MISC    @ 0x9E
#pragma char ADCON1  @ 0x9F

#pragma bit  PEIE    @ 11.6  mapped_into_bank_1

#pragma bit  OVFIF   @ 12.0
#pragma bit  ADCIF   @ 12.1
#pragma bit  RCIF    @ 12.2
#pragma bit  I2CIF   @ 12.3
#pragma bit  PBIF    @ 12.4
#pragma bit  CMIF    @ 12.7

#pragma bit  I2CM0   @ 20.0
#pragma bit  I2CM1   @ 20.1
#pragma bit  I2CM2   @ 20.2
#pragma bit  I2CM3   @ 20.3
#pragma bit  CKP     @ 20.4
#pragma bit  I2CEN   @ 20.5
#pragma bit  I2COV   @ 20.6
#pragma bit  WCOL    @ 20.7

#pragma bit  ADZERO  @ 31.0
#pragma bit  ADRST   @ 31.1
#pragma bit  AMUXOE  @ 31.2
#pragma bit  ADCS0   @ 31.4
#pragma bit  ADCS1   @ 31.5
#pragma bit  ADCS2   @ 31.6
#pragma bit  ADCS3   @ 31.7

#pragma bit  OVFIE   @ 0x8C.0
#pragma bit  ADCIE   @ 0x8C.1
#pragma bit  RCIE    @ 0x8C.2
#pragma bit  I2CIE   @ 0x8C.3
#pragma bit  PBIE    @ 0x8C.4
#pragma bit  CMIE    @ 0x8C.7

#pragma bit  LVD_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1

#pragma bit  ADOFF   @ 0x8F.0
#pragma bit  TEMPOFF @ 0x8F.1
#pragma bit  CMOFF   @ 0x8F.2
#pragma bit  OSCOFF  @ 0x8F.3
#pragma bit  LSOFF   @ 0x8F.4
#pragma bit  REFOFF  @ 0x8F.5
#pragma bit  HIBEN   @ 0x8F.7

#pragma bit  BF      @ 0x94.0
#pragma bit  UA      @ 0x94.1
#pragma bit  RW_     @ 0x94.2
#pragma bit  S       @ 0x94.3
#pragma bit  P       @ 0x94.4
#pragma bit  DA_     @ 0x94.5

#pragma bit  PRA0    @ 0x9B.0
#pragma bit  PRA1    @ 0x9B.1
#pragma bit  PRA2    @ 0x9B.2
#pragma bit  PRA3    @ 0x9B.3
#pragma bit  PRA4    @ 0x9B.4
#pragma bit  PRA5    @ 0x9B.5
#pragma bit  PRA6    @ 0x9B.6
#pragma bit  PRA7    @ 0x9B.7

#pragma bit  PRB0    @ 0x9C.0
#pragma bit  PRB1    @ 0x9C.1
#pragma bit  PRB2    @ 0x9C.2
#pragma bit  PRB3    @ 0x9C.3
#pragma bit  PRB4    @ 0x9C.4
#pragma bit  PRB5    @ 0x9C.5
#pragma bit  PRB6    @ 0x9C.6
#pragma bit  PRB7    @ 0x9C.7

#pragma bit  CPOLA   @ 0x9D.0
#pragma bit  CMAOE   @ 0x9D.1
#pragma bit  CMAOUT  @ 0x9D.2
#pragma bit  CPOLB   @ 0x9D.4
#pragma bit  CMBOE   @ 0x9D.5
#pragma bit  CMBOUT  @ 0x9D.6

#pragma bit  OSC1    @ 0x9E.0
#pragma bit  OSC2    @ 0x9E.1
#pragma bit  INCLKEN @ 0x9E.2
#pragma bit  SMBUS   @ 0x9E.3
#pragma bit  I2CSEL  @ 0x9E.4
#pragma bit  SPGNDA  @ 0x9E.5
#pragma bit  SPGNDB  @ 0x9E.6
#pragma bit  SMHOG   @ 0x9E.7

#pragma bit  PCFG0   @ 0x9F.0
#pragma bit  PCFG1   @ 0x9F.1
#pragma bit  PCFG2   @ 0x9F.2
#pragma bit  PCFG3   @ 0x9F.3
#pragma bit  ADDAC0  @ 0x9F.4
#pragma bit  ADDAC1  @ 0x9F.5
#pragma bit  ADDAC2  @ 0x9F.6
#pragma bit  ADDAC3  @ 0x9F.7
