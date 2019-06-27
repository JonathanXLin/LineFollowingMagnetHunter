// DATA STORED IN PROGRAM MEMORY AND POINTERS

#pragma chip PIC16F77

/* NOTES:
  1. 'const' data MUST be static within a module
  2. Extern visible pointers must be 16 bit on many devices because
     the compiler can not trace pointer assignment between modules
*/

// THE 'const' TYPE MODIFIER IS RECOMMENDED FOR ALL ROM DATA
const int16 tx[10] = { 1, 2, 1000, -34, -30000, 2, 100, 23, 0, 0};

const char str[] = "String 1";  // a string in program memory

const char notAccessed[] = "This data is not stored because it is not read";
// NOTE: const data that are not read is removed!

const struct  {
  /* The first const in this definition tells that the pointers (the
     struct elements) are to be stored in program memory. The
     second 'const' tells that the strings also can be stored in
     program memory */
  const char *str;
} txtp[] = {
  "A table of pointer to strings",
  "Monday", "Tuesday",
  "MyString",
  "MyString",  // equal strings and substrings are merged to save space
  "String",    // merged with "MyString"
};


char rTable[5];

void writeString(const char *s)
{
    while (1)  {
        char u = *s++;
        if (!u)
            break;
        // write 'u' to serial port, LCD, etc.
    }
}


void sub(uns8 i)
{
    // reading the 'const' table
    int16 t = tx[i];

    const char *p = str;
    i = *p;
    p = "Hello world";
    i = *p;

    char si;
    p = txtp[si].str;
    i = *p;

    writeString( "Hello world");
    writeString( rTable);
    writeString( str);
    writeString( &rTable[3]);
}


void pointers2( void)
{
    char *a = rTable; // assign address to pointer
    char t = *a;      // read pointer
    char i;
    rTable[0] = 'A';
    rTable[1] = 0x30;
    a = &rTable[i];    // assign address
}


char tab1[10];
char tab2[10];

bank1 uns24 tu2[10];
bank2 uns24 tu3[10];
uns24 *px;


void pointers( void)
{
    // p1 is 8 bit wide
    char *p1 = tab1;
    char s = 0;
    do
       s += *p1 & 3;
    while (++p1 < &tab1[10]);

    // px is 16 bit wide because it can access elements from 2 banks
    px = tu2;
    px = &tu3[9];
    uns24 e = *px;


    // low level pointer access
    FSR = &tab1[1];
    IRP = &tab1[1] / 256;
    char a = INDF;   // direct indirect reading
    FSR += 1;  // next element
    INDF += 2;  // direct writing to element pointed to
}


typedef struct {
  uns16 ab;
  struct {
    uns8 l1;
    uns8 l2;
  } vx;
} Txx;

Txx ax, bx[2], *pxx;

void sub0( void)
{
    pxx = &ax;
    ax.ab = 1000;
    pxx->vx.l1 = 3;

    pxx = &bx[0];
    pxx += 1;    // increment to next element (size-dependent)
    pxx->ab = 0;
    pxx->vx.l2 = 0;
}


size2 uns16 *lp;  /* NOTE: this pointer need to be assigned
 addresses both above and below 256, otherwise the compiler will
 warn that the size can be reduced to 8 bit (size1). This warning
 is generated only when the pointer is static or local. */

uns16 sub2( void)
{
    uns16 dx;
    dx = *lp;

    lp = &tu2[0];  // bank 1 (address 128 - 256)
    dx = *lp;
    lp = &tu3[0];  // bank 2 (address 256 - 384)
    return dx;
}

uns16 sub3( void)
{
    return *lp;
}



void main(void)
{
    pointers();
    pointers2();
    sub(3);
    sub0();

    lp = &tu2[0];

    uns16 z = sub2();
    z += sub3();
}



