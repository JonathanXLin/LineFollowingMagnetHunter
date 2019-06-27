// HEADER FILE
#pragma chip PIC16C781, core 14, code 1024, ram 32 : 0xBF /1 /3
#pragma ramdef  0x70 : 0x7F mapped_into_all_banks

#define INT_lgen_style
#define INT_rambank  0   /* interrupt variables in bank 0 */

#pragma config_def 0x1222

#pragma wideConstData p

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

#pragma char PIR1    @ 12

#pragma char TMR1L   @ 14
#pragma char TMR1H   @ 15
#pragma char T1CON   @ 16

#pragma char ADRES   @ 30
#pragma char ADCON0  @ 31

#pragma char PIE1    @ 0x8C

#pragma char PCON    @ 0x8E

#pragma char WPUB    @ 0x95
#pragma char IOCB    @ 0x96

#pragma char REFCON  @ 0x9B
#pragma char LVDCON  @ 0x9C
#pragma char ANSEL   @ 0x9D

#pragma char ADCON1  @ 0x9F

#pragma char PMDATL  @ 0x10C
#pragma char PMADRL  @ 0x10D
#pragma char PMDATH  @ 0x10E
#pragma char PMADRH  @ 0x10F
#pragma char CALCON  @ 0x110
#pragma char PSMCCON0 @ 0x111
#pragma char PSMCCON1 @ 0x112

#pragma char CM1CON0 @ 0x119
#pragma char CM2CON0 @ 0x11A
#pragma char CM2CON1 @ 0x11B
#pragma char OPACON  @ 0x11C

#pragma char DAC     @ 0x11E
#pragma char DACON0  @ 0x11F

#pragma char PMCON1  @ 0x18C


#pragma bit  RA0     @ 5.0
#pragma bit  RA1     @ 5.1
#pragma bit  RA2     @ 5.2
#pragma bit  RA3     @ 5.3
#pragma bit  RA4     @ 5.4
#pragma bit  RA5     @ 5.5
#pragma bit  RA6     @ 5.6
#pragma bit  RA7     @ 5.7

#pragma bit  RB0     @ 6.0
#pragma bit  RB1     @ 6.1
#pragma bit  RB2     @ 6.2
#pragma bit  RB3     @ 6.3
#pragma bit  RB4     @ 6.4
#pragma bit  RB5     @ 6.5
#pragma bit  RB6     @ 6.6
#pragma bit  RB7     @ 6.7

#pragma bit  PEIE    @ 11.6  mapped_into_all_banks

#pragma bit  TMR1IF  @ 12.0
#pragma bit  C1IF    @ 12.4
#pragma bit  C2IF    @ 12.5
#pragma bit  ADIF    @ 12.6
#pragma bit  LVDIF   @ 12.7

#pragma bit  TMR1ON  @ 16.0
#pragma bit  TMR1CS  @ 16.1
#pragma bit  T1SYNC_ @ 16.2
#pragma bit  T1OSCEN @ 16.3
#pragma bit  T1CKPS0 @ 16.4
#pragma bit  T1CKPS1 @ 16.5
#pragma bit  TMR1GE  @ 16.6

#pragma bit  ADON    @ 31.0
#pragma bit  CHS3    @ 31.1
#pragma bit  GO      @ 31.2
#pragma bit  CHS0    @ 31.3
#pragma bit  CHS1    @ 31.4
#pragma bit  CHS2    @ 31.5
#pragma bit  ADCS0   @ 31.6
#pragma bit  ADCS1   @ 31.7

#pragma bit  TMR1IE  @ 0x8C.0
#pragma bit  C1IE    @ 0x8C.4
#pragma bit  C2IE    @ 0x8C.5
#pragma bit  ADIE    @ 0x8C.6
#pragma bit  LVDIE   @ 0x8C.7

#pragma bit  BOR_    @ 0x8E.0
#pragma bit  POR_    @ 0x8E.1
#pragma bit  OSCF    @ 0x8E.3
#pragma bit  WDTON   @ 0x8E.4

#pragma bit  VROE    @ 0x9B.2
#pragma bit  VREN    @ 0x9B.3

#pragma bit  LV0     @ 0x9C.0
#pragma bit  LV1     @ 0x9C.1
#pragma bit  LV2     @ 0x9C.2
#pragma bit  LV3     @ 0x9C.3
#pragma bit  LVDEN   @ 0x9C.4
#pragma bit  BGST    @ 0x9C.5

