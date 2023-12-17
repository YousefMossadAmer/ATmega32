/*
SW_program.c
crated on: 6NOV,2023
author: yousef mosaad

*/
#include "types.h"
#include "BIT_MATH.h"

#include <util\delay.h>

#include "GPIO_interface.h"


#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"


void SW_voidInit (sw_type sw_configration)
{
	GPIO_enumset_PIN_DIRECTION (sw_configration.port,sw_configration.pin,GPIO_INPUT);
	if (sw_configration.pull_state == SW_Int_PULL_UP)
	{
		GPIO_enumset_PINVALUE(sw_configration.port,sw_configration.pin,GPIO_PTN_HIGH);
	}
}
uint8_t   SW_uint8_tGetPressed   ( sw_type sw_configration )
{
	uint8_t pinvalue = 0;
	uint8_t sw_status = SW_NOT_PRESSED;

	GPIO_enumget_PINVALUE (sw_configration.port,sw_configration.pin,&pinvalue);

		
	 if(sw_configration.pull_state==SW_Int_PULL_UP||sw_configration.pull_state==SW_Ext_PULL_UP)
	 {
	 	if(pinvalue==0)
	 	{
	 		sw_status=SW_PRESSED;
		}
		else if (pinvalue==1)
		{
			sw_status = SW_NOT_PRESSED;
		}

	 }
	 else if(sw_configration.pull_state==SW_Ext_PULL_DOWN)
	 {
	 	if(pinvalue==1)
	 	{
	 		sw_status=SW_PRESSED;
		}
		else if (pinvalue==0)
		{
			sw_status = SW_NOT_PRESSED;
		}

	 }
	 return sw_status;
}



