#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

void clear_completed_row(uchar clear_row)
{
    uchar col;
    for (col = 0; col < 8; col++)
    {
        stuck [clear_row][col] = 0;     // clear each element of the completed row
    }
}
