#include<stdio.h>
#include "port.h"
//#include "LPC17xx.h"
#include "port_specific.h"

#define BIND_INDEX_WITH_PORT(BLOCK_START)\
	(struct port_mem_block *) LPC_GPIO ## BLOCK_START

#if defined (ehal_lpc1768)
struct port_mem_block *port_mem_block[] = {
	BIND_INDEX_WITH_PORT(0),
	BIND_INDEX_WITH_PORT(1)
};
#else
#error MCU not defined in ehal/lpc17xx/port_init.c
#endif

#define port_mask(p, m, v) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

void *port_init (unsigned int id)
{
	void *p;
	if (id < sizeof(port_mem_block)/sizeof (*port_mem_block))
		p = port_mem_block[id];
	else
		return NULL;
	port_setdir (p, 0xFFFFFFFF, 0xFFFFFFFF);
	return p;
}
