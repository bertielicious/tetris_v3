#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

bool check_left_boundary(void)
{
   uchar row;
   for(row = 0; row < 16; row++)
   {
       if(dropping[row][0] && game_boarder[row + 1][0] == 1)// game boarder is a 'fence' of 1's around dropping
                                                            // when AND'd with dropping if we get a 1 we know dropping is next to the fence
       {
           return 1;    // cannot move left any further
           break;
       }
   }
   return 0;            // can move left further
}
