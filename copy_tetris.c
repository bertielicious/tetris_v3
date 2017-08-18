#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
void copy_tetris(bool *tetris_array)   // *tetris is a pointer containing
{                                      // the address of a tetris shape 
    char row, col;                     // eg &sq[0][0]
    for (row = 0; row < 2; row++)               
    {
        for (col = 0; col < 8; col++)
        {
            dropping [row][col] = *tetris_array;// copy tetris shape into top two rows of 
            tetris_array++;                     // dropping[][] array, then increment pointer
        }  
    }
}
