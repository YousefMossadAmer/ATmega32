/*
LED_interface.h
Author : yousef mosaad
Layer  : HAL
SWC    : LED
*/

#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3

#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0

typedef struct 
{
	uint_8 port;
	uint_8 pin;
	uint_8 active_state	
}LED_TYPES;
void LED_voidinit (LED_TYPES LED_configration);
void LED_voidon   (LED_TYPES LED_configration);
void LED_voidoff  (LED_TYPES LED_configration);
void LED_voidtog  (LED_TYPES LED_configration);


#endif