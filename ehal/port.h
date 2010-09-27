#ifndef __PORT_H_
#define __PORT_H_

#include "types.h"
#include "port_specific.h"

#define ALL_PINS	((port_t)-1)

/* Port Interface. */
extern void	port_write	(u08 p, port_t mask, port_t val);
extern port_t	port_read	(u08 p);

extern void	port_set_pullup	(u08 p, port_t mask, port_t val);
extern void	port_get_pullup	(u08 p, port_t mask, port_t val);
extern void	port_set_dir	(u08 p, port_t mask, port_t dir);
extern port_t	port_get_dir	(u08 p, port_t mask, port_t dir);

extern bool	port_validate	(u08 p);

#endif
