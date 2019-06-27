#include "mte220.c"  // C functions needed for labs

/*
;**********************************************************************
;
;    Filename:	    lab1a.c
;    Date:          Sept15/07
;    File Version:  1.2
;
;**********************************************************************
;
;    Files required:
;
;**********************************************************************
;
;    History:
;    ver 1.2	Sept15/07	Added ";" after LongDelay command
;    ver 1.1	Aug 30/07	File released
;
;**********************************************************************
;
;    Description:
;
;  Once the button is pushed, this code will turn on both servos and
;  leave them on for about 2 seconds, then turn the motors off.
;
;**********************************************************************
*/

//;**********************************************************************
void main(void)
{
    Initialization();

    // both servos are turned on
    UseServos         // (syntax of "call" is correct without () or ;)

	OnLED
	LongDelay(8);
	OffLED
	LongDelay(8);

    while (1)
    {
        WaitForButton();  // wait until the button is pushed

        // turn on the servos
        BothServosOn

        // wait for 2 second
        LongDelay(16);

        // turn off servos
        BothServosOff
       
    }
}
