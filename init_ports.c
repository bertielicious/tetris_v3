#include "xc.h"

/*  pin     PORT    FUNCTION    
    9       RC7     SDO output
 *  11      RB6     SCK output
 *  8       RC6     CS (active low) output
 *  12      RB5     move R switch input
 *  14      RC2     move L switch input
 *  2       RA5     buzzer output
 *  5       RC5     RED DE-BUG LED output
 *  10      RB7     GREEN DE-BUG LED output
 *  7       RC3     ROTATE TETRIS
 *  6       RC4     DROP TETRIS
 */
void init_ports(void)
{
//******4MHz clock setup********************************
OSCCONbits.IRCF3 = 1;           // 4MHz clock setup
OSCCONbits.IRCF2 = 1;           /* bit 5-2 IRCF<3:0>: Internal Oscillator Frequency Select bits
                                    1111 = 16 MHz or 48 MHz HF (see Section 5.2.2.1 ?HFINTOSC?)
                                    1110 = 8 MHz or 24 MHz HF (3x PLL) or 32 MHz HF (4x PLL) (see Section 5.2.2.1 ?HFINTOSC?)
                                    1101 = 4 MHz */
OSCCONbits.IRCF1 = 1;
OSCCONbits.IRCF0 = 1;
OSCCONbits.SCS1 = 1;
OSCCONbits.SCS0 = 0;

//********TURN OFF ANALOGUE INPUTS**********************
ANSELA = 0x00;                  // turn off all ADC inputs on PORTA
ANSELB = 0x00;                  // turn off all ADC inputs on PORTB
ANSELC = 0x00;                  // turn off all ADC inputs on PORTC
//********TRISBITS SETUP for I/O************************
TRISCbits.TRISC7 = 0;   // SDO
TRISBbits.TRISB6 = 0;   // SCK
TRISCbits.TRISC6 = 0;   // CS (active low))
TRISBbits.TRISB5 = 1;   // R switch
TRISCbits.TRISC2 = 1;   // L switch
TRISCbits.TRISC3 = 1;   // ROTATE TETRIS switch
TRISCbits.TRISC4 = 1;   // DROP TETRIS SWITCH
TRISAbits.TRISA5 = 0;   // piezo buzzer
TRISCbits.TRISC5 = 0;   // RED DE-BUG LED
TRISBbits.TRISB7 = 0;   // GREEN DE-BUG LED

//********CLEAR ALL OUTPUTS TO ZERO**********************
PORTCbits.RC7 = 0;
PORTBbits.RB6 = 0;
PORTCbits.RC6 = 0;
PORTBbits.RB5 = 0;
PORTCbits.RC2 = 0;
PORTCbits.RC3 = 0;
PORTAbits.RA5 = 1;
PORTBbits.RB7 = 0;
}