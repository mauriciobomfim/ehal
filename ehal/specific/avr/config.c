#include "config.h"
/* PIO_BIND_WITH_INDEX binds the port letter with the array index. */

/* The letters must be upper case. */

#define PIO_BIND_WITH_INDEX(BLOCK_START)\
	(struct pio_mem_block *)&PIN ## BLOCK_START

#if defined (_AVR_IOTN25_H_)	\
	|| (_AVR_IOTN45_H_)	\
	|| (_AVR_IOTN85_H_)
struct pio_mem_block *pio_mem_block[] = {
	PIO_BIND_WITH_INDEX (B),
};

#elif defined (_AVR_IOM8_H_)	\
	|| (_AVR_IOM48_H_)	\
	|| (_AVR_IOM88_H_)	\
	|| (_AVR_IOM328_H_)
struct pio_mem_block *pio_mem_block[] = {
	PIO_BIND_WITH_INDEX (B),
	PIO_BIND_WITH_INDEX (C),
	PIO_BIND_WITH_INDEX (D),
};

#elif defined (_AVR_IOM16_H_)	\
	|| (_AVR_IOM32_H_)
struct pio_mem_block *pio_mem_block[] = {
	PIO_BIND_WITH_INDEX (A),
	PIO_BIND_WITH_INDEX (B),
	PIO_BIND_WITH_INDEX (C),
	PIO_BIND_WITH_INDEX (D),
};

#elif defined (_AVR_IOM164_H_)
struct pio_mem_block *pio_mem_block[] = {
	PIO_BIND_WITH_INDEX (A),
	PIO_BIND_WITH_INDEX (B),
	PIO_BIND_WITH_INDEX (C),
	PIO_BIND_WITH_INDEX (D),
};

#elif defined (_AVR_IOM128_H_)
struct pio_mem_block *pio_mem_block[] = {
	PIO_BIND_WITH_INDEX (A),
	PIO_BIND_WITH_INDEX (B),
	PIO_BIND_WITH_INDEX (C),
	PIO_BIND_WITH_INDEX (D),
	PIO_BIND_WITH_INDEX (E),
	PIO_BIND_WITH_INDEX (F),
	PIO_BIND_WITH_INDEX (G),
};

#endif
