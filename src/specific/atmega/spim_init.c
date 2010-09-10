#include "spim_specific.h"

#if defined (_AVR_IOM8_H_)
#define MOSI	_BV(PB3)
#define MISO	_BV(PB4)
#define CLK	_BV(PB5)
#define SS	_BV(PB2)
#else
#define MOSI	_BV(PB3)
#define MISO	_BV(PB4)
#define CLK	_BV(PB5)
#define SS	_BV(PB2)
#endif

void spim_init (u08 s, u08 freq, u08 cpol, u08 cpha)
{
	spim_mask (DDRB, ~(MOSI), (MOSI | MISO | CLK | SS));
	SPCR = _BV(SPE) /* SPI Enable */
		| _BV(MSTR)
		| _BV(cpol ? CPOL : 0)
		| _BV(cpha ? CPHA : 0)
		| _BV(SPR1)
		| _BV(SPR0)
		| _BV(SPI2X); /* SPI speed 2x */
}
