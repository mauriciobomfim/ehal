#ifndef __UART_H_
#define __UART_H_

#include "types.h"
#include "uart_specific.h"
#include "queue.h"

/* callback funtion */
typedef void (*uart_fn)(u08 *buff, u08 sz);

extern void	uart_init		(u08 id);
extern u08	uart_validate		(u08 id);
extern u32	uart_cfg_freq		(u08 id, u32 f, u32 fcpu);

/* return a valid queue or NULL, also note that there will be one tx and one
 * rx per uart. so uart_validade also validate the number of queue pairs */
extern struct queue *uart_gettx_qp	(u08 id);
extern struct queue *uart_getrx_qp	(u08 id);

/* sends the data in the tx buffer. */
extern void	uart_send		(u08 id);

/* "events" for uart. For disabling, set as NULL. */
extern void	uart_on_txempty		(u08 id, uart_fn callback);
extern void	uart_on_rxfull		(u08 id, uart_fn callback);

#endif
