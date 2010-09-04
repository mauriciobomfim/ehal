#include <avr/io.h>
#include "types.h"

typedef struct pio_pin_t {
	u08 port:4;
	u08 pin:4;
} pio_pin;

typedef u08 pio_port;
