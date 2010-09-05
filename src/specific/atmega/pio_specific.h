#include <avr/io.h>
#include "types.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

#if defined(_AVR_IOM8_H_) \
	|| defined(_AVR_IOM48_H_) \
	|| defined(_AVR_IOM88_H_) \
	|| defined(_AVR_IOM168_H_)
#define PIO_NUM_PORTS 3

#elif defined(_AVR_IOM128_H_)
#define PIO_NUM_PORTS 7

#else
#define PIO_NUM_PORTS 4

#endif

typedef struct pio_pin_t {
	u08 port:4;
	u08 pin:4;
} pio_pin;

typedef u08 pio_port;
