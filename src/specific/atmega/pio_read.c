#include "pio_specific.h"

pio_port pio_read (pio_port p, pio_port mask)
{
	switch(p){
#if defined(_AVR_IOM8_H_) \
	|| defined(_AVR_IOM48_H_) \
	|| defined(_AVR_IOM88_H_) \
	|| defined(_AVR_IOM168_H_)
		case 0: return PORTB & mask;
		case 1: return PORTC & mask;
		case 2: return PORTD & mask;
#else
		case 0: return PORTA & mask;
		case 1: return PORTB & mask;
		case 2: return PORTC & mask;
		case 3: return PORTD & mask;
#endif
#if defined(_AVR_IOM128_H_)
		case 4: return PORTE & mask;
		case 5: return PORTF & mask;
		case 6: return PORTG & mask;
#endif
		default: return 0;
	}

}
