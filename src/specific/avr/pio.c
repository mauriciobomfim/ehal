#include "pio_specific.h"

#define pio_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))

struct pio {
	volatile u08 *port;
	volatile u08 *dir;
	volatile u08 *read;
};

static const struct pio pio[] = {
#if	defined (_AVR_IOTN25_H_) || defined (_AVR_IOTN45_H_) \
	|| defined (_AVR_IOTN85_H_)
	{ &PORTB, &DDRB, &PINB },
#elif	defined (_AVR_IOTN2313_H_)
	{ &PORTB, &DDRB, &PINB },
	{ &PORTC, &DDRC, &PINC },
#elif	defined (_AVR_IOM16_H_) || defined (_AVR_IOM32_H_)
	{ &PORTA, &DDRA, &PINA },
	{ &PORTB, &DDRB, &PINB },
	{ &PORTC, &DDRC, &PINC },
	{ &PORTD, &DDRD, &PIND },
#elif	defined (_AVR_IOM8_H_) || defined (_AVR_IOM88_H_) \
	|| defined (_AVR_IOM168_H_)
	{ &PORTB, &DDRB, &PINB },
	{ &PORTC, &DDRC, &PINC },
	{ &PORTD, &DDRD, &PIND },
#elif	defined (_AVR_IOM128_H_)
	{ &PORTA, &DDRA, &PINA },
	{ &PORTB, &DDRB, &PINB },
	{ &PORTC, &DDRC, &PINC },
	{ &PORTD, &DDRD, &PIND },
	{ &PORTE, &DDRE, &PINE },
	{ &PORTF, &DDRF, &PINF },
	{ &PORTG, &DDRG, &PING },
#endif
};

u08 pio_write (u08 p, pio_t mask, pio_t val )
{
	if (p >= ARRAY_SIZE(pio)) return 1;
	pio_mask (*pio[p].port, val, mask);
	return 0;
}

/* same as pio_write when port is input. */
u08 pio_pullup(u08 p, pio_t mask, pio_t up)
	__attribute__ ((alias("pio_write")));

u08 pio_dir (u08 p, pio_t mask, pio_t dir)
{
	if (p >= ARRAY_SIZE(pio)) return 1;
	pio_mask (*pio[p].dir, ~dir, mask);
	return 0;
}

u08 pio_read (u08 p, pio_t mask, pio_t *val )
{
	if (p >= ARRAY_SIZE(pio)) return 1;
	*val = *pio[p].read;
	return 0;
}
