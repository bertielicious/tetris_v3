#include <pic.h>
#include "send_no_op_spi_byte.h"
void send_no_op_spi_byte (void)
{
 SSPBUF = 0x00; // send 8 bit address MSB first
 while (!SSPSTATbits.BF) // wait for 8 bits address data to transmit/ complete
    {
        ; // do nothing
    }
 SSPBUF = 0x00; // send 8 bit data MSB first
 while (!SSPSTATbits.BF) // wait for 8 bits data / transmit complete
    {
        ; // do nothing
    }
 }
