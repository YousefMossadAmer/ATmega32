
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR (volatile uint8_t *)0x2D

#define SPCR_SPR0 0
#define SPCR_SPR1 1
#define SPCR_CPHA 2
#define SPCR_CPOL 3
#define SPCR_MSTR 4
#define SPCR_DORD 5
#define SPCR_SPE  6
#define SPCR_SPIE 7


#define SPDR (volatile uint8_t *)0x2F


#define SPSR (volatile uint8_t *)0x2E
#define SPSR_SPI2X 0
#define SPSR_WCOL  6
#define SPSR_SPIF  7





#endif