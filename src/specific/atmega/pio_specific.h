#include <avr/io.h>
#include "types.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

typedef struct pio_pin_t {
	u08 port:4;
	u08 pin:4;
} pio_pin;

typedef u08 pio_t;

#if	defined(_AVR_IOM8_H_)	||\
	defined(_AVR_IOM48_H_)	||\
	defined(_AVR_IOM88_H_)	||\
	defined(_AVR_IOM168_H_)	||\
	defined(_AVR_IOM328_H_)
/*-- write --*/
#define PIO_WRITE0	PORTB
#define PIO_WRITE1	PORTC
#define PIO_WRITE2	PORTD
/*-- read --*/
#define PIO_READ0	PINB
#define PIO_READ1	PINC
#define PIO_READ2	PIND
/*-- direction --*/
#define PIO_DIR0	DDRB
#define PIO_DIR1	DDRC
#define PIO_DIR2	DDRD
/*-- pullup --*/
#define PIO_PULLUP0	PORTB
#define PIO_PULLUP1	PORTC
#define PIO_PULLUP2	PORTD

#else

/*-- write --*/
#define PIO_WRITE0	PORTA
#define PIO_WRITE1	PORTB
#define PIO_WRITE2	PORTC
#define PIO_WRITE3	PORTD
#define PIO_WRITE4	PORTE
#define PIO_WRITE5	PORTF
#define PIO_WRITE6	PORTG
/*-- read --*/
#define PIO_READ0	PINA
#define PIO_READ1	PINB
#define PIO_READ2	PINC
#define PIO_READ3	PIND
#define PIO_READ4	PINE
#define PIO_READ5	PINF
#define PIO_READ6	PING
/*-- direction --*/
#define PIO_DIR0	DDRA
#define PIO_DIR1	DDRB
#define PIO_DIR2	DDRC
#define PIO_DIR3	DDRD
#define PIO_DIR4	DDRE
#define PIO_DIR5	DDRF
#define PIO_DIR6	DDRG
/*-- pullup --*/
#define PIO_PULLUP0	PORTA
#define PIO_PULLUP1	PORTB
#define PIO_PULLUP2	PORTC
#define PIO_PULLUP3	PORTD
#define PIO_PULLUP4	PORTE
#define PIO_PULLUP5	PORTF
#define PIO_PULLUP6	PORTG

#endif
