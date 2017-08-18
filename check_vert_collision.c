#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

bool check_vert_collision(void)
{
   uchar row, col;
   for(row = 0; row < 15; row++)
   {
       for(col = 0; col < 8; col++)
    {
       if (dropping[row][col] && stuck [row+1][col] == 1)   // check if the next vertical drop position would
        {                                                   // result in a collision of two 1's
           return 1;    // cannot drop
           break;
        }
      }
   }
   return 0;            // can drop
}
