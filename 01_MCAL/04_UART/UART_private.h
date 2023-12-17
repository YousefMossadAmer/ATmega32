
#ifndef UART_PRIVATE_H_ 
#define UART_PRIVATE_H_

#define UDR   *((volatile uint8_t*)0x2c) 

#define UCSRA *((volatile uint8_t*)0x2b)
#define UCSRA_MPCM   0
#define UCSRA_U2X    1
#define UCSRA_PE     2
#define UCSRA_DOR    3
#define UCSRA_FE     4
#define UCSRA_UDRE   5
#define UCSRA_TXC    6
#define UCSRA_RXC    7


#define UCSRB *((volatile uint8_t*)0x2a)
#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE		5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3
#define UCSRB_UCSZ2		2
#define UCSRB_RXB8		1
#define UCSRB_TXB8		0


#define UCSRC *((volatile uint8_t*)0x40)
#define UCSRC_URSEL 	7
#define UCSRC_UMSEL		6
#define UCSRC_UPM1		5
#define UCSRC_UPM0		4
#define UCSRC_USBS		3
#define UCSRC_UCSZ1		2
#define UCSRC_UCSZ0		1
#define UCSRC_UCPOL		0


#define UBRRH *((volatile uint8_t*)0x40) 
#define UBRRH_URSEL		7

#define UBRRL *((volatile uint8_t*)0x29)



#define DISABLE       0
#define ENABLE        1

#define BIT_5   5
#define BIT_6   6
#define BIT_7   7
#define BIT_8   8
#define BIT_9   9


#define STOPBIT_1           1
#define STOPBIT_2           2


#define DISABLE_PARITY 0 
#define	ODD_PARITY     1
#define EVEN_PARITY    2


#define TX_RISING_XCK_RX_FALLING_XCK  0
#define TX_FALLING_XCK_RX_RISING_XCK  1



#endif