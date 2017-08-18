#include "config.h"
#include <stdbool.h>
#include "send_spi_byte.h"
#include "send_no_op_spi_byte.h"
void splash_screen(void)
{
    //************************SPLASH SCREEN**************************************
const bool splash[] ={0xe7, 0x44, 0x46, 0x44, 0x47, 0x00, 0xee, 0x4a, 0x4c, // T E
0x4a, 0x49, 0x00, 0x4f, 0x44, 0x42, 0x4f};                                  // T R
                                                                            // I S
char *p1, *p2;          // define two pointers *p1 points to splash[0-7]
p1 = (void*)&splash[0]; // *p2 points to splash[8-15]
p2 = (void*)&splash[8];
char row;                 // counter variable for 'for loop'
for ( row = 1; row < 9; row++)// repeat 8 times, as there are 8 rows to fill with data per matrix
    {
    CS = 0;
    send_no_op_spi_byte();      // write to the upper matrix
    send_spi_byte(row, *p1);      // send the address (row) to write to, followed by the data at *p1
    CS = 1;

    CS = 0;
    send_spi_byte(row, *p2);
    send_no_op_spi_byte();      // write to the lower matrix
    CS = 1;
    p1 = p1 + 1;                // move each pointer forward by 1 character per iteration of the loop
    p2 = p2 + 1;
    }
}

