
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



#define SPI_ENABLE   1
#define	SPI_DISABLE  0


#define SPI_Interrupt_ENABLE   1
#define	SPI_Interrupt_DISABLE  0

#define	SPI_LSB_FIRIST 0
#define	SPI_MSB_FIRIST 1


#define	SPI_MASTER  0
#define	SPI_SLAVE   1


#define	SPI_LEADING_RISING_TRAILING_FALLING 0
#define SPI_LEADING_FALLING_TRAILING_RISING 1


#define	SPI_SAMPLE_LEADING_SETUP_TRAILING 0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING 1

#define SPI_FREQ_DIVIDED_BY_2    2
#define	SPI_FREQ_DIVIDED_BY_4    4
#define	SPI_FREQ_DIVIDED_BY_8    8
#define	SPI_FREQ_DIVIDED_BY_16   16
#define	SPI_FREQ_DIVIDED_BY_32   32
#define	SPI_FREQ_DIVIDED_BY_64   64
#define	SPI_FREQ_DIVIDED_BY_128  128
	

void SPI_voidinit(void);
void SPI_voidsend_recive_data(uint8_t data);


#endif