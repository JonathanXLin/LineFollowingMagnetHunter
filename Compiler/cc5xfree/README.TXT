
       =================================================
       README file for the CC5X C compiler, FREE edition
       =================================================

Welcome to the CC5X C compiler. The FREE edition can generate up to
1024 words of code in each module.

When evaluating the generated code, remember that the free edition
will not optimize updating of the bank and page bits. Also, duplicate
loading of the workspace (W) register will not be removed.

New versions of all CC5X editions are released at the same time.

The alternative TEST edition allows a large program to be compiled
using CC5X. However, NO hex file is generated and the assembly file
is NOT complete. The TEST edition is a separate package, different
from the FREE edition.


RESTRICTIONS
------------

  The free edition can be used to generate code for all prototype
  and non-commercial systems without restrictions. Permission is
  given to use the generated code in ONE commercial system.

  No restriction applies to source code written by the user.


COPYRIGHT NOTICE
----------------

  Copyright (c) B Knudsen Data, Trondheim, Norway, 1992 - 2006.

  www.bknd.com

  Fax: (+47) 73 96 51 84

  B Knudsen Data assumes no responsibility for errors or defects in
  the compiler or in the other supplied files. This also applies to
  problems caused by such errors.

  Making any changes to the compiler is strongly prohibited.

  Permission is required to distribute the FREE edition.



****************************************************************
==> A QUICK start is possible. Proceed to file 'INSTALL.TXT' and
    continue by compiling the example programs supplied.
****************************************************************



SPECIAL NOTES
-------------

  Newly added features are defined in file 'news.txt'

  CC5X is available in both 16 bits and 32 bits processing mode.
  The 16 bits processing is the old 16 bits pure MSDOS mode with the
  640 kB memory restriction, and high memory is automatically used
  to get enough memory. Both editions accepts the same syntax and
  generates the same code. The 16 mode is sometimes required when
  integrating CC5X into an environment which use the 16 bits mode.
  The processing mode can be identified by looking on the size of
  CC5X.EXE.


SUPPLIED FILES
--------------

  cc5x.exe      : CC5X compiler, FREE/TEST edition

  install.txt   : installation guide and MPLAB setup
  inline.txt    : information on inline assembly syntax
  debug.txt     : debugging details, MPLAB and COD file support
  chip.txt      : how to make new chip definitions
  cdata.txt     : info on the #pragma cdata statement
  const.txt     : standard C strings and constant data
  config.txt    : the chip configuration bits
  startup.txt   : special startup sequences
  linker.txt    : using MPLINK to link several modules (C or asm)
  c-goto.txt    : application notes on computed goto
  options.txt   : compiler command line options
  errata.txt    : silicon errata issues

  int16cxx.h    : interrupt header file
  inline.h      : C macros for emulating inline instructions
  hexcodes.h    : direct coded instructions

  cc5x.mtc      : MPLAB configuration file
  tlcc5x.ini    : MPLAB configuration file

  op.inc        : compiler options in a file
  reloc.inc     : options for generating object modules for linking

  sample1.c     : minimal program example
  sample2.c     : recommended program structure and syntax samples
  sample3.c     : data stored in program memory and pointers
  iicbus.c      : IIC-bus interface
  iic-com.c     : IIC-bus communication
  serial.c      : serial communication (RS232, RS485)
  state.c       : state machines
  delay.c       : implementing delays
  int16xx.c     : simple interrupt example
  div16_8.c     : fast division routine
  scaling.c     : compact and fast 16 bit math scaling routine

  12C508.H .. 16C924.H   : header files for specific chip support

  math.txt      : math library support

  math16.h      : 8-16 bit math library, signed and unsigned
  math16m.h     : 8-16 bit multiply, speed, signed and unsigned
  math24f.h     : 24 bit floating point basic math operations
  math24lb.h    : 24 bit floating point library

  news.txt      : recent added features
  readme.txt    : this file


