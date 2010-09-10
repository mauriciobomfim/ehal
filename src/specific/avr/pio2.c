#include "pio_specific.h"

void pio2_write (pio_t val, pio_t mask)
{
	pio_mask (PIO_WRITE2, val, mask);
}

void pio2_dir (pio_t dir, pio_t mask)
{
	pio_mask (PIO_DIR2, ~dir, mask);
}

void pio2_pullup (pio_t up, pio_t mask)
{
	pio_mask (PIO_PULLUP2, up, mask);
}

pio_t pio2_read (pio_t mask)
{
	return PIO_READ2 & mask;
}
