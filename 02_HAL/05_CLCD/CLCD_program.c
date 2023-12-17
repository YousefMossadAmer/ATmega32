
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

#include "GPIO_interface.h"

#include <util/delay.h>

void CLCD_voidinit()
{
 #if CLCD_MODE ==8	
	_delay_ms(50);
   
   	GPIO_void_setportdirectio   (CLCD_DATA_PORT,GPIO_PIN_OUTPUT);
    Gpio_voidsetpindirection	(CLCD_CONTROL_PORT,CLCD_RS,GPIO_PIN_OUTPUT);
    Gpio_voidsetpindirection	(CLCD_CONTROL_PORT,CLCD_RW,GPIO_PIN_OUTPUT);
    Gpio_voidsetpindirection	(CLCD_CONTROL_PORT,CLCD_EN,GPIO_PIN_OUTPUT);

    CLCD_voidsendcommand(lcd_HOME);
    _delay_ms(1);

    CLCD_voidsendcommand(FUNCTIONSET_EIGHT_BITS);
    _delay_ms(1);

    CLCD_voidclear();

    CLCD_voidsendcommand(lcd_EntryMode);
	_delay_ms(1);
	//end of initialization			
}

void CLCD_voidsenddata (uint8_t addressofdata)
{
 #if CLCD_MODE ==8
	GPIO_void_setportvalue(CLCD_DATA_PORT,addressofdata);
	GPIO_void_setpinvalue(CLCD_CONTROL_PORT,CLCD_RS,GPIO_PIN_HIGH);
	GPIO_void_setpinvalue(CLCD_CONTROL_PORT,CLCD_Rw,GPIO_PIN_LOW);
	CLCD_void_enable_falling_edge();

}
void CLCD_voidsendstring (uint8_t *arr)
{
	for (uint8_t i;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{
		CLCD_voidsenddata(arr[i]);
	}


}

void CLCD_voidsendcommand (uint8_t data)
{
 #if CLCD_MODE ==8
	GPIO_void_setportvalue(CLCD_DATA_PORT,data);
	GPIO_void_setpinvalue(CLCD_CONTROL_PORT,CLCD_RS,GPIO_PIN_LOW);
	GPIO_void_setpinvalue(CLCD_CONTROL_PORT,CLCD_Rw,GPIO_PIN_LOW);
	CLCD_void_enable_falling_edge();

}

void CLCD_voidsetposition (uint8_t raw ,uint8_t coulm)
{
	uint8_t local_command;
	if ( (raw>=2) || (coulm >=16) )
	{
		local_command=lcd_SetCursor;
	}
	else if (raw == CLCD_ROW_1)
	{
		local_command=lcd_SetCursor+(coulm-1);
	}
	else if (raw == CLCD_ROW_2)
	{
		local_command=lcd_SetCursor+64+(coulm-1);
	}
	CLCD_voidsendcommand(local_command);
	_delay_ms(1);
}

/*To generate character https://maxpromer.github.io/LCD-Character-Creator/
*/

void CLCD_voidsendextracharacter(uint8_t row ,uint8_t coulm,uint8_t *array)
{  

 //1 
	CLCD_voidsendcommand(lcd_CGRAM);

//2
	for (int i=0;i<((sizeof(array))/sizeof(array[0]));i++)
	{
		CLCD_voidsenddata(array[i]);
	}
//3
	CLCD_voidsetposition(row ,coulm);

//4
	for(int i=0;i<8;i++)
	{
		CLCD_voidsenddata(i);
	}
}

void CLCD_voidclear(void)
{
	CLCD_voidsendcommand(lcd_Clear);
	_delay_ms(10);
}

static void CLCD_void_enable_falling_edge(void)
{
	delay_ms(1);
	GPIO_void_setpinvalue(CLCD_CONTROL_PORT,CLCD_EN,GPIO_PIN_HIGH);
	delay_ms(1);
	GPIO_void_setpinvalue(CLCD_CONTROL_PORT,CLCD_EN,GPIO_PIN_LOW);
}