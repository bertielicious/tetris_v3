#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
bool check_lr(void)
{
    char row, col = 0;
       for (row = 0; row < 2; row++) 
       {
           for (col = 1; col < 8; col++) 
           {
               if(dropping[row][col - 1] && stuck[row][col] == 1)
               {
                   return 1;        // cannot move left
               }
               else
               {
                   return 0;        // can move left
               }
           }
       
    }
}
