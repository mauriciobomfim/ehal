#include "pio_specific.h"
#include "config.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))

u08 pio_write (u08 p, pio_t mask, pio_t val )
{
	if (p >= PIO_SIZE) return 1;
	pio_mask (pio_mem_block[p]->write, val, mask);
	return 0;
}

/* same as pio_write for inputs. */
u08 pio_pullup(u08 p, pio_t mask, pio_t up)
	__attribute__ ((alias("pio_write")));

u08 pio_dir (u08 p, pio_t mask, pio_t dir)
{
	if (p >= PIO_SIZE) return 1;
	pio_mask (pio_mem_block[p]->dir, ~dir, mask);
	return 0;
}

u08 pio_read (u08 p, pio_t mask, pio_t *val )
{
	if (p >= PIO_SIZE) return 1;
	*val = pio_mem_block[p]->read;
	return 0;
}
