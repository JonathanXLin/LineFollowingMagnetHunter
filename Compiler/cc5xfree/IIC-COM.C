
/* IIC-COM.C:  IIC-BUS COMMUNICATION */

#define Clock_4MHz

#pragma bit scl_IIC @ PORTA.1
#pragma bit sda_IIC @ PORTA.0
#define  WRITE_sda()  TRISA = 0xFC /* xxxx xx00 */
#define  READ_sda()   TRISA = 0xFD /* xxxx xx01 */

#define  _address_RW_0   0xa2
#define  _address_RW_1   0xa3

char  IIC_byte;
bit   IIC_error, master_ack;

//#pragma codepage 3
#include <iicbus.c>
//#pragma codepage 0

char aa,bb,cc;

void read_IIC( char address)
/* reads 3 bytes from the IIC device */
{
    startIICcomm();
    sendIICbyte( _address_RW_0);
    sendIICbyte( address);
    stopIICcomm();

    startIICcomm();
    sendIICbyte( _address_RW_1);

    master_ack = 0;
    readIICbus();  aa = IIC_byte;
    readIICbus();  bb = IIC_byte;
    master_ack = 1;
    readIICbus();  cc = IIC_byte;
    stopIICcomm();
}

void write_IIC( char address)
/* writes 3 byte variables to the IIC device */
{
    startIICcomm();
    sendIICbyte( _address_RW_0);
    sendIICbyte( address);

    sendIICbyte(aa);
    sendIICbyte(bb);
    sendIICbyte(cc);
    stopIICcomm();
}

void main( void)
{
    PORTA = 0b00000011;  // xxxx xx11
    TRISA = 0b11111100;  // xxxx xx00
    write_IIC( 10);
    read_IIC( 10);
}
