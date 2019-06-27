// *************************************************
// 24 bit floating point math functions
// Copyright (c) B Knudsen Data, Norway, 2000 - 2005
// *************************************************

#pragma library 1
/* PROTOTYPES for page definition in application header file:
float24 log( float24 arg1f24);
float24 log10( float24 arg1f24);
float24 exp10( float24 arg1f24);
float24 exp( float24 arg1f24);
float24 cos( float24 arg1f24);
float24 sin( float24 arg1f24);
float24 sqrt( float24 arg1f24);
*/

#ifndef FpFlags_defined
 #error The basic 24 bit floating point math library must be included first
#endif

#if __CoreSet__ / 100 == 12
 #error Math functions (exp,log,..) are not adapted to 12 bit core devices
#endif

float24 log( sharedM float24 arg1f24)
{
    sharedM float24 arg2f24;

    if (arg1f24.mid8 & 0x80)  //  test for negative argument
        goto DOMERR32;
    if (!arg1f24.high8)   //  test for zero argument
        goto DOMERR32;

    char savedFlags = FpFlags;   //  save rounding flag
    FpFlags |= 0x40;  //  enable rounding

    char xexp = arg1f24.high8 - (FpBIAS-1);
    arg1f24.high8 = FpBIAS-1;

    arg2f24 = 1.0;

    //  .70710678118655 = 7E3504F3
    W = arg1f24.low8 - 0x05;
    W = 0x35;
    if (!Carry)
        W = 0x35+1;
    W = arg1f24.mid8 - W;

    if (Carry)
        arg1f24 -= arg2f24;
    else  {
        arg1f24.high8 += 1;  /* arg1f24 *= 2; */
        arg1f24 -= arg2f24;
        xexp -= 1;
    }

    float24 d = arg1f24;  //  save z

    // POLL132  LOG32Q,2,0  ; Q(z)
    arg1f24 += 0.33339502905E+1; /* LOG32Q1 */
    arg1f24 *= d;
    arg1f24 += 0.24993759223E1;  /* LOG32Q0 */
    float24 c = arg1f24;

     //   minimax rational approximation  z-.5*z*z+z*(z*z*P(z)/Q(z))
    // POL32  LOG32P,1,0  ; P(z)
    arg1f24 = d;
    arg1f24 *= 0.48646956294; /* LOG32P1 */
    arg1f24 += 0.83311400452; /* LOG32P0 */

    c = arg1f24 / c;   //  P(z)/Q(z)

    arg1f24.high8 = d.high8;
    arg2f24.high8 = d.high8;
    arg1f24.mid8 = d.mid8;
    arg2f24.mid8 = d.mid8;
    arg1f24.low8 = d.low8;
    arg2f24.low8 = d.low8;
    arg1f24 *= arg2f24;       // z * z;

    float24 e = arg1f24;
    arg1f24 *= c;          //  z*z*P(z)/Q(z)
    arg1f24 *= d;          //  z*(z*z*P(z)/Q(z))

    arg2f24 = e;
    if (arg2f24.high8)
        arg2f24.high8 --;  // arg2f24 *= 0.5;
    arg1f24 -= arg2f24;       //  -.5*z*z + z*(z*z*P(z)/Q(z))
    arg1f24 += d;          //  z -.5*z*z + z*(z*z*P(z)/Q(z))

    if (!xexp)
        goto RETURN;

    e = arg1f24;  //  save

    // integer to floating point conversion
    arg1f24 = (int8) xexp;

    d = arg1f24;  //  save k

    arg1f24 *= -0.000212194440055;

    arg1f24 += e;   //  log(1+z) + k*log(2)

    e = arg1f24;  //  save

    arg1f24 = d * 0.693359375;

    arg1f24 += e;      //  log(1+z) + k*log(2)

    if (!(savedFlags & 0x40))
        FpFlags &= ~0x40;   //  restore rounding flag
    goto RETURN;

  DOMERR32:
    FpDomainError = 1;   //  domain error

  RETURN:
    return arg1f24;
}



