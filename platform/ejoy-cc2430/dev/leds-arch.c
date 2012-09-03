#include "contiki-conf.h"
#include "dev/models.h"
#include "dev/leds.h"

#include "cc2430_sfr.h"

/*
 * Sensinode v1.0 HW products have 2 red LEDs, LED1 is mapped to the Contiki
 * LEDS_GREEN and LED2 is mapped to LEDS_RED.
 */

/*---------------------------------------------------------------------------*/
void
leds_arch_init(void)
{
/* *
 * init LEDs had already finished in ejoy-cc2430.c
 */
}
/*---------------------------------------------------------------------------*/
unsigned char
leds_arch_get(void)
{
  unsigned char l = 0;

  if(LED1_PIN) {
    l |= LEDS_RED;
  }
  if(LED2_PIN) {
    l |= LEDS_GREEN;
  }
  if(LED3_PIN){
	l |= LEDS_YELLOW;
  }
  if(LED4_PIN){
	l |= LEDS_BLUE;
  }

  return l;
}
/*---------------------------------------------------------------------------*/
void
leds_arch_set(unsigned char leds)
{
/*
* LEDs Control Function
* we change LEDs here
* leds_on(unsigned char ledv)  -> static void show_leds(unsigned char changed) - > void leds_arch_set(unsigned char leds)
* by MW
*/
	
  if(leds & LEDS_RED) {
	  LED1_PIN = 1;
	} else {
	  LED1_PIN = 0;
	}

  if(leds & LEDS_GREEN) {
    LED2_PIN = 1;
  } else {
    LED2_PIN = 0;
  }

  if(leds & LEDS_YELLOW){
	LED3_PIN = 1;
  }else{
  	LED3_PIN = 0;
  }

  if(leds & LEDS_BLUE){
	LED4_PIN = 1;
  }else{
  	LED4_PIN = 0;
  }
  
  
}
/*---------------------------------------------------------------------------*/
