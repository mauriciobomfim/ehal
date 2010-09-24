/** @file
 * @brief 
 * @defgroup pio PIO
 * @{
 */
#ifndef __GENERIC_PIO_H
#define __GENERIC_PIO_H

#include "types.h"
#include "pio_specific.h"

/* Wrap of pio operations, where the first argument is the port number.
 * This don't need any change for adding a new port, change pio_specif.h
 * for this. Also, GLUE is defined at types.h */

u08 pio_write	(u08 p, pio_t mask, pio_t val);
u08 pio_dir	(u08 p, pio_t mask, pio_t dir);
u08 pio_pullup	(u08 p, pio_t mask, pio_t up);
u08 pio_read	(u08 p, pio_t mask, pio_t *read);

/** @} */

/** @brief helper for generating the pio_pin enum. @see pio_pin_names */
#define PIO_PIN_NAME(X) ((pio_t)1<<(X))

/** Macro to refer to all pins of a given PORT,
 * pio_write (0, 0, PIO_ALL_PINS); */
#define PIO_ALL_PINS		((pio_t)-1)

/* Pin symbolic names for easy usage. */
/** @brief Each P is the 1<<N where N is its number. This avoid (1<<N) for
 * the user.*/
enum pio_pin_names {
	P0  = PIO_PIN_NAME( 0),
	P1  = PIO_PIN_NAME( 1),
	P2  = PIO_PIN_NAME( 2),
	P3  = PIO_PIN_NAME( 3),
	P4  = PIO_PIN_NAME( 4),
	P5  = PIO_PIN_NAME( 5),
	P6  = PIO_PIN_NAME( 6),
	P7  = PIO_PIN_NAME( 7),
	P8  = PIO_PIN_NAME( 8),
	P9  = PIO_PIN_NAME( 9),
	P10 = PIO_PIN_NAME(10),
	P11 = PIO_PIN_NAME(11),
	P12 = PIO_PIN_NAME(12),
	P13 = PIO_PIN_NAME(13),
	P14 = PIO_PIN_NAME(14),
	P15 = PIO_PIN_NAME(15),
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
};
#undef PIO_PIN_NAME

#endif

/**@} */ /* end of PIO group */
