
#ifndef UART_CONFIG_H_ 
#define UART_CONFIG_H_

/* ENTER FREQUANCIES & BAUDRATE
*/
#define FREQUANCY 8000000
#define BAUDRATE    9600 





/*MULTI PROCESSOR COUNICATION MODE 
	-DISABLE
	-ENALBE
*/
#define MPCM DISABLE






/*select SYSTEM_SPEED
 	-NORMAL_SPEED
 	-DOUBLE_SPEED 
*/
#define SYSTEM_SPEED NORMAL_SPEED





/*select USART_MODE
 	-Synchronous
 	-Asynchronous  
*/
#define USART_MODE Asynchronous






/*SELECT DATA_SIZE
	-BIT_5
    -BIT_6
	-BIT_7
	-BIT_8
	-BIT_9
*/
#define DATA_SIZE BIT_8 






/*SELECT NUMBER OF STOP BIT
	- STOPBIT_1
	- STOPBIT_2
*/
#define NUMBER_OF_STOP_BIT STOPBIT_1





/*SELECT PARITY_MODE
	-DISABLE_PARITY 
	-EVEN_PARITY
	-ODD_PARITY
*/
#define PARITY_MODE DISABLE_PARITY





/*SELECT CLOCK_POLARITY
	-TX_RISING_XCK_RX_FALLING_XCK
	-TX_FALLING_XCK_RX_RISING_XCK
*/
#define CLOCK_POLARITY 	TX_RISING_XCK_RX_FALLING_XCK



/* select enterrupts state
	-DISABLE
	-ENABLE
	*/
#define  RX_Complete_Interrupt                 DISABLE
#define  TX_Complete_Interrupt                 DISABLE
#define  USART_Data_Register_Empty_Interrupt   DISABLE
#define  Receiver_Enable                       DISABLE
#define  Transmitter_Enable                    DISABLE




#endif