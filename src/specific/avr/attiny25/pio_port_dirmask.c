#include "pio_specific.h"

void pio_port_dirmask (pio_port p, pio_port val, pio_port mask)
{
	switch(p){
		case 0: pio_mask(DDRB, val, mask); break;
		default: break;
	}

}
