#ifndef __SPECIFIC_PIO_H
#define __SPECIFIC_PIO_H

#include "types.h"

typedef struct pio_pin_t {
	u32 port:16;
	u32 pin:16;
} pio_pin;

typedef u32 pio_port;

#endif
