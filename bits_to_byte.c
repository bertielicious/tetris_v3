#include <xc.h>
#include<pic.h>
#include "send_no_op_spi_byte.h"
#include "send_spi_byte.h"
#include <stdbool.h>
#include "config.h"
void bits_to_byte(uchar *upper, uchar *lower)
{
    char row, col, factor, byte1, byte2 = 0x00;
                   
    for (row = 0; row < 8; row++)   // converts bits to byte for rows 0 to 7 of upper and lower LED matrix display
    {
        factor = 0x80;              // initialise factor to 0x80 (128) aka 2 to the power of 7
        byte1 = 0x00;                   // clear values stored from previous row calculation
        byte2 = 0x00;
        for (col = 0; col < 8; col++)   // calculate byte1 and byte2 for a single row
        {   
            byte1 = (*upper * factor) + byte1;      // calculate row bits to byte for upper matrix
            byte2 = (*lower * factor) + byte2;      // calculate row bits to byte for lower matrix
            factor = factor >> 1;                   // divide factor by 2 on every iteration of col loop
            lower++;
            upper++;     
        }
        
        CS = 0;
        send_no_op_spi_byte();
        send_spi_byte(row + 1, byte1);
        CS = 1;
        CS = 0;
        send_spi_byte(row + 1, byte2);
        send_no_op_spi_byte();
        CS = 1;             
    } 
    
}
