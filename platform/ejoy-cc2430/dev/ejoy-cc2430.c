/*
 * ejoy-cc2430.c
 *
 *  Created on: 2012-3-13
 *      Author: manana
 */

/**
 *
 *
 */

#include "dev/ejoy-cc2430.h"

/*---------------------------------------------------------------------------*/
/* Init the port 0, port 1:
 *
 *   - P1, 3-4, P0, 0, LCD, output 1
 *   - P0, 1, s1 button, input 0
 *   - P0, 2 - 5 , CH340T:USB to serial-parallel : P0_2: RXD input,  P0_3:TXD output,
 *   											   P0_4: CTS output, P0_5:RTS input;
 *	 - P0, 6 - 7 , JOY，POT input
 *   - P1, 0 - 3 , LEDs: RED,GREEN,YELLOW,GRENN. output
 *   - P1, 4 - 7 , JTAG
 *   - P0: 0001 1001 -0x19
 *   - P1: 0000 1111 -0x0F
 */

void
io_port_init(){
	/* initial the I/O port direction */
	  P1DIR |= 0x0F;
	  P0DIR |= 0x19;

	  P1 &= 0xF0 ;/*off the LEDs*/
}
