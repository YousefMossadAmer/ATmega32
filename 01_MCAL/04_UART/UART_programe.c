

#include "types.h"
#include "BIT_MATH.H"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


void USART_voidinit(void)
{
	uint16_t UBRR = (FREQUANCY/(2*BAUDRATE))-1;

	#if (USART_MODE == Asynchronous & SYSTEM_SPEED == NORMAL_SPEED)
	CLR_BIT(UCSRA,UCSRA_U2X);
	UBRR/=8;
	#elif (USART_MODE == Asynchronous & SYSTEM_SPEED == DOUBLE_SPEED)
	SIT_BIT(UCSRA,UCSRA_U2X);
	UBRR/=4;
	//#elif (USART_MODE == Synchronous)
	#else
		#error "wrong mode or speed"
	#endif


	UBRRL=(uint8_t)UBRR;
	UBRRH=(uint8_t)(UBRR>>8);
	

	//DATA SIZE 
	#if(DATA_SIZE==BIT_5)
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		CLR_BIT(UCSRC,UCSRC_UCSZ1);
		CLR_BIT(UCSRC,UCSRC_UCSZ0);
	#elif(DATA_SIZE==BIT_6)
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		CLR_BIT(UCSRC,UCSRC_UCSZ1);
		SET_BIT(UCSRC,UCSRC_UCSZ0);
	#elif(DATA_SIZE==BIT_7)
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		SET_BIT(UCSRC,UCSRC_UCSZ1);
		CLR_BIT(UCSRC,UCSRC_UCSZ0);
	#elif(DATA_SIZE==BIT_8)
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		SET_BIT(UCSRC,UCSRC_UCSZ1);
		SET_BIT(UCSRC,UCSRC_UCSZ0);
	#elif(DATA_SIZE==BIT_9)
		SET_BIT(UCSRB,UCSRB_UCSZ2);
		SET_BIT(UCSRC,UCSRC_UCSZ1);
		SET_BIT(UCSRC,UCSRC_UCSZ0);
	#else
		#error "wrong DATA_SIZE config"
	#endif


	#if(NUMBER_OF_STOP_BIT == STOPBIT_1)
		CLR_BIT(UCSRC,UCSRC_USBS);
	#elif(NUMBER_OF_STOP_BIT == STOPBIT_2)
		SET_BIT(UCSRC,UCSRC_USBS);
	#else
		#error "wrong NUMBER_OF_STOP_BITP config"
	#endif



	#if (USART_MODE == Asynchronous)
		CLR_BIT(UCSRC,UCSRC_UMSEL);
	#elif(USART_MODE == Synchronous)
		SET_BIT(UCSRC,UCSRC_UMSEL);
	#else
		#error "wrong USART_MODE config"
	#endif

	 

	#if (PARITY_MODE == DISABLE_PARITY)
		CLR_BIT(UCSRC,UCSRC_UPM1);
		CLR_BIT(UCSRC,UCSRC_UPM0);
	#elif(PARITY_MODE == EVEN_PARITY)
		SET_BIT(UCSRC,UCSRC_UPM1);
		CLR_BIT(UCSRC,UCSRC_UPM0);
	#elif(PARITY_MODE == ODD_PARITY)
		SET_BIT(UCSRC,UCSRC_UPM1);
		SET_BIT(UCSRC,UCSRC_UPM0);
	#else
		#error "wrong PARITY_MODE config"
	#endif




	#if (CLOCK_POLARITY==TX_RISING_XCK_RX_FALLING_XCK)
		CLR_BIT(UCSRC,UCSRC_UCPOL);
	#elif(CLOCK_POLARITY ==TX_FALLING_XCK_RX_RISING_XCK)
		SET_BIT(UCSRC,UCSRC_UCPOL);
	#else
		#error "wrong CLOCK_POLARITY config"
	#endif


	#if (RX_Complete_Interrupt==ENABLE)
			SET_BIT(UCSRB,UCSRB_RXCIE);
	#elif(RX_Complete_Interrupt==DISABLE)
			CLR_BIT(UCSRB,UCSRB_RXCIE);
	#else
		#error "wrong RX_Complete_Interrupt config"
	#endif


	#if (TX_Complete_Interrupt==ENABLE)
			SET_BIT(UCSRB,UCSRB_TXCIE);
	#elif(TX_Complete_Interrupt==DISABLE)
			CLR_BIT(UCSRB,UCSRB_TXCIE);
	#else
		#error "wrong TX_Complete_Interrupt config"
	#endif
		

	#if (USART_Data_Register_Empty_Interrupt==ENABLE)
			SET_BIT(UCSRB,UCSRB_UDRIE);
	#elif(USART_Data_Register_Empty_Interrupt==DISABLE)
			CLR_BIT(UCSRB,UCSRB_UDRIE);
	#else
		#error "wrong USART_Data_Register_Empty_Interrupt config"
	#endif


	#if (Receiver_Enable==ENABLE)
			SET_BIT(UCSRB,UCSRB_RXEN);
	#elif(Receiver_Enable==DISABLE)
			CLR_BIT(UCSRB,UCSRB_RXEN);
	#else
		#error "wrong Receiver_Enable config"
	#endif


	#if (Transmitter_Enable==ENABLE)
			SET_BIT(UCSRB,UCSRB_TXEN);
	#elif(Transmitter_Enable==DISABLE)
			CLR_BIT(UCSRB,UCSRB_TXEN);
	#else
		#error "wrong Transmitter_Enable config"
	#endif

}

void USART_uint8_t_senddata(uint8_t data)
{
	UDR=data;

}


uint8_t USART_uint8_t_receivedata(uint8_t data)
{
	

}