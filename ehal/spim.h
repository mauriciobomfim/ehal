/** @defgroup SPIM
 * @{
 */

#ifndef __SPIM_H_
#define __SPIM_H_

#include "spim_specific.h"

/** @param n -  n spim number, @param freq - is the spi frequency, @param
 * cpol - is the polarity @param cpha - is the phase. */
#define spim_init( n, freq, cpol, cpha )	\
	 GLUE( spim, GLUE( n, _init( freq, cpol, cpha )) )

/** @param n - is the spim number, @param data - is the data with spi_t
 * type. @return spi_t with the slave response. */
#define spim_xmit( n, data )			\
	 GLUE( spim, GLUE( n, _xmit( data ) ) )

#endif

/** @} */ /* group SPIM */
