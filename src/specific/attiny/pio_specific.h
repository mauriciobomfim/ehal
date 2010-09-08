#include <avr/io.h>
#include "types.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

#define PIO_NUM_PORTS 1

typedef struct pio_pin_t {
	u08 port:4;
	u08 pin:4;
} pio_pin;

typedef u08 pio_port;
