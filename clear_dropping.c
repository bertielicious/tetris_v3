#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
void clear_dropping(void)
{
    uchar row, col;
    for ( row = 0; row < 16; row++)
    {
        for (col = 0; col < 8; col++)
        {
             dropping[row][col] = 0;   // clear all elements of dropping       
        }
    }
}
