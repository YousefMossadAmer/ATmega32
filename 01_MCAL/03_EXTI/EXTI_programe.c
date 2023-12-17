
#include "types.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


void *ptr_tofun[3](void)={0};




void EXTI_voidinit( void)
{
	#if (EXTI_LINE0 == ENABLE)
	{
		#if(SENSE_CONTROL0 == LOW_LEVEL)
			CLR_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);
		#elif(SENSE_CONTROL0 == RISING_EDGE)
			SET_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);	
		#elif(SENSE_CONTROL0 == FALLING_EDGE)
			CLR_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);	
		#elif(SENSE_CONTROL0 == ON_CHANGE)
			SET_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);
		#else 
			#error"ERROR IN SENSE_CONTROL0 CONFIG "
		#endif	
	}
	#endif

	#if (EXTI_LINE1 == ENABLE)
	{
		#if(SENSE_CONTROL1 == LOW_LEVEL)
			CLR_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11);
		#elif(SENSE_CONTROL1 == RISING_EDGE)
			SET_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);	
		#elif(SENSE_CONTROL1 == FALLING_EDGE)
			CLR_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);	
		#elif(SENSE_CONTROL1 == ON_CHANGE)
			SET_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11);
		#else 
			#error"ERROR IN SENSE_CONTROL1 CONFIG "
		#endif	
	}
	#endif

	#if (EXTI_LINE2 == ENABLE)
	{
		#if(SENSE_CONTROL2 == RISING_EDGE)
			SET_BIT(MCUCSR,MCUCSR_ISC2);
		#elif(SENSE_CONTROL2 == FALLING_EDGE)
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
		#else 
			#error"ERROR IN SENSE_CONTROL2 CONFIG "
		#endif	
	}
	#endif
	
}

void EXTI_voidenableinterrupt(uint8_t INT )
{
	SET_BIT(GICR,INT);
}

void EXTI_voiddisableinterrupt(uint8_t INT )
{

	CLR_BIT(GICR,INT);
	
}


void EXTI_voidclearflag( uint8_t NO_OF_INT)
{
	SET_BIT(GIFR,NO_OF_INT);
}

void set_callback (void *INT(void),uint8_t NO_OF_INT)
{
	switch(NO_OF_INT)
	{
		case INT0:
			ptr_tofun[0]=INT;
			EXTI_voidclearflag(INT0);
		case INT1:
			ptr_tofun[1]=INT;
			EXTI_voidclearflag(INT1);
		case INT2:
			ptr_tofun[0]=INT;
			EXTI_voidclearflag(INT2);

	}
}
void__vector_2(void)__atribute__((signal));
void__vector_2(void)
{
	ptr_tofun[0]();
} 
void__vector_3(void)__atribute__((signal));
void__vector_3(void)
{
	ptr_tofun[1]();
} 
void__vector_4(void)__atribute__((signal));
void__vector_4(void)
{
	ptr_tofun[2]();
} 





