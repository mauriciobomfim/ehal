#include "pio_specific.h"

/* dummy port, for testing. */
volatile static pio_port port[3];
volatile static pio_port dir[3];
volatile static pio_port pullup[3];

#define pio_mask(b, v, m) do{ b = ((b) & ~(m)) | ((v) & (m)); } while(0)

void pio_port_valmask (pio_port p, pio_port val, pio_port mask)
{
	if( p >= ARRAY_SIZE(pullup) ) return;
	pio_mask (port[p], val, mask);
}

void pio_port_dirmask (pio_port p, pio_port in, pio_port mask)
{
	if( p >= ARRAY_SIZE(pullup) ) return;
	pio_mask (dir[p], in, mask);
}

void pio_port_pullupmask (pio_port p, pio_port up, pio_port mask)
{
	if( p >= ARRAY_SIZE(pullup) ) return;
	pio_mask (pullup[p], up, mask);
}

pio_port pio_port_readmask (pio_port p, pio_port mask)
{
	if( p >= ARRAY_SIZE(pullup) ) return;
	return port[p] & mask;
}
