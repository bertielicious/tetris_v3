#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
void init_TMR0 (void)
{
OPTION_REGbits.TMR0CS = 0;  // Fosc/4
OPTION_REGbits.PSA = 0; // prescaler assigned to TMR0
OPTION_REGbits.PS2 = 1; // 1:128 prescaler assigned to TMR0
OPTION_REGbits.PS1 = 1;
OPTION_REGbits.PS0 = 0;


INTCONbits.GIE = 1;     // global interrupts enabled
INTCONbits.PEIE = 1;
INTCONbits.T0IE = 1;
INTCONbits.T0IF = 0;
}