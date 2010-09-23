#include "spim_specific.h"

#if	defined (_AVR_IOM8_H_)	|| \
	defined (_AVR_IOM48_H_) || \
	defined (_AVR_IOM88_H_)	|| \
	defined (_AVR_IOM168_H_)
#define DDR	DDRB
#define MOSI	_BV(PB3)
#define MISO	_BV(PB4)
#define CLK	_BV(PB5)
#define SS	_BV(PB2)
#else

#define DDR	DDRB
#define MOSI	_BV(PB3)
#define MISO	_BV(PB4)
#define CLK	_BV(PB5)
#define SS	_BV(PB2)
#endif

void spim0_init (u08 freq, u08 cpol, u08 cpha)
{
	spim_mask (DDR, (MOSI | CLK), (MOSI | MISO | CLK));
	SPCR = _BV(SPE)			/* SPI Enable */
		| _BV(MSTR)
		| _BV(cpol ? CPOL : 0)	/* Polarity */
		| _BV(cpha ? CPHA : 0)	/* Phase */
		| _BV(SPI2X);		/* SPI speed 2x */
}
/*
		| _BV(SPR1)		/ * * /
		| _BV(SPR0)		/ * * /
*/

spim_t spim0_xmit (spim_t data)
{
	SPDR = data;
	while( !(SPSR & _BV(SPIF)) )	/* wait ready */
		;
	return SPDR;
}
