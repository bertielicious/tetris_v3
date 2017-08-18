#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

void drop_rows_above( uchar complete_row)
{
    uchar row, col;
    for (row = (complete_row); row >= 1; row--)
    {
        for (col = 0; col < 8; col++)
        {
            stuck[row][col] = stuck[row - 1][col];   
        }
        
    }
    for (col = 0; col < 8; col++)
    {
        stuck[0][col] = 0;  // clear row 0 of stuck
    }
}
