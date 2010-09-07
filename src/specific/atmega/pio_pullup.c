#include "pio_specific.h"

void pio_pullup (pio_port p, pio_port val, pio_port mask)
{
	switch(p){
#if defined(_AVR_IOM8_H_) \
	|| defined(_AVR_IOM48_H_) \
	|| defined(_AVR_IOM88_H_) \
	|| defined(_AVR_IOM168_H_)
		case 0: pio_mask(PORTB, val, mask); break;
		case 1: pio_mask(PORTC, val, mask); break;
		case 2: pio_mask(PORTD, val, mask); break;
#else
		case 0: pio_mask(PORTA, val, mask); break;
		case 1: pio_mask(PORTB, val, mask); break;
		case 2: pio_mask(PORTC, val, mask); break;
		case 3: pio_mask(PORTD, val, mask); break;
#endif
#if defined(_AVR_IOM128_H_)
		case 4: pio_mask(PORTE, val, mask); break;
		case 5: pio_mask(PORTF, val, mask); break;
		case 6: pio_mask(PORTG, val, mask); break;
#endif
		default: break;
	}

}
