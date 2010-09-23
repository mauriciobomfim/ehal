/** @file
 * @defgroup pio pio
 * @{
 * @defgroup pio_avr PIO_avr
 * @{
 * @brief This file contains the implementation details of the AVR port.
 */
#ifndef __PIO_SPECIFIC_H
#define __PIO_SPECIFIC_H

#include <avr/io.h>
#include "types.h"

typedef struct pio_pin_t {
	u08 port:4;
	u08 pin:4;
} pio_pin;

typedef u08 pio_t;

#endif

/** @} */ /* group PIO_AVR */
/** @} */ /* group PIO */
