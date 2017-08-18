#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
#include "copy_tetris.h"
#include "bits_to_byte.h"
#include "clear_dropping.h"
#include "clear_new_tet.h"

void rotate_tet (void)
{
    uchar row, col, new_row, new_col = 0;
 
    for (row = 0; row < 16; row++)
    {
        for (col = 0; col < 8; col++)
        {
            if ( dropping[row][col] == 1)          // ignore computing rotation of pixels containing zero
            {
                
                vector [0][0] = row;        // store row and col of tetris pixel  to be rotated in vector array
                vector [1][0] = col;
                vector_rel[0][0] = vector[0][0] - pivot[0][0];
                vector_rel[1][0] = vector[1][0] - pivot[1][0];
                vector_trans[0][0] = rotate[0][0] * vector_rel[0][0] + rotate[0][1] * vector_rel[1][0];
                vector_trans[1][0] = rotate[1][0] * vector_rel[0][0] + rotate[1][1] * vector_rel[1][0];
                vector_absol[0][0] = pivot[0][0] + vector_trans[0][0];
                vector_absol[1][0] = pivot[1][0] + vector_trans[1][0];
                
                new_row = vector_absol[0][0];
                new_col = vector_absol[1][0];
                
                new_tet[new_row][new_col] = 1;   
            }
            
            else
            {
                continue;                   // don't compute the rotation if the pixel is a zero
            }   
        }  
    }
    
    for (row = 0; row < 16; row++)
    {
        for (col = 0; col < 8; col++)
        {
            dropping[row][col] = new_tet[row][col];  
   
        }
    }
    clear_new_tet();                        // delete old rotation ready for new rotation
    
}
    
