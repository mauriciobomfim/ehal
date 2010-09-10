#include "pio_specific.h"

void pio1_write (pio_t val, pio_t mask)
{
	pio_mask (PIO_WRITE1, val, mask);
}

void pio1_dir (pio_t dir, pio_t mask)
{
	pio_mask (PIO_DIR1, ~dir, mask);
}

void pio1_pullup (pio_t up, pio_t mask)
{
	pio_mask (PIO_PULLUP1, up, mask);
}

pio_t pio1_read (pio_t mask)
{
	return PIO_READ1 & mask;
}
