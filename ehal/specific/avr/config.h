#ifndef __CONFIG_H_
#define __CONFIG_H_

#include <avr/io.h>
#include "types.h"

#if defined (__AVR_ATtiny25__)	\
	|| (__AVR_ATtiny45__)	\
	|| (__AVR_ATtiny85__)
#define PORT_SIZE 1

#elif defined (__AVR_ATmega8__)	\
	|| (__AVR_ATmega88__)	\
	|| (__AVR_ATmega168__)	\
	|| (__AVR_ATmega328__)
#define PORT_SIZE 4

#elif defined (__AVR_ATmega16__)\
	|| (__AVR_ATmega32__)
#define PORT_SIZE 4

#elif defined (__AVR_ATmega164P__)
#define PORT_SIZE 4

#elif defined (_AVR_IOM128_H_)
#define PORT_SIZE 7

#endif

struct port_mem_block {
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
extern struct port_mem_block *port_mem_block[];
extern struct uart_mem_block *uart_mem_block[];

#endif	/* __CONFIG_H_ */
