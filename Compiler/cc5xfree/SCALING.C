/*
  16 BIT LINEAR SCALING ROUTINE
  =============================

   Copyright (c) B. Knudsen Data, 2000. This code can be used in any
   application at the responsibility of the application designer.
   Any publishing of this code requires dedicated permission.

  16 bit linear scaling routine:  y = K * x;

  NOTE: Requires that 'y' ranges from 0 .. 2^N-1 (N = 9..16),
        that is 0..0x1FF (or 0x3FF, 0x7FF, .. 0xFFFF).

  Example:  A number ranging from 0..14999 is transformed to
  a number ranging from 0..0x1FFF (8191). Then:

      y = (8192/15000) * x = 0.546133 * x;

  The scaling routine performs the equivalent of floating point
  multiplication, fast and using few instructions (only 29).

  Timing: Maximum 8+N*26  (=424 for N=16) Instruction Cycles
          Typical 250-350 Instruction Cycles

  ScalingMax is the upper limit of 'x'. The result value ('y') can
  be smaller or greater than ScalingMax. If 'x' is equal to
  ScalingMax, then all result bits will be 1's.
*/


#define ScalingMax  15000  // can optionally be a 16 bit variable
#define ScalingBits 13     // number of bits in scaledValue (9..16)

uns16 value;   // input value, contains the remainder after scaling
uns16 scaledValue;   // new value

/* Note that when 'y' is 8 bits or lower, then the type of
   'scaledValue' can be changed to 'uns8' */


void scaling( void)
{
    char i = ScalingBits;
    scaledValue = 0;
    Carry = 0;
    do  {
        value = rl( value);  // shift in 0

       #if ScalingMax >= 0x8000
        if ( Carry)
           goto SUBTRACT;
       #endif

        if ( value >= ScalingMax)  {
          SUBTRACT:
            value -= ScalingMax;
            Carry = 1;
        }
        // else Carry = 0;  // ok
        scaledValue = rl( scaledValue);  // shift in 0 or 1

    } while ( --i > 0);
}


// EXAMPLE :

void main( void)
{
    value = 1000;
    scaling();
    // scaledValue is then : 1000 * (8192 / 15000) = 546
}
