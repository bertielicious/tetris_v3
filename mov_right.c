#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
#include "bits_to_byte.h"
void mov_right(void)
{
    uchar temp_row[16];
    uchar row, col;
    if(RIGHT == 0  && LEFT == 1)
    {
        __delay_ms(75);
        pivot[1][0] = pivot[1][0] + 1;
    for( row = 0; row < 16; row++)
            {
                temp_row[row] = dropping[row][7];
            }
    
    for (row = 0; row < 16; row++)
    {
        for (col = 7; col > 0; col--)
        {
            dropping[row][col] = dropping[row][col - 1];
        }
    }
    for( row = 0; row < 16; row++)
            {
                dropping[row][0] = temp_row[row];   
            }
    }
}
