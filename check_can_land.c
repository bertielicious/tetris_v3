#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

bool check_can_land(void)
{
    uchar row, col;
    for ( row = 0; row < 2; row++)      // just check the inital landing position of the tetrino at top of dropping
    {
        for (col = 0; col < 8; col++)
        {
            if (stuck[row][col] && dropping[row][col] == 1)// check if there are any obstacles in stuck[][]
            {
                return 1;               // cannot land
            }
        }
    }
    return 0;                           // can land
}