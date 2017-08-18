#include <stdbool.h>
#include "config.h"
#include "init_ports.h"
#include "init_spi.h"
#include "init1_max7219.h"
#include "init2_max7219.h"
#include "splash_screen.h"
#include "clear_game_play_area.h"
#include "check_can_land.h"
#include "random.h"
#include "new_tetris_shape.h"
#include "copy_tetris.h"
#include "check_left_boundary.h"
#include "check_right_boundary.h"
#include "mov_left.h"
#include "mov_right.h"
#include "bits_to_byte.h"
#include "init_TMR0.h"
#include "rotate_tet.h"
#include "configTimer1.h"
#include "drop_one_pixel.h"
#include "clear_dropping.h"
#include "clear_stuck.h"
#include "check_right_collision.h"
#include "check_left_collision.h"
#include "check_completed_rows.h"
#include "clear_completed_row.h"
#include "drop_rows_above.h"
#include "copy_dropping_to_stuck.h"
#include "check_bottom_boundary.h"
#include "check_vert_collision.h"
#include "update_game_level.h"
#include "display_on_8x8.h"
#include "convert_score.h"
#include "split_digits.h"

#include "main.h"

void main (void)
{
    uchar i, row, col, full_row = 0;
    bool moveR, moveL, rotL, rotR = 1;
    bool bottom, coll = 0;
    init_ports();
    init_spi();
    init1_max7219();
    init2_max7219();
    
    splash_screen();
    __delay_ms(2000);
    clear_game_play_area();
    clear_dropping();       // clears the array dropping, which contains the dropping tetrino
    clear_stuck();          // clears the array dropping, which contains the stuck/ landed tetrinos
    tet_piece = random();   // get a random num between 1 and 7
    new_tetris_shape(tet_piece); // copy tetrino into dropping[][]
    init_TMR0(); // start TMR0 interrupts which multiplexes the 8x8 displays from displaying dropping and then stuck
    configTimer1();  // 0.5 second gravity interrupt for dropping tetrino
   
    

while(1)
    {
     moveL = check_left_boundary();  // makes sure we can't move tetrino further left than  the left wall
     if( moveL == 0 && LEFT == 0)    // check that a 0 was returned from check_left_boundary function and that LEFT button is pressed
     { 
         movl = check_left_collision(); // stops further left movement if another tetrino is in the way
         if(movl == 0)  // no collisions or boundary wall found
         {
           mov_left();   // move one pixel left
         }
     }
        
     
     moveR = check_right_boundary();// makes sure we can't move tetrino further right than the right wall
     if(moveR == 0 && RIGHT == 0)  // check that a 0 was returned from check_right_boundary function and that RIGHT button is pressed
        {
            movr = check_right_collision();// stops further right movement if another tetrino is in the way
            if (movr == 0) // no collisions or boundary wall found
            {
                mov_right();  // move one pixel right
            }
        } 
     
     if (DROP == 0)     // if DROP button is pressed
     {
         __delay_ms(75);    // debounce delay
        
        while( bottom != 1 && coll != 1) // repeat code block while tetrino is not yet at bottom wall and there is no tetrino to collide with vertically
        {
             drop_one_pixel();  // drop tetrino down by one pixel
             coll = check_vert_collision();// returns 1 if there will be a collision with another tetrino
             bottom = check_bottom_boundary();// returns a 1 if tetrino is at the bottom wall
        }
         bottom = 0;    // clear ready for next DROP
         coll = 0;      // clear ready for next DROP
         pivot[0][0] = 1;// restore initial values of pivot point when tetrino is first landed
         pivot[1][0] = 4;
         copy_dropping_to_stuck(); // tetrino is at bottom wall so needs to be copied to stuck
         clear_dropping();          // dropping needs to be cleared to allow a new tetrino to be added to dropping
         tet_piece = random();   // get a random num between 1 and 7 to spawn a new tetrino
         new_tetris_shape(tet_piece); // copy tetrino into dropping[][]
     }
     
     if (ROTATE == 0)   // if ROTATE button is pressed
     {
                __delay_ms(75);// de-bounce delay
                rotate_tet(); // call rotate_tet function
     }      
        full_row = check_completed_rows();// identify which row of the game is fully completed with 1's, ie 11111111
        clear_completed_row(full_row);  // call a function to clear the identified row to 00000000
        if(full_row != 17)// if any from from 0 to 15 is completed
        {
            drop_rows_above(full_row); // drop the rows above the completed row down by one row, and copy all zeros into row [0][col]
            full_row = 17;  // restore default value of full_row for next ROTATE operation
            score = score + 1;  // increase the score by 1 for every completed row
            update_game_level();// assigns appropriate game level according to current score
            BUZZER = 0;     // create a beep from the buzzer when a completed row drops
            __delay_ms(10);
            BUZZER = 1;
        }
        
    }    
}
 
     

 
    


/*pseudocode for TETRIS  05/ 07/ 2017
 * initialise ports, SPI, Timer0 interrupt, Timer1 interrupt and displays
 * display tetris splash screen for 2 seconds
 * clear screen
 * game level = 0
 * enable TMR0 and TMR1 
 * call random() which randomly select one of seven tetris shapes to start the game
 *  get a random number between 1 and 7 and return rand_num to caller.
 *  select the tetris shape from  1 = sq, 2 = bar, 3 = z, 4 = s, 5 = l, 6 = j, 7 = t, then call copy_tetris function to copy tetris shape into dropping[][]
 *  call check_can_land - knowing where the piece will be initially placed at 
 *  pivot ([0][5]), check to see there are no existing obstacles preventing the tetris piece from landing.
 *  by comparing stuck[][]array with dropping[][]array
 *  if result == 1 
 *   the shape cannot be landed return bool 1 via obstacles variable
 * else
 *  the shape can be landed, return bool 0 via obstacles variable
 * if obstacles = 0
 *  land tetris shape at top of display
 * else
 *  game over
 *  clear game play area, display score achieved, wait for reset
 * 
 * do forever
 call check_left_boundary
 * for all rows and column zero of dropping[row][0] check 
 *  if ANDing with game_boarder[row+1][0] yields a 1
 *      return 1 via variable moveL     // cannot move further left
 *  else
 *      return 0 vial moveL             // can move further left
 * 
 *  if there is player input from Right button
 *      if there are no obstacles immediately 1 pixel right and we are not at RHS game border
 *          move tetris piece one pixel right
 *      else
 *          do not allow tetris piece to move right
 *  endif
 *  
 * 
 *  while there is player input from Left button
 *      if there are no obstacles immediately 1 pixel left and we are not at LHS game border
 *          move tetris piece one pixel left
 *      else
 *          do not allow tetris piece to move left
 * endif
 *    if there is player input from drop button
 *      if all pixels below tetris shape are empty
 *      drop shape to bottom row (row 16)
 *      copy to game_board array
 *      launch new tetris piece
 * 
 *      else
 *          do not allow tetris piece to drop
 *    if there are any fully completed rows
 *      clear the row and drop all tetris pieces above this line by one row
 *      award 1 point to the player
 *    if score is equal or  greater than that required to move to next level
 *      increment level
 *      increase game speed
 *      else
 *      do nothing
 *    if 0.5sec interrupt has occurred and
 *      if pixels one row below tetris shape are empty and we are not at row 16 (bottom)
 *      drop tetris shape by one pixel
 *      copy to game_board array
 *      else
 *          stick tetris shape forever
 *          launch new tetris piece
 * else
 *      stop 0.5 second timer interrupt
 *      call game_over function
 *      clear screen
 *      display score achieved
 * 
 * endif
 */