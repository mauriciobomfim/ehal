#include "types.h"
#include "lpc210x_gnuarm.h"
#include "pio_specific.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))

struct pio {
	volatile u32 *read;
	volatile u32 *set;
	volatile u32 *dir;
	volatile u32 *clear;
};

static const struct pio pio[] = {
	{ &GPIO0_IOPIN, &GPIO0_IOSET, &GPIO0_IODIR, &GPIO0_IOCLR },
};

u08 pio_write (u08 p, pio_t mask, pio_t val)
{
	if (p >= ARRAY_SIZE(pio)) return 1;
	*pio[p].set = mask & val;
	*pio[p].clear = mask & ~val;
	return 0;
}
u08 pio_dir (u08 p, pio_t mask, pio_t dir)
{
	if (p >= ARRAY_SIZE(pio)) return 1;
	pio_mask (*pio[p].dir, mask, dir);
	return 0;
}
u08 pio_pullup (u08 p, pio_t mask, pio_t up)
{
	return 0;
}

u08 pio_read (u08 p, pio_t mask, pio_t *read)
{
	return 0;
}
