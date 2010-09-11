#ifndef __GENERIC_PIO_H
#define __GENERIC_PIO_H

#include "types.h"
#include "pio_specific.h"

/* Wrap of pio operations, where the first argument is the port number. */
#define pio_write( x, y, z)	GLUE(pio, GLUE(x, _write (y, z) ))
#define pio_dir( x, y, z)	GLUE(pio, GLUE(x, _dir (y, z) ))
#define pio_pullup( x, y, z)	GLUE(pio, GLUE(x, _pullup (y, z) ))
#define pio_read(x, y)		GLUE(pio, GLUE(x, _read(y) ))

/* Wrap for whole port operations. */
#define pio_write_port( x, y)	pio_write( x, y, (pio_t)-1)
#define pio_dir_port( x, y)	pio_dir( x, y, (pio_t)-1)
#define pio_pullup_port( x, y)	pio_pullup( x, y, (pio_t)-1)
#define pio_read_port(x)	pio_read( x, (pio_t)-1)

#define PIO_PIN_NAME(X) ((pio_t)1<<(X))

/* Pin symbolic names for easy usage. */
enum pio_pin_names {
	P0  = PIO_PIN_NAME( 0),
	P1  = PIO_PIN_NAME( 1),
	P2  = PIO_PIN_NAME( 2),
	P3  = PIO_PIN_NAME( 3),
	P4  = PIO_PIN_NAME( 4),
	P5  = PIO_PIN_NAME( 5),
	P6  = PIO_PIN_NAME( 6),
	P7  = PIO_PIN_NAME( 7),
#if PIO_SIZE > 8
	P8  = PIO_PIN_NAME( 8),
	P9  = PIO_PIN_NAME( 9),
	P10 = PIO_PIN_NAME(10),
	P11 = PIO_PIN_NAME(11),
	P12 = PIO_PIN_NAME(12),
	P13 = PIO_PIN_NAME(13),
	P14 = PIO_PIN_NAME(14),
	P15 = PIO_PIN_NAME(15),
#endif
#if PIO_SIZE > 16
	P16 = PIO_PIN_NAME(16),
	P17 = PIO_PIN_NAME(17),
	P18 = PIO_PIN_NAME(18),
	P19 = PIO_PIN_NAME(19),
	P20 = PIO_PIN_NAME(20),
	P21 = PIO_PIN_NAME(21),
	P22 = PIO_PIN_NAME(22),
	P23 = PIO_PIN_NAME(23),
	P24 = PIO_PIN_NAME(24),
	P25 = PIO_PIN_NAME(25),
	P26 = PIO_PIN_NAME(26),
	P27 = PIO_PIN_NAME(27),
	P28 = PIO_PIN_NAME(28),
	P29 = PIO_PIN_NAME(29),
	P30 = PIO_PIN_NAME(30),
	P31 = PIO_PIN_NAME(31),
#endif
};
#undef PIO_PIN_NAME

#endif
