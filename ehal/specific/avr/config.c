#include "config.h"
/* PORT_BIND_WITH_INDEX binds the port letter with the array index. */

/* The letters must be upper case. */

#define PORT_BIND_WITH_INDEX(BLOCK_START)\
	(struct port_mem_block *)&PIN ## BLOCK_START

#if defined (__AVR_ATtiny25__)	\
	|| (__AVR_ATtiny45__)	\
	|| (__AVR_ATtiny85__)
struct port_mem_block *port_mem_block[] = {
	PORT_BIND_WITH_INDEX (B),
};

#elif defined (__AVR_ATmega8__)	\
	|| (__AVR_ATmega48__)	\
	|| (__AVR_ATmega88__)
struct port_mem_block *port_mem_block[] = {
	PORT_BIND_WITH_INDEX (B),
	PORT_BIND_WITH_INDEX (C),
	PORT_BIND_WITH_INDEX (D),
};

#elif defined (_AVR_IOM16_H_)	\
	|| (_AVR_IOM32_H_)
struct port_mem_block *port_mem_block[] = {
	PORT_BIND_WITH_INDEX (A),
	PORT_BIND_WITH_INDEX (B),
	PORT_BIND_WITH_INDEX (C),
	PORT_BIND_WITH_INDEX (D),
};

#elif defined (_AVR_IOM164_H_)
struct port_mem_block *port_mem_block[] = {
	PORT_BIND_WITH_INDEX (A),
	PORT_BIND_WITH_INDEX (B),
	PORT_BIND_WITH_INDEX (C),
	PORT_BIND_WITH_INDEX (D),
};

#elif defined (_AVR_IOM128_H_)
struct port_mem_block *port_mem_block[] = {
	PORT_BIND_WITH_INDEX (A),
	PORT_BIND_WITH_INDEX (B),
	PORT_BIND_WITH_INDEX (C),
	PORT_BIND_WITH_INDEX (D),
	PORT_BIND_WITH_INDEX (E),
	PORT_BIND_WITH_INDEX (F),
	PORT_BIND_WITH_INDEX (G),
};

#endif
