/*
SW_interface.h
crated on: 6NOV,2023
author: yousef mosaad

*/

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_Int_PULL_UP     0
#define SW_Ext_PULL_UP     1
#define SW_Ext_PULL_DOWN   2
#define SW_FLOATING        3

#define SW_PRESSED     1
#define SW_NOT_PRESSED 0

typedef struct
{
	uint8_t port;
	uint8_t pin;
	uint8_t pull_state;
}sw_type;

void SW_voidInit       ( sw_type sw_configration);
uint8_t   SW_uint8_tGetPressed   ( sw_type sw_configration);

#endif