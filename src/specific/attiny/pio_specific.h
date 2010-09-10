#include <avr/io.h>
#include "types.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

typedef struct pio_pin_t {
	u08 port:4;
	u08 pin:4;
} pio_pin;

typedef u08 pio_t;

#if	defined(_AVR_ITN25_H_)	||\
	defined(_AVR_ITN45_H_)	||\
	defined(_AVR_ITN85_H_)
/*-- write --*/
#define PIO_WRITE0	PORTB
/*-- read --*/
#define PIO_READ0	PINB
/*-- direction --*/
#define PIO_DIR0	DDRB
/*-- pullup --*/
#define PIO_PULLUP0	PORTB

#else

/*-- write --*/
#define PIO_WRITE0	PORTB
/*-- read --*/
#define PIO_READ0	PINB
/*-- direction --*/
#define PIO_DIR0	DDRB
/*-- pullup --*/
#define PIO_PULLUP0	PORTB

#endif


