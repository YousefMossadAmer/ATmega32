#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define INT0  6
#define INT1  7
#define INT2  5

#define LOW_LEVEL    0
#define	RISING_EDGE  1
#define	FALLING_EDGE 2
#define	ON_CHANGE    3



void EXTI_voidinit( void);
void EXTI_voidenableinterrupt(uint8_t INT );
void EXTI_voiddisableinterrupt(uint8_t INT );
void EXTI_voidclearflag( uint8_t NO_OF_INT);
void EXTI_voidset_callback (void *INT(void),uint8_t NO_OF_INT);


#endif