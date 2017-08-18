#include "config.h"
#include <stdlib.h>
#include <stdbool.h>
#include "copy_tetris.h"
#include "random.h"


void new_tetris_shape(uchar tet_shape) 
{
    switch (tet_shape)
    {
        case 1:
            copy_tetris(&sq[0][0]); // call copy_tetris function to copy tetris shape into dropping[][]
            break;
            
        case 2:
            copy_tetris(&bar[0][0]); // call copy_tetris function to copy tetris shape into dropping[][]
            break;
            
        case 3:
            copy_tetris(&z[0][0]); // call copy_tetris function to copy tetris shape into dropping[][]
            break;
            
        case 4:
            copy_tetris(&s[0][0]); // call copy_tetris function to copy tetris shape into dropping[][]
            break;
            
        case 5:
            copy_tetris(&l[0][0]); // call copy_tetris function to copy tetris shape into dropping[][]
            break;
            
        case 6:
            copy_tetris(&jay[0][0]); // call copy_tetris function to copy tetris shape into dropping[][]
            break;
            
        case 7:
            copy_tetris(&t[0][0]); // call copy_tetris function to copy tetris shape into dropping[][]
            break;
            
        default:
            copy_tetris(&err[0][0]);
    }
}

