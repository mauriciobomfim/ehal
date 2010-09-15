/** @file
 * @defgroup PIO
 * @{
 * @brief PIO API
 */
#ifndef __GENERIC_PIO_H
#define __GENERIC_PIO_H

#include "types.h"
#include "pio_specific.h"

/* Wrap of pio operations, where the first argument is the port number.
 * This don't need any change for adding a new port, change pio_specif.h
 * for this. Also, GLUE is defined at types.h */
/**@{
 * @param p is the port
 * @param v is the value (high/low; in/out; on/off)
 * @param m is the mask, that says which bits from the port will be changed.
 */

#define pio_write( p, v, m)	GLUE(pio, GLUE(p, _write (v, m) ))
#define pio_dir( p, v, m)	GLUE(pio, GLUE(p, _dir (v, m) ))
#define pio_pullup( p, v, m)	GLUE(pio, GLUE(p, _pullup (v, m) ))
#define pio_read(p, v)		GLUE(pio, GLUE(p, _read(m) ))
/**@}*/

/** @brief Runtime check of @a port existence */
u08 pio_exists (u08 port);

#define PIO_PIN_NAME(X) ((pio_t)1<<(X))
#define PIO_ALL		((pio_t)-1)

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

/**@} */ /* end of PIO group */
