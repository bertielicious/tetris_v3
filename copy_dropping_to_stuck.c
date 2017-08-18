#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
void copy_dropping_to_stuck(void)
{
    uchar row, col;
    for (row = 0; row < 16; row++)
        {
            for (col = 0; col < 8; col++)
            {
                stuck[row][col] = (dropping[row][col] || stuck[row][col]) ;// 'OR' elements of dropping and stuck to combine 1's from both matrices
            }
        }
}
