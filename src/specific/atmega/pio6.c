#include "pio_specific.h"

void pio6_write (pio_t val, pio_t mask)
{
	pio_mask (PIO_WRITE6, val, mask);
}

void pio6_dir (pio_t dir, pio_t mask)
{
	pio_mask (PIO_DIR6, ~dir, mask);
}

void pio6_pullup (pio_t up, pio_t mask)
{
	pio_mask (PIO_PULLUP6, up, mask);
}

pio_t pio6_read (pio_t mask)
{
	return PIO_READ6 & mask;
}
