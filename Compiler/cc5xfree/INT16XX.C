/*
  USING INTERRUPTS
  ================
*/

#pragma bit pin1 @ PORTA.1
#pragma bit pin2 @ PORTA.2

#include "int16CXX.H"

#pragma origin 4

interrupt int_server( void)
{
    int_save_registers    // W, STATUS (and PCLATH)

    if (T0IF)  {
        /* TMR0 overflow interrupt */
        TMR0 = -45;
        if (pin1 == 1)
            pin1 = 0;
        else
            pin1 = 1;
        T0IF = 0;  /* reset flag */
    }

    if (INTF)  {
        /* INT interrupt */
        INTF = 0;  /* reset flag */
    }

    if (RBIF)  {
        /* RB port change interrupt */
        W = PORTB; /* clear mismatch */
        RBIF = 0;  /* reset flag */
    }

   /*
     NOTE: GIE is AUTOMATICALLY cleared on interrupt entry and set
           to 1 on exit (by RETFIE). Setting GIE to 1 inside the
           interrupt service routine will cause nested interrupts
           if an interrupt is pending. Too deep nesting may crash
           the program !
   */

    int_restore_registers // W, STATUS (and PCLATH)
}



void main( void)
{
  #ifdef _16C71
    ADCON1 = bin(11); // PORT A is digital
  #endif
  #if defined _16F873 || defined _16F874 || defined _16F876 || defined _16F877
    ADCON1 = 0b0110; // PORT A is digital
  #endif
    PORTA = 0; //76543210
    TRISA =    0b11111001;

    OPTION = 0; /* prescaler divide by 2 */
    TMR0 = -45;  /* 45 * 2 = 90 periods */
    T0IE = 1;   /* enable TMR0 interrupt */
    GIE = 1;    /* interrupts allowed */


    while (1)  {  /* infinite loop */
        pin2 = 0;
        nop();
        nop();
        pin2 = 1;
    }
}
