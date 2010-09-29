#ifndef __PIN_H_
#define __PIN_H_

#include "types.h"

struct pin_t {
	u08 port:4;
	u08 pin:4;
};

#endif
