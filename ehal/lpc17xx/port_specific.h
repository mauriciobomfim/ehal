#ifndef PORT_SPECIFIC_H
#define PORT_SPECIFIC_H

#include "LPC17xx.h"
#include "tinytypes.h"

/* Mapping of Port with port_ functions index.
 * The letters must be upper case. */
struct port_mem_block {
  volatile uint32_t dir; /* FIODIR */
  volatile uint32_t RESERVED0[3];
  volatile uint32_t mask; /* FIOMASK */
  volatile uint32_t data; /* FIOPIN */
  volatile uint32_t set;  /* FIOSET */
  volatile uint32_t clear; /* FIOCLR */
};

typedef u32 port_t;

#endif
