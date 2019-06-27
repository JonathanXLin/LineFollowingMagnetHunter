-r2
-x"C:\Program Files\Microchip\MPASM Suite\mpasmwin.exe"
-X/o -X/q

// Alternatives:
// -xC:\progra~1\microc~1\mpasms~1\mpasmwin.exe    // short format (MSDOS)
// -xC:\progra~1\mplab\mpasm.exe                   // old mpasm.exe

// These CC5X command line options starts MPASM from inside the
// compiler to generate an object module for linking by MPLINK.
// The path to the assembler (mpasmwin) may have to be changed if
// MPLAB/MPASM is installed in another directory.

// This file is included by using the option: +reloc.inc

// -r2[<file.lkr>]    // generate relocatable assembly + partial script
// -r                 // generate relocatable assembly

// -X/o  // generate object module for linking
// -X/q  // silent operation of MPASM
