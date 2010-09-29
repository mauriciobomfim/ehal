#ifndef __PIN_H_
#define __PIN_H_

#include "types.h"
#include "pin_specific.h"

/* Pin Interface */
extern void	pin_high	(pin_t p);
extern void	pin_low		(pin_t p);

extern void	pin_in		(pin_t p);
extern void	pin_out		(pin_t p);

extern void	pin_value	(pin_t p);
extern void	pin_pullup	(pin_t p);
extern void	pin_nopullup	(pin_t p);
extern u08	pin_getdir	(pin_t p);
extern u08	pin_getpullup	(pin_t p);

extern bool	pin_validate	(pin_t p);

#endif
