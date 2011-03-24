#include <avr/io.h>
#include <avr/interrupt.h>
#include "queue.h"
#include "uart.h"
#include "uart_implementation.h"

u32 uart_getbaud (void *unused)
{
#if U2X_OFF
	return F_CPU/((UBRR0L+(UBRR0H << 8)+1)*8);
#else
	return F_CPU/((UBRR0L+(UBRR0H << 16)+1)*8);
#endif
}
