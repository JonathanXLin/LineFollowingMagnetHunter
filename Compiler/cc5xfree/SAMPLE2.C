// THIS FILE CONTAINS RECOMMENDED PROGRAM STRUCTURE AND SYNTAX SAMPLES

/* COMMAND LINE OPTIONS:
   -a : generate assembly file
   -I\my\files : include files path (multiple -I<path> is supported)
   -CA : generate COD file for debugging
   .. all options is printed when starting the compiler without arguments
*/

#pragma chip PIC16F877
/* First define the device. It can be overridden by a similar
   command line option (-p16F877). Remember to supply the path to
   the valid header file (option -Ic:\cc5x or similar) if this is
   not located in the current directory */


/* HEADER FILES: define IO, variables, constants, prototypes, etc. */
// #include "myheader.h"
// #include "project\iodef.h"

// CONSTANTS
#define CONST1  10
#define CONST2  ((100 + CONST1) / 10)
enum { No0, No1, No2,  No10 = 10, No11,  No20 = 20 };

// IO definitions
bit  pin1 @ PORTB.0;
bit  mux  @ PORTB.1;


// DEFINING RAM VARIABLES
bit bt;        // a bit variable, value 0 or 1
char ga, c8;   // char is by default unsigned, value 0 - 255
uns32 ug32;    // a 32 bit unsigned variable
uns16 table1[3];  // a table of 3 elements, each 16 bit

// a structure
struct {
  char b;
  char c;
} cgt;

// a typedef
typedef struct {
  uns16 ab;
  int tab[10];
  struct {
    uns8 l1;
    uns8 l2;
  } vx;
} Txx;

// RAMBANK definition
/* The rambank have to be defined in the source code, either using
   #pragma rambank or the bank type modifier.  This is quite trivial
   unless you need to find optimal combinations to reduce the code
   size (which may require much trial and error). Note that the
   rambank selection also applies to local variables and parameters,
   which should be kept in the same bank if possible. */
bank1 Txx ax, bx[2];
bank0 char a;

#pragma rambank 3  // select default bank for the next definitions
char m1;
bank0 char uu1;
int32 m2;

#pragma rambank -  // default is unbanked/shared RAM
char yy;

#pragma rambank 1
char pp;
shrBank int16 ir;  // unbanked RAM


const char *pro[3];  // a table in RAM of pointers to 'const' data

// variables overlaying another variable or table
bit  ov0 @ bt;  // full overlay
char ov1 @ c8;  // full overlay
int8 ov2 @ c8;  // full overlay, different type
bit  ov3 @ ug32.31;           // partial overlay
uns16 uu16 @ ug32.mid16;      // partial overlay
uns24 uu24 @ table1[1].high8; // partial overlay
char table2[5] @ table1[0];   // partial overlay



// #pragma library 1  // this will delete all unused functions


// INTERRUPTS:

void fx(char x);  // prototype, fx is defined later
/* If the interrupt routine need to call a function, just define the
   prototype first */

#include "int16CXX.h"  // device dependent interrupt definitions

#pragma origin 4   // start address of interrupt routine (14 bit core)

interrupt serverX( void)
{
    int_save_registers    // W, STATUS (and PCLATH if required)

    //char sv_FSR = FSR;  // save FSR when using tables/pointers
    /* An error is generated if FSR need to be saved and the compiler
       does not detect that this is actually done */

    // handle the interrupt
    if ( T0IF)  {
        // .. handle TMR0 overflow
        T0IF = 0;  /* reset flag */
    }

    if ( INTF)  {
        // .. handle INT interrupt
        INTF = 0;  /* reset flag */
    }

    fx(0);  // call function

    //FSR = sv_FSR;               // restore FSR if saved
    int_restore_registers // W, STATUS (and PCLATH if required)
}
// GIE is automatically set to 1 on exit (by RETFIE).


// Include MATH LIBRARIES after interrupt definition
#include "math24f.h"   // 24 bit basic floating point operations
#include "math24lb.h"  // 24 bit math function library


// CODEPAGE definitions
/* The codepage have to be defined in the source code, either using
   #pragma codepage, #pragma location or the page type modifier.
   This is quite trivial unless you need to find optimal
   combinations to reduce the code size (which may require much
   trial and error). Note that #pragma location and the page type
   modifier is able to locate prototype definitions in addition to
   the function definition. Devices with only one codepage do not
   need any codepage definitions. The number of instructions in each
   page is printed by the compiler during compilation. Typical
   example usage is shown:

#pragma location 2  // codepage for following functions and prototypes
void myFunction1(void);
void myFunction2(char xt);
#pragma location 1  // codepage for following functions and prototypes
void myFunction3(uns16 ux, bit bx);
page0 void myFunction4(void);     // this goes to page 0
void myFunction5(int8, char, char);
#pragma location -  // enable #pragma codepage definition again

/* Note that #pragma codepage ONLY selects the codepage for those
   functions that are not yet located */
#pragma codepage 1   // select default codepage for following functions
#include "module1.c"
#include "module2.c"
#pragma codepage 2
#include "module3.c"
#pragma codepage 3
#include "module4.c"
#pragma codepage 0
#include "module5.c"
*/

// definition of earlier defined prototype function
void fx(char x)
{
    PORTB = x;
}

char function(char x)
{
    return *pro[x];  // return element pointed to
}

void init( void)
{
    cgt.c = 2;

    ov0 = 1;
    ov1 = 1;
    ov2 = 1;
    ov3 = 1;

    uu16 = 1000;

    uu24 = 1000000;
    table1[2] = 1;
    table1[0] = 2;
    table2[0] = 3;

    pro[0] = "Hello";
    pro[1] = &pp;
    pro[2] = "E\r\n\x7F";
}

void main( void)
{
    float X, input;
    uns16 ad;
    #define ConstF 22.94

    // initialize
    clearRAM();  // built-in function
    init();
    W = function(1) & 0x3F;  //

    ADFM = 1;  // right justify result

    // do AD conversion
    // ..

    // read result
    ad = ADRESH * 256;
    ad |= ADRESL;

    // alternative read result
    ad.high8 = ADRESH;
    ad.low8 = ADRESL;

    // process result
    input = ad;  // converting to float
    X = log(input) * ConstF;
    X = ConstF/input + X;
}
