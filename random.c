#include<xc.h>
#include<pic.h>
#include "config.h"
#include<stdlib.h>
uchar random(void)
{
    uchar rand_num = 0;
    rand_num = rand()%7 + 1 ;  // generates a random number between 1 and 7  
    return rand_num ;            // which are used to select the tetris shape
}

