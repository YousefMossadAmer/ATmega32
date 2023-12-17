/*
LED_program.c
Author : yousef mosaad
Layer  : HAL
SWC    : LED
*/

#include"types.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"

#include"LED_interface.h"
#include"LED_config.h"
#include"LED_private.h"
 
void LED_voidinit (LED_TYPES LED_configration)
{
	GPIO_enumset_PIN_DIRECTION(LED_configration.port , LED_configration.pin , LED_configration.active_state);
}

void LED_voidon(LED_TYPES LED_configration)
{
	if(LED_configration.active_state == ACTIVE_HIGH)
	{
		GPIO_enumset_PINVALUE(LED_configration.port , LED_configration.pin ,GPIO_PTN_HIGH);
	}
	else if (LED_configration.active_state == ACTIVE_LOW)
	{
		GPIO_enumset_PINVALUE(LED_configration.port , LED_configration.pin ,GPIO_PTN_LOW);
	}
}

void LED_voidoff(LED_TYPES LED_configration)
{
	if(LED_configration.active_state == ACTIVE_HIGH)
	{
		GPIO_enumset_PINVALUE(LED_configration.port , LED_configration.pin ,GPIO_PTN_LOW);
	}
	else if (LED_configration.active_state == ACTIVE_LOW)
	{
		GPIO_enumset_PINVALUE(LED_configration.port , LED_configration.pin ,GPIO_PTN_HIGH);
	}
}


void LED_voidtog(LED_TYPES LED_configration)
{
	GPIO_STATUS GPIO_enumtoggle_PINVALUE(LED_configration.port ,LED_configration.pin);
}

