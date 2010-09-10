#include "pio_specific.h"

void pio5_write (pio_t val, pio_t mask)
{
	pio_mask (PIO_WRITE5, val, mask);
}

void pio5_dir (pio_t dir, pio_t mask)
{
	pio_mask (PIO_DIR5, ~dir, mask);
}

void pio5_pullup (pio_t up, pio_t mask)
{
	pio_mask (PIO_PULLUP5, up, mask);
}

pio_t pio5_read (pio_t mask)
{
	return PIO_READ5 & mask;
}
