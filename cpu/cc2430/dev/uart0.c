/**
 * \file
 *
 *   uart0 write routines
 *
 * \author
 *
 *   Anthony "Asterisk" Ambuehl
 *
 */
#include <stdlib.h>
#include <string.h>

#include "cc2430_sfr.h"
#include "dev/uart0.h"

#if UART_ZERO_ENABLE
/*---------------------------------------------------------------------------*/
void
uart0_init()
{
/*
*UART BAUD Rates = 115200
*/
  UART_SET_SPEED(0, UART_115_M, UART_115_E);

/*设置UART0 I/O 接口*/

//PO selected 此处配置选中 P0.3-4
  PERCFG &= ~U0CFG; /*alternative port 1 = P0.5-2*/
	#ifdef UART0_RTSCTS //四线
  		P0SEL |= 0x3C;    /*peripheral select for TX and RX, RTS, CTS*/
	#else				//两线
  		P0SEL |= 0x0C;    /*peripheral select for TX and RX*/
  		P0 &= ~0x20;    /*RTS down*/
	#endif
	P0DIR &= ~0X80; 
   //P0DIR |= 0x28;    /*RTS & TX out*/
   //P0DIR &= ~0x14;   /*CTS & RX in*/
#endif

/*设置UART0 流控制等等*/
#ifdef UART0_RTSCTS //四线
	U0UCR = 0x02;
	//U0UCR = 0x42;   /*defaults: 8N1, RTS/CTS, high stop bit*/
#else
  U0UCR = 0x02;   /*defaults: 8N1, no flow control, high stop bit*/
#endif

  U0CSR = U_MODE | U_TXB;  /*UART mode, receiver disable, TX done*/

  /*set priority group of group 3 to highest, so the UART won't miss bytes*/
  IP1 |= IP1_3;
  IP0 |= IP0_3;
}
/*---------------------------------------------------------------------------*/
/* Write one byte over the UART. */
void
uart0_writeb(uint8_t byte)
{
  IRCON2_UTX0IF = 0;
  U0BUF = byte;
  while(!IRCON2_UTX0IF); /* Wait until byte has been transmitted. */
  IRCON2_UTX0IF = 0;
}
#endif
