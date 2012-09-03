#ifndef __MODELS_H__
#define __MODELS_H__

#ifndef FLASH_SIZE
#define FLASH_SIZE "F128"
#endif

#include "dev/ejoy-cc2340.h"

/* LED pins*/
#define LED1_PIN 	P1_0
#define LED2_PIN	P1_1
#define LED3_PIN	P1_2
#define LED4_PIN	P1_3

/* Bunton pins*/
#define BUTTON_S1_PIN	P0_1
#define BUTTON_JOY_PIN	P2_0

/* Sensor pins */

/* Model-Specific startup functions */
void model_init();
void model_uart_intr_en();

#endif /* __MODELS_H__ */
