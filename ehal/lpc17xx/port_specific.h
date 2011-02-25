#ifndef PORT_SPECIFIC_H
#define PORT_SPECIFIC_H

#include "tinytypes.h"

/* Mapping of Port with port_ functions index.
 * The letters must be upper case. */
struct port_mem_block {
	volatile uint32_t data;	/* FIOPIN */
	volatile uint32_t dir;	/* FIODIR */
};

typedef u32 port_t;

#endif
