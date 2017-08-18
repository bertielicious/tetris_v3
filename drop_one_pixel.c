#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
void drop_one_pixel(void)
{
    uchar row, col;
    bool temp[8] = {0,0,0,0,0,0,0,0};
    
    for (col = 0; col < 8; col++)
    {
        temp[col] = dropping[15][col];   // copy row 15 of dropping[15][j] to temp[j]
    }
    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 8; col++)
        {
            temp_tet[row][col] = dropping [row][col];
        }
    }

    
    for(row = 0; row < 15; row++)
    {
        
        for(col = 0; col < 8; col++)
        {   
                temp_tet[row+ 1][col] = dropping [row][col];//copy row 0 - 14 to temp_tet[][]    
        }
    }
   
    

    for (col = 0; col < 8; col++)
    {
        temp_tet[0][col] = temp[col];   // copy temp[] to row 0 of temp_tet{0][j]
    }

    for(row = 0; row < 16; row++)
    {
        
        for(col = 0; col < 8; col++)
        {
            dropping[row][col] = temp_tet[row][col];    // copy temp_tet[][] into dropping[][]
        }       
    }   
}