/** @file
 * @defgroup cpu cpu
 * @{
 */
#ifndef EHAL_CPU
#define EHAL_CPU
/* cpu_specific should contain:
 * (8 bits example)
 *
 * #define	CPU_SIZE	8
 * #define	CPU_TYPE	unsigned char
 * #define	CPU_FREQ	8000000L or for mutable frequencies
 * int		CPU_FREQ	8000000L
 */
#include "types.h"
#include "cpu_specific.h"

/* TODO complete description */
void
	cpu_global_int_en	(void);
void
	cpu_global_int_dis	(void);
void
	cpu_save_state		(void);
void
	cpu_load_state		(void);

#endif
/** @} */
