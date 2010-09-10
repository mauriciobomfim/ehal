#include "spim_specific.h"

void spim_init (u08 s, u08 freq, u08 cpol, u08 cpha);
u08 spim_send (u08 s, u08 data);
spim_t spim_xmit (u08 s, spim_t data);