SUPPORTED DEVICES
-----------------

  The compiler supports the 12 and 14 bit core devices from
  Microchip. Take a look in chip.txt for details on how to generate
  code for a particular device.


PROGRAMMING RECOMMENDATIONS THAT ENABLES COMPACT CODE
-----------------------------------------------------

  1. If you are going to use multiplication and division, take a
     look at 'math.txt'.

  2. CC5X will update the bank bits automatically, but variables
     have to be placed on the different RAM banks by using pragma
     statements. It therefore recommended to locate all global
     variables belonging to the same RAM bank together (in header
     files).

        #pragma rambank 0
         char a;  // variables to be located in bank 0
        #pragma rambank 1
         // variables to be located in bank 1
         ..

     Some notes when locating variables:
     a) Locate variables which are close related to each other in
        the same bank.
     b) Locate all variables accessed in the same function in the
        same bank if possible.
     c) Switching between bank 0 and 3, or bank 1 and 2 require more
        instructions than the other combinations.
     d) Use as few banks as possible. Fill bank 0 first, then bank 1,
        etc.


  3. It is most efficient to put all local variables in mapped RAM.
     This is easiest done by moving all global variables to the
     beginning of the program (or to header files). Then change the
     rambank to mapped RAM before compiling the functions:

         // all global variables
         #pragma rambank -    // mapped RAM
         // all functions


  4. It is recommended to define all functions before they are
     called. That is, make sure that the function code is compiled
     before the first function call is made. This allows better
     optimization of the bank selection bits (RP0,1 or FSR5,6).


  5. The functions have to be located on the different code pages by
     pragma instructions. Calling a function located in another
     codepage requires extra page instructions. CC5X will do this
     automatically. However, moving a function to another codepage
     may reduce the number of instructions required. Some of the
     PICmicro devices have 4 code pages. Note that calls which
     requires switching between page 0 and 3, or page 1 and 2
     requires more instructions than the other combinations.

     It is recommended to divide the program into modules. Use a
     small main file and include all header and program modules in
     the beginning of the main file. Pragma instructions will locate
     the functions. The generated function call structure file
     (*.fcs) contains information that will be helpful in finding
     optimal combinations. Please refer to the manual or the *.txt
     files for details.

        #pragma codepage 2  // locate following functions
        #pragma location 2  // locate functions prototypes also


  6. Computed goto is very efficient for implementing a multi-
     selection (instead of using the switch or multiple if
     statements). Many examples of how to do this is found in
     'Application Notes' in the User's Manual.


  7. The smallest possible variables should be used. Variables of 1
     and 8 bit are efficient. Also, some operations on signed
     variables requires more code compared to using unsigned
     variables.


SOME REGISTER ARE VOLATILE
--------------------------

  Note that RAM and special purpose registers are treated
  different. Most special purpose registers are volatile. That is,
  the compiler assumes that the contents may have changed between
  each register access. Optimization will therefore be different.


SOME CODE GENERATION NOTES:
---------------------------

  The compiler has some powerful features which may be confusing
  when the assembly file is examined:

    1) Peephole optimization: can be switched off with the '-u'
       command line option

    2) Extended call level: CALL's are replaced by GOTO's in some
       cases, and therefore the call level can be extended beyond
       the 2 or 8 levels offered by the PIC16 family. Option '-g'
       switch this off.

    3) Overlapping local variables: The compiler calculates a
       safe mapping to global addresses based on the variable
       scope, global optimized.

    4) Global optimization when updating the bank selection bits,
       RP0+1 and FSR.5+6. The contents of these bits can be
       difficult to trace because the compiler removes nearly all
       unnessesary updating.

    5) The switch test constants will be different from the
       constants in the source file because the W register is
       modified through a series of XORLW instructions.

  If the code looks wrong, think twice. The advanced optimization
  is sometimes difficult to understand.



