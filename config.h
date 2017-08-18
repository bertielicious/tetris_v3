/* 
 * File:   config.h
 * Author: Phil
 *
 * Created on 10 July 2017, 19:16
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif
    // PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include<pic.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)
#define _XTAL_FREQ 16000000      // Internal clock 4MHz




//**********************SPI CONSTANTS***********************************************

#define normal_operation_addr 0x0C //normal operation mode hi byte
#define shut_down_data 0x00       // shutdown mode hi byte
#define normal_operation_data 0x01 //normal operation mode lo byte
#define decode_off_addr 0x09 // no BCD decoding needed hi byte
#define decode_off_data 0x00 // no BCD decoding needed lo byte
#define scan_limit_addr 0x0B // display 8 columns of leds hi byte
#define scan_limit_data 0x07 // display 8 columns of leds lo byte
#define display_intensity_addr 0x0A // minimum display intensity hi byte
#define display_intensity_data 0x00 // minimum display intensity lo byte
#define no_op_addr 0x00 // No operation address
#define no_op_data 0x00 // No operation data
//**********************DEFINITIONS OF PORT IN/OUTPUTS************************

#define TMR0_LED PORTBbits.RB7      // green debug led
#define TMR1_LED PORTCbits.RC5      // red debug led
//#define SDI PORTBbits.RB4
#define SDO PORTCbits.RC7           //SDO
#define CS PORTCbits.RC6            // CS
#define SCK PORTBbits.RB6           // SCK
#define LEFT PORTBbits.RB5      // pin 12   left switch input
#define RIGHT PORTCbits.RC2     // pin 14   right switch input
#define ROTATE PORTCbits.RC3    // pin 7   rotate switch input
#define DROP PORTCbits.RC4      // pin 6   drop switch input
#define BUZZER PORTAbits.RA5    // pin 2   piezo buzzer output
    
typedef unsigned char uchar;  
bool result = 0;
volatile bool collision = 0;    // variable used by isr
uchar g = 0;
uchar tet_piece = 0;
uchar row_p = 0;
uchar col_p = 5;
uchar game_level = 1;
uchar retardation = 4;
uchar score = 0;
uchar units, tens = 0;
bool obstacles = 0;
volatile bool row16 = 0;        // variable used by isr
volatile uchar count = 0;
volatile bool can_land = 0;
bool landed = 0;
volatile uchar current_row = 0;
volatile uchar movl = 0;
volatile uchar movr = 0;

    bool game_boarder[18][10] = {{1,1,1,1,1,1,1,1,1,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,0,0,0,0,0,0,0,0,1},
                                 {1,1,1,1,1,1,1,1,1,1}};
    
   volatile bool stuck[16][8]={{0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0}};
    
volatile bool dropping[16][8] = {{0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0}};
 
    const bool sq[2][8] = {{0,0,0,0,1,1,0,0},       // square tetrino
                           {0,0,0,0,1,1,0,0}};
                           
    const bool bar[2][8] = {{0,0,1,1,1,1,0,0},      // bar tetrino
                            {0,0,0,0,0,0,0,0}};
    
    const bool z[2][8] = {{0,0,0,1,1,0,0,0},        // z tetrino
                          {0,0,0,0,1,1,0,0}};
    
    const bool s[2][8] = {{0,0,0,0,1,1,0,0},        // s tetrino  
                          {0,0,0,1,1,0,0,0}};          
    
    
  
    
    const bool l[2][8] = {{0,0,0,0,0,1,0,0},        // L tetrino
                          {0,0,0,1,1,1,0,0}};
    
    const bool jay[2][8] = {{0,0,0,1,1,1,0,0},      // J tetrino
                            {0,0,0,0,0,1,0,0}};
    
    const bool t[2][8] =   {{0,0,0,1,1,1,0,0},      // T tetrino
                            {0,0,0,0,1,0,0,0}};
    
    const bool err[2][8] = {{0,1,1,1,1,1,0,0},        // error
                            {0,1,0,1,0,1,0,0}};

    bool new_tet[16][8] = {{0,0,0,0,0,0,0,0},        // rotated tetrino
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0}};
    bool temp_tet[17][8]={{0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0}};
    
   volatile char pivot[2][1] = {{1},
                                {4}};
    char vector[2][1] = {{0},
                         {0}};
    char vector_rel[2][1] = {{0},
                             {0}};
    const signed char rotate[2][2] = {{0, -1},
                                      {1,  0}};
    char vector_trans [2][1] = {{0},
                                {0}};

    char vector_absol [2][1] = {{0},
                                {0}};
    //const bool zero[8] = {0x00, 0x00, 0x0e, 0x0a, 0x0a, 0x0a, 0x0a, 0x0e};// score board digits
   // const bool one[8] =  {0x00, 0x00, 0x02, 0x06, 0x0a, 0x02, 0x02, 0x02};
   // const bool two[8] =  {0x00, 0x00, 0x0e, 0x02, 0x0e, 0x08, 0x08, 0x0e};
    //const bool three[8] ={0x00, 0x00, 0x0e, 0x02, 0x06, 0x02, 0x02, 0x0e};
    //const bool four[8] = {0x00, 0x00, 0x08, 0x0a, 0x0a, 0x0e, 0x02, 0x02};
    //const bool five[8] = {0x00, 0x00, 0x0e, 0x08, 0x0e, 0x02, 0x02, 0x0e};
    //const bool six[8] = {0x00, 0x00, 0x0e, 0x0a, 0x0a, 0x0a, 0x0a, 0x0e};
    //const bool seven[8] = {0x00, 0x00, 0x0e, 0x02, 0x02, 0x04, 0x04, 0x04};
    //const bool eight[8] = {0x00, 0x00, 0x0e, 0x0a, 0x0a, 0x0e, 0x0a, 0x0e};
    //const bool nine[8] = {0x00, 0x00, 0x0e, 0x0a, 0x0a, 0x0e, 0x02, 0x0e};
    const bool num[80] = {0x00, 0x00, 0x0e, 0x0a, 0x0a, 0x0a, 0x0a, 0x0e,//0
    0x00, 0x00, 0x02, 0x06, 0x0a, 0x02, 0x02, 0x02, //1
    0x00, 0x00, 0x0e, 0x02, 0x0e, 0x08, 0x08, 0x0e, //2
    0x00, 0x00, 0x0e, 0x02, 0x06, 0x02, 0x02, 0x0e, //3
    0x00, 0x00, 0x08, 0x0a, 0x0a, 0x0e, 0x02, 0x02, //4
    0x00, 0x00, 0x0e, 0x08, 0x0e, 0x02, 0x02, 0x0e, //5
    0x00, 0x00, 0x0e, 0x0a, 0x0a, 0x0a, 0x0a, 0x0e, //6
    0x00, 0x00, 0x0e, 0x02, 0x02, 0x04, 0x04, 0x04, //7
    0x00, 0x00, 0x0e, 0x0a, 0x0a, 0x0e, 0x0a, 0x0e, //8
    0x00, 0x00, 0x0e, 0x0a, 0x0a, 0x0e, 0x02, 0x0e};//9
                                                 
// 0 = [0]->[3]
// 1 = [4]->[7]
// 2 = [8]->[11]
// 3 = [12]->[15]
// 4 = [16]->[19]
// 5 = [20]->[23]
// 6 = [24]->[27]
// 7 = [28]->[31]
// 8 = [32]->[35]
// 9 = [36]->[39]
    
    const bool gameover[16] = {0x66, 0xa9, 0x89, 0xe9, 0xa9, 0x66, 0x00, 0x00,  // G
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // O
#ifdef	__cplusplus

#endif

#endif	/* CONFIG_H */