#pragma bit  VCFG0   @ 0x9F.4
#pragma bit  VCFG1   @ 0x9F.5

#pragma bit  PMD0    @ 0x10C.0
#pragma bit  PMD1    @ 0x10C.1
#pragma bit  PMD2    @ 0x10C.2
#pragma bit  PMD3    @ 0x10C.3
#pragma bit  PMD4    @ 0x10C.4
#pragma bit  PMD5    @ 0x10C.5
#pragma bit  PMD6    @ 0x10C.6
#pragma bit  PMD7    @ 0x10C.7

#pragma bit  PMA0    @ 0x10D.0
#pragma bit  PMA1    @ 0x10D.1
#pragma bit  PMA2    @ 0x10D.2
#pragma bit  PMA3    @ 0x10D.3
#pragma bit  PMA4    @ 0x10D.4
#pragma bit  PMA5    @ 0x10D.5
#pragma bit  PMA6    @ 0x10D.6
#pragma bit  PMA7    @ 0x10D.7

#pragma bit  PMD8    @ 0x10E.0
#pragma bit  PMD9    @ 0x10E.1
#pragma bit  PMD10   @ 0x10E.2
#pragma bit  PMD11   @ 0x10E.3
#pragma bit  PMD12   @ 0x10E.4
#pragma bit  PMD13   @ 0x10E.5

#pragma bit  PMA8    @ 0x10F.0
#pragma bit  PMA9    @ 0x10F.1
#pragma bit  PMA10   @ 0x10F.2

#pragma bit  CALREF  @ 0x110.5
#pragma bit  CALERR  @ 0x110.6
#pragma bit  CAL     @ 0x110.7

#pragma bit  DC0     @ 0x111.0
#pragma bit  DC1     @ 0x111.1
#pragma bit  MAXDC0  @ 0x111.2
#pragma bit  MAXDC1  @ 0x111.3
#pragma bit  MINDC0  @ 0x111.4
#pragma bit  MINDC1  @ 0x111.5
#pragma bit  SMCCL0  @ 0x111.6
#pragma bit  SMCCL1  @ 0x111.7

#pragma bit  SMCCS   @ 0x112.0
#pragma bit  PWM     @ 0x112.1
#pragma bit  SMCOM   @ 0x112.2
#pragma bit  SCEN    @ 0x112.3
#pragma bit  S1BPOL  @ 0x112.5
#pragma bit  S1APOL  @ 0x112.6
#pragma bit  SMCON   @ 0x112.7

#pragma bit  C1CH0   @ 0x119.0
#pragma bit  C1CH1   @ 0x119.1
#pragma bit  C1R     @ 0x119.2
#pragma bit  C1SP    @ 0x119.3
#pragma bit  C1POL   @ 0x119.4
#pragma bit  C1OE    @ 0x119.5
#pragma bit  C1OUT   @ 0x119.6
#pragma bit  C1ON    @ 0x119.7

#pragma bit  C2CH0   @ 0x11A.0
#pragma bit  C2CH1   @ 0x11A.1
#pragma bit  C2R     @ 0x11A.2
#pragma bit  C2SP    @ 0x11A.3
#pragma bit  C2POL   @ 0x11A.4
#pragma bit  C2OE    @ 0x11A.5
#pragma bit  C2OUT   @ 0x11A.6
#pragma bit  C2ON    @ 0x11A.7

#pragma bit  C2SYNC  @ 0x11B.0
#pragma bit  MC2OUT  @ 0x11B.6
#pragma bit  MC1OUT  @ 0x11B.7

#pragma bit  GBWP    @ 0x11C.0
#pragma bit  CMPEN   @ 0x11C.6
#pragma bit  OPAON   @ 0x11C.7

#pragma bit  DA0     @ 0x11E.0
#pragma bit  DA1     @ 0x11E.1
#pragma bit  DA2     @ 0x11E.2
#pragma bit  DA3     @ 0x11E.3
#pragma bit  DA4     @ 0x11E.4
#pragma bit  DA5     @ 0x11E.5
#pragma bit  DA6     @ 0x11E.6
#pragma bit  DA7     @ 0x11E.7

#pragma bit  DARS0   @ 0x11F.0
#pragma bit  DARS1   @ 0x11F.1
#pragma bit  DAOE    @ 0x11F.6
#pragma bit  DAON    @ 0x11F.7

#pragma bit  RD      @ 0x18C.0
