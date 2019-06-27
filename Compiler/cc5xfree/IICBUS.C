/*
    IIC BUS INTERFACE:

    Code size for one read and one write to IIC device:

        8 MHz clock   : 110 instructions
        4 MHz clock   : 91 instructions
        2 MHz clock   : 82 instructions
        500 kHz clock : 76 instructions

    Use of macros are recommended. This module use
    subroutines in one level. New macros may be
    constructed in a similar way.

    Delay syntax:
      delay_4us_m3 : insert a 4 microseconds delay, but subtract the
                     time to execute 3 instruction cycles

    1 instruction cycle = 4 clock cycles = 1 microsecond at 4 MHz
*/


#ifndef WRITE_sda

  #define TEST_IIC

  /* these should be user defined */

  #define Clock_8MHz

  #pragma  bit  scl_IIC    @ PORTA.1
  #pragma  bit  sda_IIC    @ PORTA.0

  #define  WRITE_sda()     TRISA = 0xFE
  #define  READ_sda()      TRISA = 0xFF

  #define  IIC_address_RW_0   0xa2
  #define  IIC_address_RW_1   0xa3

  char  IIC_byte;
  bit   IIC_error, master_ack;

#endif

#ifdef Clock_8MHz
  #define  delay_(kn)  { char x; x=kn; do x--; while (x>0); }
  #define  delay_4us_m1  delay_( 2)
  #define  delay_4us_m3  nop();nop();nop();nop();nop();
  #define  delay_4us_m6  nop(); nop();
  #define  delay_4us_m7  nop();
  #define  delay_4us_m8
  #define  delay_5us_m1  delay_( 3)
  #define  delay_5us_m2  delay_( 3)
  #define  delay_5us_m5  nop();nop();nop();nop();nop();
  #define  delay_5us_m7  nop();nop();nop();
  #define  delay_5us_m10
  #define  delay_0us_m1
#endif

#ifdef Clock_4MHz
  #define  delay_4us_m1   nop();nop();nop();
  #define  delay_4us_m3   nop();
  #define  delay_4us_m6
  #define  delay_4us_m7
  #define  delay_4us_m8
  #define  delay_5us_m1   nop();nop();nop();nop();
  #define  delay_5us_m2   nop();nop();nop();
  #define  delay_5us_m5
  #define  delay_5us_m7
  #define  delay_5us_m10
  #define  delay_0us_m1
#endif

#ifdef Clock_2MHz
  #define  delay_4us_m1   nop();
  #define  delay_4us_m3
  #define  delay_4us_m6
  #define  delay_4us_m7
  #define  delay_4us_m8
  #define  delay_5us_m1   nop();nop();
  #define  delay_5us_m2   nop();
  #define  delay_5us_m5
  #define  delay_5us_m7
  #define  delay_5us_m10
  #define  delay_0us_m1
#endif

#ifdef Clock_500kHz
  #define  delay_4us_m1
  #define  delay_4us_m3
  #define  delay_4us_m6
  #define  delay_4us_m7
  #define  delay_4us_m8
  #define  delay_5us_m1
  #define  delay_5us_m2
  #define  delay_5us_m5
  #define  delay_5us_m7
  #define  delay_5us_m10
  #define  delay_0us_m1
#endif


void startIICcomm( void)
/* assuming sda_IIC = 1  and  scl_IIC = 1 */
{
    WRITE_sda();
    sda_IIC = 0;
    delay_5us_m10
}


void stopIICcomm( void)
{
    scl_IIC = 0;
    WRITE_sda();
    sda_IIC = 0;
    delay_5us_m1
    scl_IIC = 1;
    delay_4us_m1
    sda_IIC = 1;
    delay_4us_m6
}


void readIICbus( void)
/* reads one byte from IIC slave device */
{
    char  counter;

    scl_IIC = 0;
    READ_sda();
    counter = 8;
    do  {
        scl_IIC = 0;
        delay_5us_m1
        scl_IIC = 1;
        delay_4us_m7
        Carry = sda_IIC;
        IIC_byte = rl( IIC_byte);
    } while ( -- counter > 0);

    scl_IIC = 0;
    WRITE_sda();
    sda_IIC = master_ack;
    delay_5us_m7
    scl_IIC = 1;
    delay_4us_m6
}


void sendIICbyte( char W)
/* writes one byte to IIC slave device */
{
    char  counter;

    IIC_byte = W;
    WRITE_sda();
    counter = 8;

    do  {
        IIC_byte = rl( IIC_byte);
        scl_IIC = 0;
        delay_5us_m5
        sda_IIC = Carry;
        delay_0us_m1   /* minimum 250 nanosec. */
        scl_IIC = 1;
        delay_4us_m3
    } while ( -- counter > 0);

    /* read ack. */

    scl_IIC = 0;
    READ_sda();
    delay_5us_m2
    scl_IIC = 1;
    if ( sda_IIC)
        IIC_error = 1;
    delay_4us_m8
}


#define  readByteFromIIC( address, variable)     \
    startIICcomm();                              \
    sendIICbyte( IIC_address_RW_0);              \
    sendIICbyte( address);                       \
    stopIICcomm();                               \
                                                 \
    startIICcomm();                              \
    sendIICbyte( IIC_address_RW_1);              \
                                                 \
    /* more bytes to read ..                     \
      master_ack = 0;                            \
      readIICbus();  */                          \
                                                 \
    master_ack = 1;                              \
    readIICbus();                                \
    stopIICcomm();                               \
    variable = IIC_byte


#define  writeByteToIIC( address, IIC_data)      \
    startIICcomm();                              \
    sendIICbyte( IIC_address_RW_0);              \
    sendIICbyte( address);                       \
                                                 \
    sendIICbyte( IIC_data);                      \
    /* + more bytes to send                      \
      sendIICbyte( .. ); */                      \
                                                 \
    stopIICcomm();

/* NOTE: EEPROM's require a delay between each
         (block) write to the IIC device */


#ifdef TEST_IIC
 void main( void)
 {
     char x;
     writeByteToIIC( 1, 100);
     readByteFromIIC( 10, x);
 }
#endif
