#include "pio_specific.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

void pio_port_valmask (pio_port p, pio_port val, pio_port mask)
{
	switch(p){
		case 0: pio_mask(PORTB, val, mask); break;
		case 1: pio_mask(PORTC, val, mask); break;
		case 2: pio_mask(PORTD, val, mask); break;
		default: break;
	}
}

void pio_port_dirmask (pio_port p, pio_port val, pio_port mask)
{
	switch(p){
		case 0: pio_mask(DDRB, val, mask); break;
		case 1: pio_mask(DDRC, val, mask); break;
		case 2: pio_mask(DDRD, val, mask); break;
		default: break;
	}

}

void pio_port_pullupmask (pio_port p, pio_port val, pio_port mask)
{
	switch(p){
		case 0: pio_mask(PORTB, val, mask); break;
		case 1: pio_mask(PORTC, val, mask); break;
		case 2: pio_mask(PORTD, val, mask); break;
		default: break;
	}

}

pio_port pio_port_readmask (pio_port p, pio_port mask)
{
	switch(p){
		case 0: return PORTB & mask;
		case 1: return PORTC & mask;
		case 2: return PORTD & mask;
		default: return 0;
	}
}

u08 pio_port_validate (pio_port p)
{
	return p < 3;
}

