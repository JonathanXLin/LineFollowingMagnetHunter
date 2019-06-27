// SIZE & SPEED

#pragma library 1
/*
uns16 operator* _multM8_8( uns8 arg1, char W);
uns16 operator* _multM16_16( uns16 arg1, uns16 arg2);
*/

int8 operator*( int8 arg1, int8 arg2) @

uns16 operator* _multM8_8( uns8 arg1, char W)
{
    uns16 rval = 0;
    Carry = 0;
   #define addRR(rval,arg,bit) if(arg&((uns8)1<<bit)) rval.high8+=W; rval=rr(rval);
    addRR( rval, arg1, 0);
    addRR( rval, arg1, 1);
    addRR( rval, arg1, 2);
    addRR( rval, arg1, 3);
    addRR( rval, arg1, 4);
    addRR( rval, arg1, 5);
    addRR( rval, arg1, 6);
    addRR( rval, arg1, 7);
   #undef addRR
    return rval;
}



int16 operator*( int16 arg1, int16 arg2) @

uns16 operator* _multM16_16( uns16 arg1, uns16 arg2)
{
    uns16 rval;
    rval = (uns16) arg1.low8 * arg2.low8;
    W = arg1.high8;
    if (W)
        rval.high8 += W * arg2.low8;
    W = arg2.high8;
    if (W)
        rval.high8 += W * arg1.low8;
    return rval;
}

#pragma library 0
