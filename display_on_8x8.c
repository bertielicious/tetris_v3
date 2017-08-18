#include "config.h"
#include <pic.h>
#include "send_no_op_spi_byte.h"
#include "send_spi_byte.h"
void display_on_8x8(uchar *sum_row1, uchar *sr2)
{
    uchar row;
    for(row = 0; row < 8; row++)
    {
        CS = 0;
       
            send_spi_byte(row + 1, *sum_row1);// write units
            send_no_op_spi_byte();
            sum_row1 = sum_row1 + 1;
        CS = 1;   
        
       
         CS = 0;     
            send_no_op_spi_byte();
            send_spi_byte(row + 1, *sr2);   // write tens 
            sr2 = sr2 + 1;
      CS = 1;
        
        
        
    }
}

