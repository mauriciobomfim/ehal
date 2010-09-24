#ifndef __CONFIG_H_
#define __CONFIG_H_

#include <avr/io.h>
#include "types.h"

#if defined (_AVR_IOTN25_H_)	\
	|| (_AVR_IOTN45_H_)	\
	|| (_AVR_IOTN85_H_)
#define PIO_SIZE 1

#elif defined (_AVR_IOM8_H_)	\
	|| (_AVR_IOM48_H_)	\
	|| (_AVR_IOM88_H_)	\
	|| (_AVR_IOM328_H_)
#define PIO_SIZE 2

#elif defined (_AVR_IOM16_H_)	\
	|| (_AVR_IOM32_H_)
#define PIO_SIZE 4

#elif defined (_AVR_IOM164_H_)
#define PIO_SIZE 4

#elif defined (_AVR_IOM128_H_)
#define PIO_SIZE 7

#endif

struct pio_mem_block {
	volatile u08 read;
	volatile u08 dir;
	volatile u08 write;
};

struct spi_mem_block {
	volatile u08 dummy;
};

struct uart_mem_block {
	volatile u08 dummy;
};

/* defined in config.c */
extern struct pio_mem_block *pio_mem_block[];
extern struct uart_mem_block *uart_mem_block[];

#endif	/* __CONFIG_H_ */