float24 log10( sharedM float24 arg1f24)
{
    sharedM float24 arg2f24;      // allocation 'trick'

    char flags = FpFlags;
    FpFlags |= 0x40;

    arg1f24 = log( arg1f24);

    arg1f24 *= 0.43429448190325;  //  log10(e);

    if (!(flags & 0x40))
        FpFlags &= ~0x40;

    return arg1f24;
}



char floorMaskTable24( char i)
{
    if (i & 4)  {
        if (i & 2)  {
            if (i & 1)
                return 128;
            return 192;
        }
        if (i & 1)
            return 224;
        return 240;
    }
    if (i & 2)  {
        if (i & 1)
            return 248;
        return 252;
    }
    if (i & 1)
        return 254;
    return 255;
}

float24 floor24( sharedM float24 arg1f24)
{
    if (!arg1f24.high8)
        goto RETURN;

    uns16 ma = arg1f24.low16;  //  save mantissa

    W = arg1f24.high8 - 127;
    char tmp = W;
    if (tmp & 0x80)
        goto FLOOR24ZERO;

    //  save number of zero bits
    W = 15 - W;

    char tmpa = W;
    tmp = W;

    if (tmp & 0x8)  // LSB+3		; divide by eight
        goto FLOOR24MASKH;


    W = floorMaskTable24( tmpa);    //  get mask
    arg1f24.low8 &= W;
    if (!(arg1f24.mid8 & 0x80))  //  if negative, round down
        goto RETURN;

    char arg1B7 = W;
    if (!(arg1f24.low8 - ma.low8))
        goto RETURN;

    tmp = ~arg1B7;
    arg1f24.low8 += tmp + 1;
    if (Zero_)
        arg1f24.mid8 += 1;

    //  has rounding caused carryout?
    if (!Zero_)
        goto RETURN;
    arg1f24.mid8 = rr( arg1f24.mid8);
    arg1f24.low8 = rr( arg1f24.low8);

    //  check for overflow
    arg1f24.high8 = incsz( arg1f24.high8);
    goto RETURN;
    goto OVERFLOW;


  FLOOR24MASKH:
    W = floorMaskTable24( tmpa);  //  get mask
    arg1f24.mid8 &= W;
    arg1f24.low8 = 0;

    //  if negative, round down
    if (!(arg1f24.mid8 & 0x80))
        goto RETURN;

    arg1B7 = W;
    if (( arg1f24.low8 - ma.low8) != 0)
        goto FLOOR24RNDH;
    if (!(arg1f24.mid8 - ma.mid8))
        goto RETURN;

  FLOOR24RNDH:
    tmp = ~arg1B7;
    arg1f24.mid8 += tmp + 1;

    //  has rounding caused carryout?
    if (!Carry)
        goto RETURN;
    arg1f24.mid8 = rr( arg1f24.mid8);
    arg1f24.low8 = rr( arg1f24.low8);

    //  check for overflow
    arg1f24.high8 = incsz( arg1f24.high8);
    goto RETURN;
    goto OVERFLOW;


  FLOOR24ZERO:
    if (!(arg1f24.mid8 & 0x80))
        goto RES0;
    return -1.0;

  RES0:
    W = 0;
    goto ASSIGNW;

  OVERFLOW:
    FpOverflow = 1;
    W = 0xFF;
  ASSIGNW:
    arg1f24.low8 = W;
    arg1f24.mid8 = W;
    arg1f24.high8 = W;

  RETURN:
    return arg1f24;
}



