#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
void configTimer1(void)
{
    TMR1H = 0x00;           // preload TMR1 to generate a 0.5sec interrupt
    TMR1L = 0x00;           // max count  (asumes 4MHz clock)
    T1CONbits.T1CKPS0 = 1;  // 1:8 prescale
    T1CONbits.T1CKPS1 = 1;
    PIE1bits.TMR1IE = 1;    // TMR1 interrupts are enabled
    INTCONbits.PEIE = 1;    // Peripheral interrupts are enabled
    INTCONbits.GIE = 1;     // Global interrupts are enabled
    
    T1GCONbits.TMR1GE = 0.;
    T1CONbits.TMR1CS1 = 0;
    T1CONbits.TMR1CS0 = 0;
    PIR1bits.TMR1IF = 0;    // clear TMR1 interupt flag to enable counting
    T1CONbits.TMR1ON = 1;   // start TMR1 counting
}
