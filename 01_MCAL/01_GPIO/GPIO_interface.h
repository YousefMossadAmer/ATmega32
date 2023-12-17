/*
GPIO_privat.h
created on :19oct,2023
author: yousef mosaad
*/

#ifndef _GPIO_PRIVAT_H_
#define _GPIO_PRIVAT_H_

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3

#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7


#define GPIO_PTN_OUTPT 1
#define GPIO_PTN_INPUT 0

#define GPIO_PTN_LOW  0
#define GPIO_PTN_HIGH 1
 GPIO_OK
}GPIO_STATUS;

//PIN FUNCTIONS
GPIO_STATUS GPIO_enumset_PIN_DIRECTION (uint8_t PORT ,uint8_t PIN,uint8_t DIRECTION); 
GPIO_STATUS GPIO_enumset_PINVALUE      (uint8_t PORT ,uint8_t PIN,uint8_t VALUE);
GPIO_STATUS GPIO_enumget_PINVALUE      (uint8_t PORT ,uint8_t PIN,uint8_t* ptr_save_pinvalue);
GPIO_STATUS GPIO_enumtoggle_PINVALUE   (uint8_t PORT ,uint8_t PIN);


//PORT FUNCTIONS 
GPIO_STATUS GPIO_enumset_PORT_DIRECTION    (uint8_t PORT ,uint8_t DIRECTION );
GPIO_STATUS GPIO_enumset_PORTVALUE         (uint8_t PORT ,uint8_t VALUE);
GPIO_STATUS GPIO_enumget_PORTVALUE         (uint8_t PORT,uint8_t* ptr_save_portvalue);
GPIO_STATUS GPIO_enumtoggle_PORTVALUE      (uint8_t PORT);

//NIBBLE FUNCTIONS
void GPIO_voidlownibble   (uint8_t PORT ,uint8_t VALUE);
void GPIO_voidhighnibble  (uint8_t PORT ,uint8_t VALUE);


#endif