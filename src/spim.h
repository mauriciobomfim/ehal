#ifndef __SPIM_H_
#define __SPIM_H_

#include "spim_specific.h"

#define spim_init( x, y, w, z ) GLUE( spim, GLUE( x, _init( y, w, z )) )

#endif
