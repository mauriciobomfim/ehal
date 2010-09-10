#include "pio_specific.h"

void pio0_write (pio_t val, pio_t mask)
{
	pio_mask (PIO_WRITE0, val, mask);
}

void pio0_dir (pio_t dir, pio_t mask)
{
	pio_mask (PIO_DIR0, ~dir, mask);
}

void pio0_pullup (pio_t up, pio_t mask)
{
	pio_mask (PIO_PULLUP0, up, mask);
}

pio_t pio0_read (pio_t mask)
{
	return PIO_READ0 & mask;
}