float24 exp10( sharedM float24 arg1f24)
{
    sharedM float24 arg2f24;      // allocation 'trick'
    float24 c, d;
    char xexp;

    if (( arg1f24.high8 - 100) & 0x80)
        goto EXP1;   //  return e**x = 1

    W = 132 - arg1f24.high8;
    if (!Carry)
        goto DOMERR;
    if (!Zero_)
        goto ARGOK;

    if (!(arg1f24.mid8 & 0x80))  {
        //  positive domain check
        W = 26 - arg1f24.mid8;
        if (!Carry)
            goto DOMERR;
        if (!Zero_)
            goto ARGOK;

        W = 33 - arg1f24.low8;
        if (!Carry)
            goto DOMERR;
    }
    else  {

        W = 151 - arg1f24.mid8;
        if (!Carry)
            goto DOMERR;
        if (!Zero_)
            goto ARGOK;

        W = 184 - arg1f24.low8;
        if (!Carry)
            goto DOMERR;
    }

  ARGOK:

    char savedFlags = FpFlags;
    FpFlags |= 0x40;  //  enable rounding

    c = arg1f24;  //  save x
    arg1f24 *= 3.32192809489;  //  1/log10(2) = 3.32192809489
    arg1f24 += 0.5;  //  k = [ x / log10(2) + .5 ]
    arg1f24 = floor24( arg1f24);

    float24 e = arg1f24; //  save float k
    FpFlags &= ~0x40;
    //floating point to integer conversion
    xexp = arg1f24; //  k = [ x / ln(2) + .5 ]
    FpFlags |= 0x40;
    arg1f24 = e * -0.30078125; //  c1
    d = arg1f24 + c;
    arg1f24 = e * -2.487456637421670e-04;  // c2
    arg1f24 += d;
    d = arg1f24;  //  save f

    if (!(d.mid8 & 0x80))  {
        // POL32  EXP1032H,5,4   ; minimax approximation on [0,log10(2)/2]
        arg1f24 *= 6.388992868121E-1;/* EXP1032H5 */
        arg1f24 += 1.154596329197E0; /* EXP1032H4 */
        arg1f24 *= d;
        arg1f24 += 2.035920309947E0; /* EXP1032H3 */
        arg1f24 *= d;
        arg1f24 += 2.650909138708E0; /* EXP1032H2 */
        arg1f24 *= d;
        arg1f24 += 2.302585504840E0; /* EXP1032H1 */
    }
    else  {
        // POL32 EXP1032L,5,4  ; minimax approximation on [-log10(2)/2,0]
        arg1f24 *= 4.544952589676E-1;/* EXP1032L5 */
        arg1f24 += 1.157459289066E0; /* EXP1032L4 */
        arg1f24 *= d;
        arg1f24 += 2.033640565225E0; /* EXP1032L3 */
        arg1f24 *= d;
        arg1f24 += 2.650914554552E0; /* EXP1032L2 */
        arg1f24 *= d;
        arg1f24 += 2.302584716116E0; /* EXP1032L1 */
    }
    arg1f24 *= d;
    if (!(savedFlags & 0x40))
        FpFlags &= ~0x40;
    arg1f24 += 1.0; /* EXP1032H0/EXP1032L0 */

    arg1f24.high8 += xexp;
    goto RETURN;

  EXP1:
    arg1f24 = 1.0;   //  return 10**x = 1.0
    goto RETURN;

  DOMERR:
    FpDomainError = 1;   //  domain error

  RETURN:
    return arg1f24;
}



