#include "port.h"

#define port_mask(p, m, v) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

port_t port_getdir (void *_p)
{
	struct port_mem_block *p = _p;
	return ~p->dir;
}
