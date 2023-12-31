

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_RS GPIO_PIN0   
#define CLCD_RW GPIO_PIN1   
#define CLCD_EN GPIO_PIN2  



#define CLCD_CONTROL_PORT GPIO_PORTA
#define CLCD_DATA_PORT    GPIO_PORTB

uint8_t arr_of_extracharacter[]={
	0x00,0x00,0x19,0x19,0x1F,0x08,0x13,0x00,
	0x00,0x00,0x07,0x07,0x1F,0x00,0x00,0x00,
	0x01,0x00,0x03,0x13,0x1F,0x00,0x00,0x00,
	0x00,0x00,0x1B,0x1B,0x1F,0x00,0x00,0x00,
	0x00,0x00,0x0D,0x09,0x1F,0x00,0x00,0x00,
	0x00,0x00,0x02,0x02,0x0F,0x00,0x00,0x00
};

#endif