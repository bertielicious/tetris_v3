#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"

void update_game_level (void)
{
    if (score < 6)
    {
        game_level = 1;
        retardation = 4;
    }
    else if (score > 5 && score <10)
    {
        game_level = 2;
        retardation = 3;
    }
    else if (score > 9 && score <12)
    {
        game_level = 3;
        retardation = 2;
    }
    else if (score > 11)
    {
        game_level = 4;
        retardation = 1;
    }
}
