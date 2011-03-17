#include <stdio.h>
#include "LPC17xx.h"

#define ARRAY_SIZE(x) (sizeof (x)/sizeof (*x))
static void * port_mem_block[] = {
  LPC_GPIO1,
  LPC_GPIO2
};

void *port_init (unsigned int id)
{
  if (id >= ARRAY_SIZE (port_mem_block)) return NULL;
  return port_mem_block[id];
}

