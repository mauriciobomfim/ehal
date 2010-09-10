#include "pio_specific.h"

void pio3_write (pio_t val, pio_t mask)
{
	pio_mask (PIO_WRITE3, val, mask);
}

void pio3_dir (pio_t dir, pio_t mask)
{
	pio_mask (PIO_DIR3, ~dir, mask);
}

void pio3_pullup (pio_t up, pio_t mask)
{
	pio_mask (PIO_PULLUP3, up, mask);
}

pio_t pio3_read (pio_t mask)
{
	return PIO_READ3 & mask;
}
