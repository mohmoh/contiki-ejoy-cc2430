/*
 * ejoy-cc2430.h
 *
 *  Created on: 2012-3-13
 *      Author: manana
 */

#ifndef EJOY_CC2430_H_
#define EJOY_CC2430_H_

#ifndef FLASH_SIZE
#define FLASH_SIZE "F128"
#endif

/* LED pins*/
#define LED1_PIN 	P1_0 //LED_RED
#define LED2_PIN	P1_1//LED_GREEN
#define LED3_PIN	P1_2//LED_YELLOW
#define LED4_PIN	P1_3//LED_GREEN_BLUE -  We see it as BLUE

#undef LED_BLUE
#defin LED_BLUE 6

#undef LEDS_ALL
#defin LEDS_ALL 15

/* Bunton pins*/
#define BUTTON_S1_PIN	P0_1
#define BUTTON_JOY_PIN	P2_0

/* Sensor pins */

#include "8051def.h"

/* I/O port Configuration */
void io_port_init(void);

#endif /* EJOY_CC2430_H_ */

