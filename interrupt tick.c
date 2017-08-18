#include <xc.h>
#include<pic.h>
#include <stdbool.h>
#include "config.h"
#include "drop_one_pixel.h"
#include "bits_to_byte.h"
#include "random.h"
#include "new_tetris_shape.h"
#include "clear_dropping.h"
#include "check_vert_collision.h"
#include "check_can_land.h"
#include "copy_dropping_to_stuck.h"
#include "check_bottom_boundary.h"
#include "interrupt tick.h"
#include "rotate_tet.h"
#include "clear_game_play_area.h"
#include "clear_stuck.h"
#include "display_on_8x8.h"
#include "split_digits.h"
#include "convert_score.h"

void interrupt tick (void)
{
    uchar *j;
    j = &gameover[0];
    extern bool collision;
    extern bool row16;
    extern uchar count;
    extern bool can_land;
    extern char pivot[2][1];    // point about which the new landed tetrino rotates at top of dropping[][] is pivot [0][0] = 1 (row)
                                                                                                            //pivot [1][0] = 4 (column))
    
    if (INTCONbits.TMR0IE = 1 && INTCONbits.T0IF == 1)       // TMR0 refreshes display of STUCK and DROPPING arrays alternately (i.e. multiplexing))
    {
        TMR0 = 0x00;                // 60Hz display refresh/ multiplex rate showing dropping [][] then stuck[][] alternately
        TMR0_LED = ~TMR0_LED;       // GREEN LED for TMR0 diagnostics
        if(g == 0)                  // display dropping
        {
            bits_to_byte(&dropping[0][0], &dropping[8][0]);     // display dropping[][] on LED matrices
            g = 1;                          // set g to allow display of stuck[][] on next TMR0 interrupt
        }
        else 
        {
            bits_to_byte(&stuck[0][0], &stuck[8][0]);           // display stuck[][] on LED matrices
            g = 0;                      // set g to allow display of dropping[][] on next TMR0 interrupt
        }
            INTCONbits.T0IF = 0;        // clear TMR0 interrupt flag
    }
    
    if (PIR1bits.TMR1IF == 1 )       // TMR1 is 0.5 sec gravity timer interrupt
    {
        TMR1H = 0x00;               // preload TMR1 to generate a 125ms interrupt
        TMR1L = 0x00;
        TMR1_LED = ~TMR1_LED;       // RED LED for TMR1 diagnostics
        
        collision = check_vert_collision();// returns 1 for collision, 0 for no collision
        row16 = check_bottom_boundary();// returns 1 for tetrino at bottom wall, 0 for not yet at bottom wall
        if(row16 == 0 && collision == 0)// if tetrino not at bottom wall and no tetrino is in the way
        { 
            count = count + 1;  // slow down the tetrino descent rate by a factor of 4
            if(count == retardation)      // 4 x 125ms = 0.5sec descent rate (16MHz clock frequency))
            {                            // initially retardation = 4, then reduces by 1 as game level increases, according to score
                drop_one_pixel();   // allow current tetrino stored in dropping to drop by 1 pixel
                count = 0; // reset count to initial value, ready for next drop by 1 pixel
                pivot[0][0] = pivot[0][0] + 1; // update the pivot point of the tetrino as it falls vertically
            }
        }
        else    // tetrino in dropping is either at bottom wall boundary and/ or there is a tetrino in it's immediate vertical path
        {
            copy_dropping_to_stuck();// copy current tetrino from dropping to stuck array
            clear_dropping();// clear contents of dropping to allow a new tetrino shape to be written to dropping
            pivot[0][0] = 1;// restore the initial pivot point of the newly landed tetrino at top of dropping
            pivot[1][0] = 4;
            tet_piece = random();   // get a random num between 1 and 7 to spawn a new tetrino
            new_tetris_shape(tet_piece); // copy tetrino into dropping[][]
            can_land = check_can_land();    // test to see there is space for new tetrino to land at top of dropping
                            
        if(can_land == 1)// if new tetrino cannot land at top of dropping, because there is already a tetrino occupying the pixels
            {
                clear_dropping();// erase the tetrino in dropping/ GAME OVER
                clear_stuck();      // clear previous game 
                display_on_8x8(&gameover[0], &gameover[8]);  // display GO
               __delay_ms(2000);
               split_digits();
               //convert_score(units) ;
               display_on_8x8(&num[units * 8], &num[tens * 8]);
               while(1);
            }
        }
        PIR1bits.TMR1IF = 0;            // clear TMR1IF to enable further interrupts
    }
    
}