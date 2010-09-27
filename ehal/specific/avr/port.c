#include "port_specific.h"
#include "config.h"

#define port_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))

void port_write (u08 p, port_t mask, port_t val )
{
	port_mask (port_mem_block[p]->write, val, mask);
}

port_t port_read (u08 p, port_t mask)
{
	return port_mem_block[p]->read;
}

void port_set_pullup(u08 p, port_t mask, port_t up)
	__attribute__ ((alias("port_write")));

void port_set_dir (u08 p, port_t mask, port_t dir)
{
	port_mask (port_mem_block[p]->dir, ~dir, mask);
}

port_t port_get_dir (u08 p)
{
	return port_mem_block[p]->write;
}

u08 port_validate (u08 p)
{
	return p < PORT_SIZE;
}
