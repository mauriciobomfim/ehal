#ifndef __PIO_SPECIFIC_H
#define __PIO_SPECIFIC_H

#include <avr/io.h>
#include "types.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

typedef struct pio_pin_t {
	u08 port:4;
	u08 pin:4;
} pio_pin;

typedef u08 pio_t;

#if	defined(_AVR_IOTN25_H_) ||\
	defined(_AVR_IOTN45_H_) ||\
	defined(_AVR_IOTN85_H_)
#define PIO_WRITE0	PORTB
#define PIO_READ0	PINB
#define PIO_DIR0	DDRB
#define PIO_PULLUP0	PORTB
#define PIO_NUM_PORTS	1


#elif	defined(_AVR_IOM8_H_)	||\
	defined(_AVR_IOM48_H_)	||\
	defined(_AVR_IOM88_H_)	||\
	defined(_AVR_IOM168_H_)	||\
	defined(_AVR_IOM328_H_)
#define PIO_WRITE0	PORTB
#define PIO_WRITE1	PORTC
#define PIO_WRITE2	PORTD

#define PIO_READ0	PINB
#define PIO_READ1	PINC
#define PIO_READ2	PIND

#define PIO_DIR0	DDRB
#define PIO_DIR1	DDRC
#define PIO_DIR2	DDRD

#define PIO_PULLUP0	PORTB
#define PIO_PULLUP1	PORTC
#define PIO_PULLUP2	PORTD
#define PIO_NUM_PORTS	3
#else


#define PIO_WRITE0	PORTA
#define PIO_WRITE1	PORTB
#define PIO_WRITE2	PORTC
#define PIO_WRITE3	PORTD
#define PIO_WRITE4	PORTE
#define PIO_WRITE5	PORTF
#define PIO_WRITE6	PORTG

#define PIO_READ0	PINA
#define PIO_READ1	PINB
#define PIO_READ2	PINC
#define PIO_READ3	PIND
#define PIO_READ4	PINE
#define PIO_READ5	PINF
#define PIO_READ6	PING

#define PIO_DIR0	DDRA
#define PIO_DIR1	DDRB
#define PIO_DIR2	DDRC
#define PIO_DIR3	DDRD
#define PIO_DIR4	DDRE
#define PIO_DIR5	DDRF
#define PIO_DIR6	DDRG

#define PIO_PULLUP0	PORTA
#define PIO_PULLUP1	PORTB
#define PIO_PULLUP2	PORTC
#define PIO_PULLUP3	PORTD
#define PIO_PULLUP4	PORTE
#define PIO_PULLUP5	PORTF
#define PIO_PULLUP6	PORTG
#define PIO_NUM_PORTS	7
#endif

/* functions that pio.c have to implement, one group for port. */
void pio0_write		(pio_t val, pio_t mask);
void pio0_dir		(pio_t in, pio_t mask);
void pio0_pullup	(pio_t up, pio_t mask);
pio_t pio0_read		(pio_t mask);

void pio1_write		(pio_t val, pio_t mask);
void pio1_dir		(pio_t in, pio_t mask);
void pio1_pullup	(pio_t up, pio_t mask);
pio_t pio1_read		(pio_t mask);

void pio2_write		(pio_t val, pio_t mask);
void pio2_dir		(pio_t in, pio_t mask);
void pio2_pullup	(pio_t up, pio_t mask);
pio_t pio2_read		(pio_t mask);

void pio3_write		(pio_t val, pio_t mask);
void pio3_dir		(pio_t in, pio_t mask);
void pio3_pullup	(pio_t up, pio_t mask);
pio_t pio3_read		(pio_t mask);

void pio4_write		(pio_t val, pio_t mask);
void pio4_dir		(pio_t in, pio_t mask);
void pio4_pullup	(pio_t up, pio_t mask);
pio_t pio4_read		(pio_t mask);

void pio5_write		(pio_t val, pio_t mask);
void pio5_dir		(pio_t in, pio_t mask);
void pio5_pullup	(pio_t up, pio_t mask);
pio_t pio5_read		(pio_t mask);

void pio6_write		(pio_t val, pio_t mask);
void pio6_dir		(pio_t in, pio_t mask);
void pio6_pullup	(pio_t up, pio_t mask);
pio_t pio6_read		(pio_t mask);

/* end of functions to implement */



#endif
