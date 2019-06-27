/*
  DELAYS AND TIMING
  =================

  Delays are frequently used. There are various
  ways to generate them:
     1. Instruction cycle counting
     2. Using the TMR0 timer
     3. Watchdog timeout for low power consumption
     4. Using variables achieves longer delays
*/


void delay_ms( uns16 millisec)
// Delays a multiple of 1 milliseconds at 4 MHz
// using the TMR0 timer
{
    char next = 0;

    OPTION = 2; // prescaler divide TMR0 rate by 8
    TMR0 = 2;  // deduct 2*8 fixed instruction cycles delay
    do  {
        next += 125;
        clrwdt();  // needed only if watchdog is enabled
        while (TMR0 != next)   // 125 * 8 = 1000 (= 1 ms)
            ;
    } while ( -- millisec != 0);
}


void delay10( char n)
/*
  Delays a multiple of 10 milliseconds using the TMR0 timer
  Clock : 4 MHz   => period T = 0.25 microseconds
  1 IS = 1 Instruction Cycle = 1 microsecond
  error: 0.16 percent
*/
{
    char i;

    OPTION = 7;
    do  {
        clrwdt();  // only if watchdog enabled
        i = TMR0 + 39; /* 256 microsec * 39 = 10 ms */
        while ( i != TMR0)
            ;
    } while ( --n > 0);
}


void _delay10( char x)
/*
  Delays a multiple of 10 milliseconds
   using instruction cycle counting
  Clock : 32768 Hz   => period T = 30.518 microseconds
  1 Instruction Cycle = 1 IS = 4 * T = 122 microseconds
  10 ms = 82 IS (81.92) =>  error: 0.1 percent
*/
{
    do  {
        char i = 26;            /* 2 IS */
        do ; while ( --i > 0);  /* 26 * 3 - 1 = 77 IS */
    } while ( --x > 0);         /* 3 IS */
}



char counter;

void main( void)
{
    if ( TO == 1)  {
        /* power up or MCLR */
        PORTA = 0;     /* write output latch first */
        TRISA = 0;     /* all outputs */
        TRISB = 0xFF;  /* all inputs */
    }
    else  {
        /* watchdog wakeup */
        if ( --counter > 0)  {
            OPTION = 0x0B; /* WDT divide by 16 */
            sleep();  /* waiting 16 * 18 ms =
                         288 ms = 0.288 seconds */
        }
    }

    // ..

    delay_ms( 5500);  /* 5.5 seconds */

    // ..

    delay10( 100);  /* 1 second */

    // ..

    counter = 7;   // 7 * 0.288 sec. = 2 sec. totally
    OPTION = 0x0B; // 0 1011: WDT divide by 16
    // main terminates by sleep();, allows low power consumption
    // waiting for watchdog timeout: approx. 16*18 ms = 288 ms
}

