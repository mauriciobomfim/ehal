#include "pio_specific.h"

u08 pio_port_validate (pio_port p)
{
	return p < PIO_NUM_PORTS;
}
