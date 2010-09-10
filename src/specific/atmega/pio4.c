#include "pio_specific.h"

void pio4_write (pio_t val, pio_t mask)
{
	pio_mask (PIO_WRITE4, val, mask);
}

void pio4_dir (pio_t dir, pio_t mask)
{
	pio_mask (PIO_DIR4, ~dir, mask);
}

void pio4_pullup (pio_t up, pio_t mask)
{
	pio_mask (PIO_PULLUP4, up, mask);
}

pio_t pio4_read (pio_t mask)
{
	return PIO_READ4 & mask;
}
