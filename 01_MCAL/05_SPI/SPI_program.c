
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_voidinit(void)
{
	


	#if (SPI_Interrupt == SPI_Interrupt_ENABLE)
		SET_BIT(SPCR,SPCR_SPIE);
	#elif(SPI_Interrupt == SPI_Interrupt_DISABLE)
		CLR_BIT(SPCR,SPCR_SPIE);
	#else
		#error "WRONG IN SPI_Interrupt CONFIG "
	#endif

	#if (SPI_DATA_ORDER == SPI_LSB_FIRIST)
		SET_BIT(SPCR,SPCR_DORD);
	#elif(SPI_DATA_ORDER == SPI_MSB_FIRIST)
		CLR_BIT(SPCR,SPCR_DORD);
	#else
		#error "WRONG IN SPI_DATA_ORDER CONFIG "
	#endif


	#if ( SPI_MASTER_SLAVE == SPI_MASTER)
		SET_BIT(SPCR,SPCR_MSTR);
	#elif( SPI_MASTER_SLAVE == SPI_SLAVE)
		CLR_BIT(SPCR,SPCR_MSTR);
	#else
		#error "WRONG IN  SPI_MASTER_SLAVE CONFIG "
	#endif


	#if ( SPI_Clock_Polarity == SPI_LEADING_RISING_TRAILING_FALLING)
		CLR_BIT(SPCR,SPCR_CPOL);
	#elif( SPI_Clock_Polarity == SPI_LEADING_FALLING_TRAILING_RISING)
		SET_BIT(SPCR,SPCR_CPOL);
	#else
		#error "WRONG IN  SPI_Clock_Polarity CONFIG "
	#endif

	#if (SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING)
		CLR_BIT(SPCR,SPCR_CPHA);
	#elif(SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING)
		SET_BIT(SPCR,SPCR_CPHA);
	#else
		#error "WRONG IN  SPI_CLOCK_PHASE CONFIG "
	#endif



	#if (SPI_Clock_Rate == SPI_FREQ_DIVIDED_BY_2)
		SET_BIT(SPSR,SPSR_SPI2X);
		CLR_BIT(SPCR,SPCR_SPR1);
		CLR_BIT(SPCR,SPCR_SPR0);
	#elif(SPI_Clock_Rate SPI_FREQ_DIVIDED_BY_4)
		CLR_BIT(SPSR,SPSR_SPI2X);
		CLR_BIT(SPCR,SPCR_SPR1);
		CLR_BIT(SPCR,SPCR_SPR0);
	#elif(SPI_Clock_Rate SPI_FREQ_DIVIDED_BY_8)
		SET_BIT(SPSR,SPSR_SPI2X);
		CLR_BIT(SPCR,SPCR_SPR1);
		SET_BIT(SPCR,SPCR_SPR0);
	#elif(SPI_Clock_Rate SPI_FREQ_DIVIDED_BY_16)
		CLR_BIT(SPSR,SPSR_SPI2X);
		CLR_BIT(SPCR,SPCR_SPR1);
		SET_BIT(SPCR,SPCR_SPR0);
	#elif(SPI_Clock_Rate SPI_FREQ_DIVIDED_BY_32)
		SET_BIT(SPSR,SPSR_SPI2X);
		SET_BIT(SPCR,SPCR_SPR1);
		CLR_BIT(SPCR,SPCR_SPR0);
	#elif(SPI_Clock_Rate SPI_FREQ_DIVIDED_BY_64)
		CLR_BIT(SPSR,SPSR_SPI2X);
		SET_BIT(SPCR,SPCR_SPR1);
		CLR_BIT(SPCR,SPCR_SPR0);
	#elif(SPI_Clock_Rate SPI_FREQ_DIVIDED_BY_128)
		CLR_BIT(SPSR,SPSR_SPI2X);
		SET_BIT(SPCR,SPCR_SPR1);
		SET_BIT(SPCR,SPCR_SPR0);
	#else
		#error "WRONG IN  Clock_Polarity CONFIG "
	#endif


	#if (SPI_MODE == SPI_ENABLE )
		SET_BIT(SPCR,SPCR_SPE);
	#elif(SPI_MODE == SPI_DISABLE)
		CLR_BIT(SPCR,SPCR_SPE);
	#else
		#error "WRONG IN SPI_MODE CONFIG "
	#endif
}

void SPI_voidsend_recive_data(uint8_t data)
{
	SPDR = data;
	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	CLR_BIT(SPSR,SPSR_SPIF);
}