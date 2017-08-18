#include "config.h"
#include "send_no_op_spi_byte.h"
#include "send_spi_byte.h"
void clear_game_play_area (void)
{
    unsigned char row;
    for (row = 1; row < 9; row++)   // for rows 1 to 8
    {
        CS = 0;
        send_no_op_spi_byte();      // write to top matrix
        send_spi_byte(row, 0x00);   // clear the row of leds
        CS = 1;
        
        CS = 0;
        send_spi_byte(row, 0x00);   // write to bottom matrix
        send_no_op_spi_byte();      // clear the row of leds
        CS = 1;  
    }
    
}
