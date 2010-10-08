/** @ingroup pin
 * @{*/
#include "ehal/pin.h"

#define PORT	0
#define PIN0	P0
#define PIN1	P1

static struct pin_t pin0 = MAKE_PIN (PORT, PIN0);
static struct pin_t pin1 = MAKE_PIN (PORT, PIN1);

/* set to 1; set to 0. */
void toggle (void)
{
	pin_high (p);
	pin_low (p);
}

void loop (void)
{
	/* make sure we can use it. */
	if (!pin_is_valid (pin0)) return;

	/* configure to output if its an input. */
	if (pin_get_dir (pin0) == PIN_INPUT)
		pin_out (pin0);

	while (1) toogle();
}

void heads_or_tails (void)
{
	pin_out (pin0);
	/* set it to a random value. */
	pin_set (pin0, rand ());
}

void echo_pin (void)
{
	pin_out (pin0);

	pin_in (pin1);
	pin_pullup (pin1);

	while (1){
		/* pin0 is the echo of pin1. */
		pin_set (pin0, pin_get(pin1));
	}
}

/** @} ingrpup */
