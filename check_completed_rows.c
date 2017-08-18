#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

uchar check_completed_rows(void)
{
   uchar row, comp_row = 0;
   for(row = 0; row < 16; row++)
   {

       if  ((stuck [row][0] == 1) && (stuck [row][1] == 1) && (stuck [row][2] == 1) &&  (stuck [row][3] == 1) && (stuck [row][4] == 1)
            && (stuck [row][5] == 1) && (stuck [row][6] == 1) && (stuck [row][7] == 1))// check if we have any complete rows of '1's
        {
           comp_row = row;// if we do, save the identified row in comp_row
           return comp_row;// pass the identified row back to caller
           break;
        }
    }
        return 17;       // no completed row, 17 is just a number outside the accepted rows (0 - 15))
}

