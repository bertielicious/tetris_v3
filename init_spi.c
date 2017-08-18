#include "config.h"
#include <pic.h>

void init_spi(void)
{
//***********************SSPCONbits****************************************
 SSPCONbits.SSPM = 0001; // SPI Master mode, clock = Fosc/4 = 1MHz
 SSPCONbits.CKP = 0; // idle state for clock is low
 SSPCONbits.SSPEN = 1; // enables seial port and configures SCK, SDO
 //and SDI pins as serial port pins
 SSPCONbits.SSPOV = 0; // no overflow allowed as we are in Master mode
 SSPCONbits.WCOL = 0; // no collision
//***********************SSPSTATbits****************************************
 SSPSTATbits.CKE = 1; // data transmitted on rising edge of clock
 SSPSTATbits.SMP = 1; // input data sampled at end of output data
 CS = 1; // Disable Chip Select
/**************************************************************************/
}
