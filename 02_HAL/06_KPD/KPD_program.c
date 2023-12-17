
#include "KPD_private.h"
#include "KPD_interface.h"
#include "KPD_config.h"

void KPD_voidinit(void)
{


	Gpio_voidsetpindirection(KPD_PORT,KPD_R0,GPIO_PIN_INPUT);
	Gpio_voidsetpindirection(KPD_PORT,KPD_R1,GPIO_PIN_INPUT);
	Gpio_voidsetpindirection(KPD_PORT,KPD_R2,GPIO_PIN_INPUT);
	Gpio_voidsetpindirection(KPD_PORT,KPD_R3,GPIO_PIN_INPUT);

	GPIO_void_setpinvalue(KPD_PORT,KPD_R0,GPIO_PIN_HIGH);
	GPIO_void_setpinvalue(KPD_PORT,KPD_R1,GPIO_PIN_HIGH);
	GPIO_void_setpinvalue(KPD_PORT,KPD_R2,GPIO_PIN_HIGH);
	GPIO_void_setpinvalue(KPD_PORT,KPD_R3,GPIO_PIN_HIGH);




	Gpio_voidsetpindirection(KPD_PORT,KPD_C0,GPIO_PIN_OUTPUT);
	Gpio_voidsetpindirection(KPD_PORT,KPD_C1,GPIO_PIN_OUTPUT);
	Gpio_voidsetpindirection(KPD_PORT,KPD_C2,GPIO_PIN_OUTPUT);
	Gpio_voidsetpindirection(KPD_PORT,KPD_C3,GPIO_PIN_OUTPUT);

	GPIO_void_setpinvalue(KPD_PORT,KPD_C0,GPIO_PIN_HIGH);
	GPIO_void_setpinvalue(KPD_PORT,KPD_C1,GPIO_PIN_HIGH);
	GPIO_void_setpinvalue(KPD_PORT,KPD_C2,GPIO_PIN_HIGH);
	GPIO_void_setpinvalue(KPD_PORT,KPD_C3,GPIO_PIN_HIGH);

}

uint8_t KPD_uint8_t_getpressed(void)
{
	uint8_t returndata=0;
	uint8_t getpressed=1;

	uint8_t row,colum;


	for (colum=colum_init;colum<colum_end;colum++)
	{
		GPIO_void_setpinvalue(KPD_PORT,KPD_C0,GPIO_PIN_LOW);

		for (row=row_init;row<crow_end;row++)
		{
			getpressed=GPIO_uint8_t_getpinvalue(KPD_PORT,row);

			if(getpressed==0)
			{
				_delay_ms(50);
				getpressed=GPIO_uint8_t_getpinvalue(KPD_PORT,row);

				if(getpressed==0)
				{
					returndata=KPD_Buttons[row-row_init][colum-colum_init];
				}

				while(getpressed==0)
				{
					getpressed=GPIO_uint8_t_getpinvalue(KPD_PORT,row);
				}
				break;
			}
		}


		GPIO_void_setpinvalue(KPD_PORT,KPD_C0,GPIO_PIN_HIGH);

	}
	return returndata;

}
