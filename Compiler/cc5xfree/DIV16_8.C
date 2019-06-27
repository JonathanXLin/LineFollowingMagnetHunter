/*
  DIVISION: 16 bit DIV 8 bit
  ==========================
  Requires only 97 Cycles (97 microsec. at 4 MHz) to divide a 16 bit
  number by a 8 bit number. Requires that the result is 8 bit. The
  division remainder is also available.
  Optimized for SPEED & SIZE.
*/

uns16 arg1;  // argument 1: 16 bit unsigned
uns8 arg2;   // argument 2: 8 bit unsigned
uns8 res;    // result    : 8 bit unsigned
uns8 rm;     // remainder : 8 bit unsigned


char uDiv16_8( void)
// res,rm = arg1 / arg2
// CYCLES: 11*8 + 10 - 1 = 97 + CALL & RETURN
// INSTRUCTIONS: 27
{
    if ( arg1.high8 >= arg2)
        return 0;   /* overflow or zero divide */
    char counter = 8;
    rm = arg1.high8;
    res = rl( arg1.low8);
    do  {
      LOOP:
        rm = rl( rm);
        W = arg2;
        if ( !Carry)  {
            W = rm - W;
            if (Carry)
                rm = W;
            res = rl( res);
            if ( -- counter == 0)
                return 1;
            goto LOOP;
        }
        rm -= W;
        Carry = 1;
        res = rl( res);
    } while ( -- counter > 0);
    return 1;  // OK
}



void main (void)
{
    arg1 = 2000;
    arg2  = 200;

    while ( arg1 > arg2) {
      if ( !uDiv16_8())
          nop();
      arg1 -= 11;
    }
}