float24 exp( sharedM float24 arg1f24)
//     Maximum argument : 88.7228391117 = log(2**128)
//     Minimum argument : -87.3365447506 = log(2**-126)
{
    sharedM float24 arg2f24;
    float24 c, d;
    char xexp;

    if (( arg1f24.high8 - 94) & 0x80)
        goto EXP1;   //  return e**x = 1

    W = 133 - arg1f24.high8;
    if (!Carry)
        goto DOMERR;
    if (!Zero_)
        goto ARGOK;

    if (!(arg1f24.mid8 & 0x80))  {

        W = 49 - arg1f24.mid8;
        if (!Carry)
            goto DOMERR;
        if (!Zero_)
            goto ARGOK;

        W = 114 - arg1f24.midL8;
        if (!Carry)
            goto DOMERR;
    }
    else {

        W = 174 - arg1f24.mid8;
        if (!Carry)
            goto DOMERR;
        if (!Zero_)
            goto ARGOK;

        W = 172 - arg1f24.midL8;
        if (!Carry)
            goto DOMERR;
    }

  ARGOK:

    char savedFlags = FpFlags;
    FpFlags |= 0x40;  //  enable rounding

    c = arg1f24;  //  save x
    arg1f24 *= 1.44269504089;
    arg1f24 += 0.5; //  k = [ x / ln(2) + .5 ]
    arg1f24 = floor24( arg1f24);

    float24 e = arg1f24;
    xexp = arg1f24;   //  k = [ x / ln(2) + .5 ]
    arg1f24 = e * -0.69140625; // c1
    d = arg1f24 + c;
    arg1f24 = e * -1.740930559945286e-03;  // c2
    arg1f24 += d;
    d = arg1f24;  //  save f

    if (!(d.mid8 & 0x80))  {
        // POL32   EXP32H,5,0
        arg1f24 *= 0.989943653774E-2; /* EXP32H5 */
        arg1f24 += 0.410473706887E-1; /* EXP32H4 */
        arg1f24 *= d;
        arg1f24 += 0.166777360103;    /* EXP32H3 */
        arg1f24 *= d;
        arg1f24 += 0.499991163105;    /* EXP32H2 */
        arg1f24 *= d;
        arg1f24 += 1.00000025499;     /* EXP32H1 */
    }
    else  {
        // POL32   EXP32L,5,0
        arg1f24 *= 0.699995870637E-2; /* EXP32L5 */
        arg1f24 += 0.411548782678E-1; /* EXP32L4 */
        arg1f24 *= d;
        arg1f24 += 0.166574299807;    /* EXP32L3 */
        arg1f24 *= d;
        arg1f24 += 0.499992371926;    /* EXP32L2 */
        arg1f24 *= d;
        arg1f24 += 0.999999766814;    /* EXP32L1 */
    }
    arg1f24 *= d;
    arg1f24 += 1.0;   /* EXP32H0 or EXP32L0 */
    arg1f24.high8 += xexp;

    if (!(savedFlags & 0x40))
        FpFlags &= ~0x40;   //  restore rounding flag
    goto RETURN;

  EXP1:
    arg1f24 = 1.0;   //  return 10**x = 1.0
    goto RETURN;

  DOMERR:
    FpDomainError = 1;   //  domain error

  RETURN:
    return arg1f24;
}






float24 cosin24( sharedM float24 arg1f24, sharedM float24 arg2f24, char cosinus)
{
    float24 c, d;
    char j;

    char savedFlags = FpFlags;  //  save rounding flag
    FpFlags |= 0x40;  //  enable rounding

    char csign = 0;    //  initialize sign

    if (!cosinus  &&  (arg1f24.mid8 & 0x80))
        csign |= 0x80;

    arg1f24.mid8 &= ~0x80;  //  use |x|

    //  loss threshold check
    // arg1f24 <= +512.0
    // arg1f24 >= -512.0
    if (arg1f24.high8 >= 0x88)
        FpDomainError = 1;   //  domain error

    c = arg1f24;  //  save |x|

    // fixed point multiplication by 4/pi
    arg1f24 *= 1.27323954474;   // 4/pi

    FpFlags &= ~0x40;

    //  y = [ |x| * (4/pi) ]
    arg1f24.low16 = arg1f24;  // floating point to integer conversion

    FpFlags |= 0x40;

    if (arg1f24.low8 & 0x1)
        arg1f24.low16 += 1;  // make arg1f24 even

    //  j = y mod 8
    j = arg1f24.low8 & 7;  // 0,2,4,6
    if (j >= 4)  {
        csign ^= 128;
        j -= 4;
    }

    arg1f24 = arg1f24.low16;  // integer to floating point conversion

    //  save y in DARG
    d.high8 = arg1f24.high8;
    if (Zero_)
        goto ZEQX;
    d.low16 = arg1f24.low16;

    arg1f24 *= -7.851562500000000e-01;
    c = arg1f24 + c;    //  z1 = |x| - y * (p1)
    arg1f24 = d * -2.419133974475018e-04;
    arg1f24 += c;

    //  save z in c
    c.high8 = arg1f24.high8;
    arg2f24.high8 = arg1f24.high8;
    c.mid8 = arg1f24.mid8;
    arg2f24.mid8 = arg1f24.mid8;
    c.low8 = arg1f24.low8;
    arg2f24.low8 = arg1f24.low8;

    goto POLYNOM;

   ZEQX:
    arg1f24.high8 = c.high8;
    arg2f24.high8 = c.high8;
    arg1f24.mid8 = c.mid8;
    arg2f24.mid8 = c.mid8;
    arg1f24.low8 = c.low8;
    arg2f24.low8 = c.low8;

   POLYNOM:



    arg1f24 *= arg2f24;   // z * z
    d = arg1f24;   //  save z * z

    if ((( rr( j) ^ j) & 0x1) ^ cosinus)  {
        // POL24  COS24,3,0

        arg1f24 *= -1.35859090e-03;  // 117,178,18,191
        arg1f24 += 4.16550264e-02;   // 122,42,158,118
        arg1f24 *= d;
        arg1f24 += -4.99998569e-01;  // 125,255,255,208
        arg1f24 *= d;
        arg1f24 += 1.0;
    }
    else  {
        /// POL24  SIN24,2,0
        arg1f24 *= 8.12155753e-03;   // 120,5,16,72
        arg1f24 += -1.66601613e-01;  // 124,170,153,157
        arg1f24 *= d;
        arg1f24 += 9.99994993e-01;   // 126,127,255,172
        arg1f24 *= c;
    }

    W = 128;  // LSB+1
    if (cosinus  &&  (j & 0x2))
        csign ^= W;
    if (csign & 0x80)
        arg1f24.mid8 ^= W;

    if (savedFlags & 0x40)
        FpFlags |= 0x40;  //  restore rounding flag
    return arg1f24;
}


