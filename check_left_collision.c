#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

bool check_left_collision (void)
{
   uchar row, col;
   for(row = 0; row < 15; row++)
   {
       for(col = 1; col < 8; col++)
       {
            if (dropping[row][col] && stuck [row][col - 1] == 1)   // check if the next move left position would
            {                                                   // result in a collision of two 1's
                return 1;    // cannot move further left
                break;
            }
       }
   }
   return 0;            // can move further left
}


