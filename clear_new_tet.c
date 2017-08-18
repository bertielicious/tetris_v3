#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
void clear_new_tet(void)
{
    uchar row, col;
    for ( row = 0; row < 16; row++)
    {
        for (col = 0; col < 8; col++)
        {
             new_tet[row][col] = 0;   // clear all elements of new_tet[][]       
        }
    }
}
