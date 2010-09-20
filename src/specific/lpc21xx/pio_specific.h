/** @file
 * @defgroup pio pio
 * @{
 * @defgroup pio_lpc21xx PIO LPC21xx
 * @{
 * @brief This file contains the implementation details of the LPC21xx port.
 */
#ifndef __PIO_SPECIFIC_H
#define __PIO_SPECIFIC_H

#include "types.h"

typedef struct pio_pin_t {
	u32 port:16;
	u32 pin:16;
} pio_pin;

typedef u32 pio_t;

#endif

/** @} */ /* group pio lpc21xx */
/** @} */ /* group pio */
