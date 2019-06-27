#include "mte220.c"  // C functions needed for labs

/*
;**********************************************************************
;
;    Filename:	    labhall.c
;    Date:          Nov 12/05
;    File Version:  2.0
;
;    Author:        C.C.W. Hulls & D.L. Wight
;
;    Copyright (c) C.C.W. Hulls, P.Eng and D.L. Wight, 2005.
;    This software can be used and modified by students, staff and
;    faculty members at the University of Waterloo for teaching or
;    research purposes, provided the authors are acknowledged.
;
;**********************************************************************
;
;    Files required:
;
;**********************************************************************
;
;    History:
;
;    2.0  Nov 12/05  ported to C
;
;    1.0  Oct 10/05  original release
;
;**********************************************************************
;**********************************************************************
;
;    Description:
;
;   The labhall code reads the Hall effect sensor ADC.  The duty cycle of
;   the LED is set based on the value.
;
;**********************************************************************
*/

//;**********************************************************************
void main(void)
{
    uns8 analog_value;  // current ADC value

    Initialization();

    while (1)  // loop forever
    {
        // get analog value from the Hall effect sensor
        analog_value = AnalogConvert(ADC_HALL_EFFECT);

        // Turn on LED for fraction of time corresponding to analog value
        OnLED
        Delay(analog_value);

        // Turn off LED
        OffLED
        analog_value = 255 - analog_value;
        Delay(analog_value);
    }
}
