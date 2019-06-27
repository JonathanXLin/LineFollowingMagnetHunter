/*
  SERIAL COMMUNICATION (RS232)
  ============================

  Using 9600 baud, one stop bit, no parity.
  Baudrate 9600 baud => 104.167 microsec. per bit
  TMR0 counts each 8th microsec. => 13.02 steps per bit

  ______       _____ _____ _____ _____ _____ _____ _____ _____ _____
        |_____|_____|_____|_____|_____|_____|_____|_____|_____|
         Start bit0  bit1  bit2  bit3  bit4  bit5  bit6  bit7  Stop

  NOTE: RS232 signal levels are different from the CMOS levels
  used by the PIC device. A level converter is required:

        Logic level     CMOS       RS232
        1 (default)     +Vcc       -2.8V to -15V
        0               0 V        +2.8V to +15V
*/

#define _4_MHz    /* 4 MHz system clock */

// optional items
//#define UseTMR0
#define USE_CONST


#pragma bit RS232_out @ PORTB.0
#pragma bit RS232_in  @ PORTB.1

#ifdef _4_MHz
 #define   TimeStartbit    4
 #define   BitTimeIncr     13
#endif

char bitCount, limit;
char serialData;

#ifdef _4_MHz
 #ifdef UseTMR0
   #define delayStart   limit = TMR0;
   #define delayOneBit      \
     limit += BitTimeIncr;  \
     while (limit != TMR0) \
         ;
 #else
   #define delayStart   /* empty */
   #define delayOneBit  {      \
        char ti;               \
        ti = 30;               \
        do ; while( --ti > 0); \
        nop();                 \
     }  /* total: 5 + 30*3 - 1 + 1 + 9 \
           = 104 microsec. at 4 MHz */
 #endif
#endif

void sendData( char dout)
/* sends one byte */
{
    RS232_out = 0;  /* startbit */
    delayStart
    for (bitCount = 9; ; bitCount--)  {
        delayOneBit
        if (bitCount == 0)
            break;
        Carry = 1;  /* incl. stopbit */
        dout = rr( dout);
        RS232_out = Carry;
    }
}


#define NText 12

#ifndef USE_CONST
char text( char i)
{
    skip(i);
   #pragma return[NText] = "Hello world!"
}
#else
const char text[NText] = "Hello world!";
#endif


void main( void)
{
    char i;

    /* NOTE: some devices like the 16F877 have an on-chip analog to
       digital converter with analog input pins that should be
       configured. */
    //ADCON1 = ..; // Refer to the data sheet for init values.

    PORTB = 0x03; // xxxx xx11
    TRISB = 0xFE; // xxxx xx10
    OPTION = 2;   // prescaler divide by 8

    for (i = 0; i < NText; i++)  {
       #ifndef USE_CONST
        sendData( text(i));  /* text string */
       #else
        sendData( text[i]);  /* text string */
       #endif
    }

  WaitNextIO:
    while (RS232_in == 1)
        ;

  Start_RS232:
    /* sampling once per bit */
    TMR0 = 0;
    limit = TimeStartbit;
    while (limit != TMR0)
        ;
    if (RS232_in == 1)
        goto StartBitError;

    bitCount = 8;
    do  {
        limit += BitTimeIncr;
        while (limit != TMR0)
            ;
        Carry = RS232_in;
        serialData = rr( serialData);  /* rotate carry */
    } while (-- bitCount > 0);

    limit += BitTimeIncr;
    while (limit != TMR0)
        ;
    if (RS232_in == 0)
        goto StopBitError;

    /* 'serialData' can be processed here */
    /* NOTE: limited time (40 - 50 microsec.) */
    goto WaitNextIO;

  StopBitError:
    /* RS232 stopbit error,
       waiting while line is low */
    while (RS232_in == 0)
        ;
  StartBitError:
    goto WaitNextIO;
}
