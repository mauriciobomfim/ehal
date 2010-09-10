#include "spim_specific.h"

spim_t spi_xmit (u08 s, spim_t data)
{
	SPDR = data;
	while( SPSR & !_BV(SPIF) )
		;
	return SPDR;
}
