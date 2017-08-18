#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

bool check_right_boundary(void)
{
   
   unsigned char row;
   for(row = 0; row < 16; row++)
   {
       if(dropping[row][7] && game_boarder[row + 1][9] == 1)
       {
           return 1;
           break;
       }   
   }
   return 0;
}

