#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "uart.h"

#define SET_UBRR(baud, fcpu)	(fcpu/(16*baud
#define UART(n)	(struct uart_mem_block *)&UCSR ## n ## A

struct uart_mem_block {
	volatile u08 ucsra;
	volatile u08 ucsrb;
	volatile u08 ucsrc;
	volatile u08 ubrrl;
	volatile u08 ubrrh;
	volatile u08 udr;
};

struct uart_mem_block *uart_mem_block[] = {
	UART(0),
	UART(1),
};

static struct queue tx[UART_NUM];
static struct queue rx[UART_NUM];

/* callbacks */
static uart_fn on_txempty = 0;
static uart_fn on_rxfull = 0;

void uart_init (u08 id)
{
	uart_mem_block[id]->ucsra = (1<<U2X0);
	uart_mem_block[id]->ucsrb = (1<<RXEN0) | (1<<TXEN0)|(1<<RXCIE0);
	uart_mem_block[id]->ucsrc = 3<<UCSZ00;

}

#define ENTRY(_baud, _fcpu) B ## _baud:		\
	ubrr = _fcpu/(8UL*_baud) - 1;		\
	uart_mem_block[id]->ubrrl = ubrr >> 8;	\
	uart_mem_block[id]->ubrrh = ubrr
void uart_set_baud (u08 id, u08 baud, u32 fcpu)
{
	switch(baud){
		u32 ubrr;
	case ENTRY(   300, fcpu); break;
	case ENTRY(  1200, fcpu); break;
	case ENTRY(  2400, fcpu); break;
	case ENTRY(  4800, fcpu); break;
	default:
	case ENTRY(  9600, fcpu); break;
	case ENTRY( 19200, fcpu); break;
	case ENTRY(115200, fcpu); break;
	}
}

struct queue *uart_gettx (u08 id)
{
	return &tx[id];
}

struct queue *uart_getrx (u08 id)
{
	return &rx[id];
}

ISR(USART0_RX_vect)
{
	u08 tmp;
	// throw older away.
	if (queue_full (&rx[0]) && on_rxfull)
		on_rxfull(&rx[0]);
	queue_enq (&rx[0], UDR0);
}
