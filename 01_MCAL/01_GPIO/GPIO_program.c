/*
GPIO_program.c
crated on: 19oct,2023
author: yousef mosaad

*/

#include "types.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"






//--------------------------------------PIN FUNCTIONS ----------------------------------------------

GPIO_STATUS GPIO_enumset_PIN_DIRECTION(uint8_t PORT ,uint8_t PIN,uint8_t DIRECTION)
{
	if ( (PORT <= GPIO_PORTD) && (PIN <= GPIO_PIN7) )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;
		if (DIRECTION ==  GPIO_PTN_INPUT)
		{
			switch(PORT)
			{
			case GPIO_PORTA: CLR_BIT(DDRA,PIN);break;
			case GPIO_PORTB: CLR_BIT(DDRB,PIN);break;	
			case GPIO_PORTC: CLR_BIT(DDRC,PIN);break;	
		    case GPIO_PORTD: CLR_BIT(DDRD,PIN);break;
			}
		}
		else if (DIRECTION ==GPIO_PTN_OUTPT)
		{
			switch(PORT)
			{
			case GPIO_PORTA: SET_BIT(DDRA,PIN);break;
			case GPIO_PORTB: SET_BIT(DDRB,PIN);break;	
			case GPIO_PORTC: SET_BIT(DDRC,PIN);break;	
		    case GPIO_PORTD: SET_BIT(DDRD,PIN);break;
			}
		}
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;
}
GPIO_STATUS GPIO_enumset_PINVALUE(uint8_t PORT ,uint8_t PIN,uint8_t VALUE)
{
	if ( (PORT <= GPIO_PORTD) && (PIN <= GPIO_PIN7) )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;
		if (VALUE == 0)
		{
			switch(PORT)
			{
			case GPIO_PORTA: CLR_BIT(PORTA,PIN);break;
			case GPIO_PORTB: CLR_BIT(PORTB,PIN);break;	
			case GPIO_PORTC: CLR_BIT(PORTC,PIN);break;	
		    case GPIO_PORTD: CLR_BIT(PORTD,PIN);break;
			}
		}
		else if (VALUE == 1)
		{
			switch(PORT)
			{
			case GPIO_PORTA: SET_BIT(PORTA,PIN);break;
			case GPIO_PORTB: SET_BIT(PORTB,PIN);break;	
			case GPIO_PORTC: SET_BIT(PORTC,PIN);break;	
		    case GPIO_PORTD: SET_BIT(PORTD,PIN);break;
			}
		}
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;
}

GPIO_STATUS GPIO_enumget_PINVALUE(uint8_t PORT ,uint8_t PIN,uint8_t* ptr_save_pinvalue)
{
	if ( (PORT <= GPIO_PORTD) && (PIN <= GPIO_PIN7) )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;

		switch(PORT)
			{
			case GPIO_PORTA:STATUS= * ptr_save_pinvalue = GET_BIT(PINA,PIN);break;
			case GPIO_PORTB:STATUS= * ptr_save_pinvalue = GET_BIT(PINB,PIN);break;	
			case GPIO_PORTC:STATUS= * ptr_save_pinvalue = GET_BIT(PINC,PIN);break;	
		    case GPIO_PORTD:STATUS= * ptr_save_pinvalue = GET_BIT(PIND,PIN);break;
			}
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;
}


GPIO_STATUS GPIO_enumtoggle_PINVALUE(uint8_t PORT ,uint8_t PIN)
{
	if ( (PORT <= GPIO_PORTD) && (PIN <= GPIO_PIN7) )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;
		switch(PORT)
			{
			case GPIO_PORTA: TOG_BIT(PORTA,PIN);break;
			case GPIO_PORTB: TOG_BIT(PORTB,PIN);break;	
			case GPIO_PORTC: TOG_BIT(PORTC,PIN);break;	
		    case GPIO_PORTD: TOG_BIT(PORTD,PIN);break;
			}
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;
}


//--------------------------------------PORT FUNCTIONS ----------------------------------------------

GPIO_STATUS GPIO_enumset_PORT_DIRECTION(uint8_t PORT ,uint8_t DIRECTION )
{
	if ( PORT <= GPIO_PORTD )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;
		if(DIRECTION == 1)
		{
			switch(PORT)
			{
			case GPIO_PORTA: DDRA=0XFF;break;
			case GPIO_PORTB: DDRB=0XFF;break;	
			case GPIO_PORTC: DDRC=0XFF;break;	
		    case GPIO_PORTD: DDRD=0XFF;break;
			}

		}
		else if(DIRECTION == 0)
		{
			switch(PORT)
			{
			case GPIO_PORTA: DDRA=0X00;break;
			case GPIO_PORTB: DDRB=0X00;break;	
			case GPIO_PORTC: DDRC=0X00;break;	
		    case GPIO_PORTD: DDRD=0X00;break;
			}

		}
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;	
}