float24 cos( sharedM float24 arg1f24)
{
    sharedM float24 arg2f24;      // allocation 'trick'
    arg1f24 = cosin24( arg1f24, arg2f24, 1);
    return arg1f24;
}


float24 sin( sharedM float24 arg1f24)
{
    sharedM float24 arg2f24;      // allocation 'trick'
    arg1f24 = cosin24( arg1f24, arg2f24, 0);
    return arg1f24;
}



float24 sqrt( sharedM float24 arg1f24)
{
    sharedM float24 arg2f24;      // allocation 'trick'

    if (arg1f24.mid8 & 0x80)     // test for negative argument
        goto DOMERR;
    if (!arg1f24.high8)          // return if argument zero
        goto RETURN;

    char cexp = arg1f24.high8;    // save exponent
    char savedFLAGS = FpFlags;
    FpFlags |= 0x40;           // enable rounding

    arg1f24.high8 = FpBIAS;   // compute z
    float24 d = arg1f24;

    if (arg1f24.mid8 & 0x40)  {
        // POL24  SQRT24H,4,0
        arg1f24 *= -5.6351436252E-3;  // SQRT24H4
        arg1f24 += 5.5047377031E-2; // SQRT24H3
        arg1f24 *= d;
        arg1f24 += -2.3944355047E-1;  // SQRT24H2
        arg1f24 *= d;
        arg1f24 += 8.3106978456E-1; // SQRT24H1
        arg1f24 *= d;
        arg1f24 += 3.5963132863E-1;  // SQRT24H0
    }
    else  {
        // POL24  SQRT24L,4,0
        arg1f24 *= -1.8702682470E-2;  // SQRT24L4
        arg1f24 += 1.3009144111E-1; // SQRT24L3
        arg1f24 *= d;
        arg1f24 += -4.0192034196E-1;  // SQRT24L2
        arg1f24 *= d;
        arg1f24 += 9.8831235597E-1;  // SQRT24L1
        arg1f24 *= d;
        arg1f24 += 3.0221977303E-1;  // SQRT24L0
    }

    if (!(cexp & 0x1))      // is cexp even or odd?
        arg1f24 *= 1.41421356237;  // sqrt(2)

    // divide exponent by two
    cexp += 127;
    arg1f24.high8 = rr( cexp);

    if (!(savedFLAGS & 0x40))
        FpFlags &= ~0x40;

    goto RETURN;

  DOMERR:
    FpDomainError = 1;   //  domain error

  RETURN:
    return arg1f24;
}

#pragma library 0
