#ifndef __SPIM_SPECIFIC_H
#define __SPIM_SPECIFIC_H

#include <avr/io.h>
#include "types.h"

#define spim_mask(p, v, m) do { p = ((p) & ~(m)) | ((v) & (m)); } while(0)

typedef u08 spim_t;

void spim0_init (u08 freq, u08 cpol, u08 cpha);
spim_t spim0_xmit (spim_t data);

#endif
