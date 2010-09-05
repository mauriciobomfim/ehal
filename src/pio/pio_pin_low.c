#include "pio.h"

void pio_pin_low (pio_pin p)
{
	pio_port_valmask (p.port, (0<<p.pin), (1<<p.pin));
}
