#include "config.h"
#include "init1_max7219.h"
#include "send_spi_byte.h"
/* initialise matrix 1 */
void init1_max7219(void)
{
 CS = 0;
 send_spi_byte (normal_operation_addr,shut_down_data);//leave shutdown mode and enter normal operation
 CS = 1;

 CS = 0;
 send_spi_byte (display_intensity_addr,display_intensity_data);// minimum display intensity 1/32
 CS = 1;

 CS = 0;
 send_spi_byte (decode_off_addr,decode_off_data); // decode mode off
 CS = 1;

 CS = 0;
 send_spi_byte (scan_limit_addr,scan_limit_data); // scan limit = 8 digits multiplexed
 CS = 1; // LOAD is high

 CS = 0;
 send_spi_byte (normal_operation_addr,normal_operation_data);//leave shutdown mode and enter normal                                                         //operation
 CS = 1;
}