PROGRAMMING PRECAUTIONS:
------------------------

  1. The page selection bits (PA0,PA1) are automatically updated
     by the compiler, and attempts to set or clear these bits in
     the source code are removed by the optimizer. This process
     may be switched off. PIC16C5X Warning: assigning a value to
     the status register (f3) may cause the automatic updating to
     fail.

  2. The bank selection bits (FSR.5/6 + RP0/RP1) are checked and
     updated by the compiler. Attempts to set or clear these bits
     in the source code are removed by the optimizer. This process
     may be switched off, local or global.

  3. Note that global variabeles are NOT initialized. The function
     clearRAM() can be used to clear ALL RAM locations (at startup).



MAIN COMPILER VERSIONS:
-----------------------

  April    1992 :  Version 1.0 released
  January  1994 :  Version 1.1 released
  June     1995 :  Version 2.0 released
  February 1996 :  Version 2.1 released
  May      1999 :  Version 3.0 released
  October  2000 :  Version 3.1 released
  January  2004 :  Version 3.2 released



WRITING CODE THAT CAN BE COMPILED BY CC5X
-----------------------------------------

  CC5X is not a full C compiler. There are restrictions to be aware
  of. The main problem is that CC5X has limited ability to allocate
  temporary variables. Because of this, complex statements often
  have to be rewritten using simpler statements. This is most
  notisable when using variables of 16 bit or larger. There is an
  advantage of such rewriting. Often the generated hex code gets
  more compact.


  MODIFIED SAMPLE:

    uns16 array[10], temp, temp2;
    char j, k;

    //if(array[j] > array[j+1])
    //{
    //    temp = array[j];
    //    array[j] = array[j+1];
    //    array[j+1] = temp;
    //}

    temp = array[j];
    k = j+1;
    temp2 = array[k];
    if(temp > temp2)
    {
        array[j] = temp2;
        array[k] = temp;
    }


  MODIFIED SAMPLE:

    #pragma chip PIC16F877
    #include "math32f.h"
    #include "math32lb.h"

    void main( void)
    {
        double X, input;
        #define Const 22.94

        //X = exp( ( Const / input ) + ( Const * log(input) ) );
        X = log(input) * Const;
        X = exp( Const/input + X );
    }


  MODIFIED SAMPLE:
    //if (x++ < 20) { /* .. */ }
    if (x < 20) { x++;  /* .. */ }
    if (++x < 20) { /* .. */ }  // ok


  MODIFIED SAMPLE:

    unsigned long checksum;
    unsigned char c;
    unsigned long calc(unsigned long c);
    //checksum = calc(c^checksum) ^ (checksum/256);
    unsigned long tmp = calc(c^checksum);
    checksum /= 256;
    checksum ^= tmp;


  MODIFIED SAMPLE:

    //rx_str[ptr2] = rx_str[ptr1];
    char tmp = rx_str[ptr1];
    rx_str[ptr2] = tmp;


  MODIFIED SAMPLE:

    // if (c = TestOptions(0x00c6)) { /* .. */ }
    c = TestOptions(0x00c6);
    if (c) { /* .. */ }


  MODIFIED SAMPLE:

    //if (!((1<<(rx_str[ptr1]-1))&option)) { /* .. */ }
    unsigned char xtmp = rx_str[ptr1] - 1;
    unsigned long tmp = (unsigned long)1 << xtmp;
    tmp &= option;
    if (!tmp) { /* .. */ }


  MODIFIED SAMPLE:

    unsigned long packet;
    //packet = rx_str[2]*256 + rx_str[3];
    packet.high8 = rx_str[2];
    packet.low8 = rx_str[3];


  MODIFIED SAMPLE:

    unsigned long length;
    //length = 0x45 + 0x88 + 0x40 + 127 + addr1 + addr3 + str[1] + str[3];
    length = (unsigned long) 0x45 + 0x88 + 0x40 + 127 + addr1;
    length += addr3;
    length += str[1];
    length += str[3];

    //length = (length & 255) + packet / 256;
    length &= 255;
    length += packet.high8;