GPIO_STATUS GPIO_enumset_PORTVALUE(uint8_t PORT ,uint8_t VALUE)
{
	if ( PORT <= GPIO_PORTD )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;
		if(VALUE == 1)
		{
			switch(PORT)
			{
			case GPIO_PORTA: PORTA=0XFF;break;
			case GPIO_PORTB: PORTB=0XFF;break;	
			case GPIO_PORTC: PORTC=0XFF;break;	
		    case GPIO_PORTD: PORTD=0XFF;break;
			}

		}
		else if(VALUE == 0)
		{
			switch(PORT)
			{
			case GPIO_PORTA: PORTA=0X00;break;
			case GPIO_PORTB: PORTB=0X00;break;	
			case GPIO_PORTC: PORTC=0X00;break;	
		    case GPIO_PORTD: PORTD=0X00;break;
			}

		}
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;	

}
GPIO_STATUS GPIO_enumget_PORTVALUE(uint8_t PORT,uint8_t* ptr_save_portvalue)
{
	if ( PORT <= GPIO_PORTD )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;
		switch(PORT)
			{
			case GPIO_PORTA: * ptr_save_portvalue = PORTA;break;
			case GPIO_PORTB: * ptr_save_portvalue = PORTB;break;	
			case GPIO_PORTC: * ptr_save_portvalue = PORTC;break;	
		    case GPIO_PORTD: * ptr_save_portvalue = PORTD;break;
			}
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;	
}

GPIO_STATUS GPIO_enumtoggle_PORTVALUE(uint8_t PORT)
{
	if ( PORT <= GPIO_PORTD )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;
		switch(PORT)
			{
			case GPIO_PORTA: PORTA = ~PORTA;break;
			case GPIO_PORTB: PORTB = ~PORTB;break;	
			case GPIO_PORTC: PORTC = ~PORTC;break;	
		    case GPIO_PORTD: PORTD = ~PORTD;break;
			}
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;
}

//--------------------------------------NIBBLE FUNCTIONS----------------------------------------------


GPIO_STATUS GPIO_enumlownibble   (uint8_t PORT ,uint8_t VALUE) //VALUE=1010 1001   PORT=1100 1011
{
	if ( (PORT <= GPIO_PORTD) )
	{
		GPIO_STATUS loc_enumstate  = GPIO_OK;
		
		switch(PORT)
			{
			case GPIO_PORTA: 
				VALUE &=0X0F;   //VALUE = 0X0000 1001
				PORTA &=0XF0;   //PORT  = 0X1100 0000
				PORTA |=VALUE;	//PORT  = 0X1100 1001
				break;
			case GPIO_PORTB:
				VALUE &=0X0F;   //VALUE = 0X0000 1001
				PORTB &=0XF0;   //PORT  = 0X1100 0000
				PORTB |=VALUE;	//PORT  = 0X1100 1001
				break;	
			case GPIO_PORTC:
				VALUE &=0X0F;   //VALUE = 0X0000 1001
				PORTC &=0XF0;   //PORT  = 0X1100 0000
				PORTC |=VALUE;	//PORT  = 0X1100 1001
				break;	
		    case GPIO_PORTD:
		    	VALUE &=0X0F;   //VALUE = 0X0000 1001
				PORTD &=0XF0;   //PORT  = 0X1100 0000
				PORTD |=VALUE;	//PORT  = 0X1100 1001
		    	break;
			}	
		
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;
}



GPIO_STATUS GPIO_enumhighnibble  (uint8_t PORT ,uint8_t VALUE) //VALUE=1010 1001   PORT=1100 1011
{
		if ( (PORT <= GPIO_PORTD) )
	{
		GPIO_STATUS loc_enumstate = GPIO_OK;
		
		switch(PORT)
			{
			case GPIO_PORTA: 
				VALUE &=0XF0;   //VALUE = 0X1010 0000
				PORTA &=0X0F;   //PORT  = 0X0000 1011
				PORTA |=VALUE;	//PORT  = 0X1010 1011
				break;
			case GPIO_PORTB:
				VALUE &=0XF0;   //VALUE = 0X1010 0000
				PORTB &=0X0F;   //PORT  = 0X0000 1011
				PORTB |=VALUE;	//PORT  = 0X1010 1011
				break;	
			case GPIO_PORTC:
				VALUE &=0XF0;   //VALUE = 0X1010 0000
				PORTC &=0X0F;   //PORT  = 0X0000 1011
				PORTC |=VALUE;	//PORT  = 0X1010 1011
				break;	
		    case GPIO_PORTD:
		    	VALUE &=0XF0;   //VALUE = 0X1010 0000
				PORTD &=0X0F;   //PORT  = 0X0000 1011
				PORTD |=VALUE;	//PORT  = 0X1010 1011
		    	break;
			}	
		
	}
	else
	{
		loc_enumstate = GPIO_NOT_OK;
	}
	return loc_enumstate;
}