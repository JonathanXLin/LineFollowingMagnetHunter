// OPTIONS FILE
// included on command line:   cc5x <options> +op.inc <options>

-L80,60 -Vn       // spaces, TAB or linefeed separate each option
test\sample1.c    // source file

// the rest of the line after '//' is a comment in an "options file"

+opi.inc   // more options: 5 levels of nested files is allowed

// Adding a space behind the first '-' allows more spaces to be inserted
// to enhance readability. But, this requires that the next option is
// separated by a line feed.

- L 80, 60       // a space after first '-' allows more spaces to be inserted
- L 80, 60  -Vn  // this will NOT work!

- V n            // variable file, sorted by name
- A t 6+6+6
- pPIC16C54
- fINHX8M
- D MM = (300 - 400)  // equivalent to  #define MM (300-400)


// String translation rules for options in a file:
//  1. Doublequotes " " allows spaces in the option, quotes are removed
//  2. Using \" means a single quote " in an option

-I"C:\Program Files\cc5x"     //  ==>  -IC:\Program Files\cc5x
-IC:"\Program Files"\cc5x     //  ==>  -IC:\Program Files\cc5x

-DMyString="\"Hello\n\""      //  ==>  -DMyString="Hello\n"
-DQuote='\\"'                 //  ==>  -DQuote='\"'
