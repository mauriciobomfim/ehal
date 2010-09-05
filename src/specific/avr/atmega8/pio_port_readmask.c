#include "pio_specific.h"

pio_port pio_port_readmask (pio_port p, pio_port mask)
{
	switch(p){
		case 0: return PORTB & mask;
		case 1: return PORTC & mask;
		case 2: return PORTD & mask;
		default: return 0;
	}
}
