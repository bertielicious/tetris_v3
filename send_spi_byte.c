#include <pic.h>
#include "send_spi_byte.h"
void send_spi_byte(char addr, char data)
{
 SSPBUF = addr; // send 8 bit address MSB first
 
 while (!SSPSTATbits.BF) // wait for 8 bits address data to transmit/ complete
    {
        ; // do nothing
    }
 SSPBUF = data; // send 8 bit data MSB second
 
 while (!SSPSTATbits.BF) // wait for 8 bits data / transmit complete
    {
        ; // do nothing
    }
 }
