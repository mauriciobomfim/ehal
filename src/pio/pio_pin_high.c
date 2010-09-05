#include "pio.h"

void pio_pin_high (pio_pin p)
{
	pio_port_valmask (p.port, (1<<p.pin), (1<<p.pin));
}
