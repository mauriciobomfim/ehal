#include "pio_specific.h"

pio_port pio_read (pio_port p, pio_port mask)
{
	switch(p){
		case 0: return PORTB & mask;
		default: break;
	}
}
