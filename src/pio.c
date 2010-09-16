#include "types.h"
#include "pio_specific.h"

#if (PIO_NUM_PORTS > 8)
#error ports larger than 8 are not inplemented
#endif

u08 pio_rt_write (u08 p, pio_t value, pio_t mask)
{
	switch(p){
#if   (PIO_NUM_PORTS > 0)
		case 0: pio0_write (value, mask); return 1;
#elif (PIO_NUM_PORTS > 1)
		case 1: pio1_write (value, mask); return 1;
#elif (PIO_NUM_PORTS > 2)
		case 2: pio2_write (value, mask); return 1;
#elif (PIO_NUM_PORTS > 3)
		case 3: pio3_write (value, mask); return 1;
#elif (PIO_NUM_PORTS > 4)
		case 4: pio4_write (value, mask); return 1;
#elif (PIO_NUM_PORTS > 5)
		case 5: pio5_write (value, mask); return 1;
#elif (PIO_NUM_PORTS > 6)
		case 6: pio6_write (value, mask); return 1;
#elif (PIO_NUM_PORTS > 7)
		case 7: pio7_write (value, mask); return 1;
#elif (PIO_NUM_PORTS > 8)
		case 8: pio8_write (value, mask); return 1;
#endif
		default: break;
	}
	return 0;
}

u08 pio_rt_dir (u08 p, pio_t direction, pio_t mask)
{
	switch(p){
#if (PIO_NUM_PORTS > 0)
		case 0: pio0_write (direction, mask); return 1;
#elif (PIO_NUM_PORTS > 1)
		case 1: pio1_write (direction, mask); return 1;
#elif (PIO_NUM_PORTS > 2)
		case 2: pio2_write (direction, mask); return 1;
#elif (PIO_NUM_PORTS > 3)
		case 3: pio3_write (direction, mask); return 1;
#elif (PIO_NUM_PORTS > 4)
		case 4: pio4_write (direction, mask); return 1;
#elif (PIO_NUM_PORTS > 5)
		case 5: pio5_write (direction, mask); return 1;
#elif (PIO_NUM_PORTS > 6)
		case 6: pio6_write (direction, mask); return 1;
#elif (PIO_NUM_PORTS > 7)
		case 7: pio7_write (direction, mask); return 1;
#elif (PIO_NUM_PORTS > 8)
		case 8: pio8_write (direction, mask); return 1;
#endif
		default: break;
	}
	return 0;
}

u08 pio_rt_pullup (u08 p, pio_t pullup, pio_t mask)
{
	switch(p){
#if (PIO_NUM_PORTS > 0)
		case 0: pio0_write (pullup, mask); return 1;
#elif (PIO_NUM_PORTS > 1)
		case 1: pio1_write (pullup, mask); return 1;
#elif (PIO_NUM_PORTS > 2)
		case 2: pio2_write (pullup, mask); return 1;
#elif (PIO_NUM_PORTS > 3)
		case 3: pio3_write (pullup, mask); return 1;
#elif (PIO_NUM_PORTS > 4)
		case 4: pio4_write (pullup, mask); return 1;
#elif (PIO_NUM_PORTS > 5)
		case 5: pio5_write (pullup, mask); return 1;
#elif (PIO_NUM_PORTS > 6)
		case 6: pio6_write (pullup, mask); return 1;
#elif (PIO_NUM_PORTS > 7)
		case 7: pio7_write (pullup, mask); return 1;
#elif (PIO_NUM_PORTS > 8)
		case 8: pio8_write (pullup, mask); return 1;
#endif
		default: break;
	}
	return 0;
}

u08 pio_rt_read (u08 p, pio_t mask, pio_t *value)
{
	switch(p){
#if (PIO_NUM_PORTS > 0)
		case 0: *value = pio0_read (mask); return 1;
#elif (PIO_NUM_PORTS > 1)
		case 1: *value = pio1_read (mask); return 1;
#elif (PIO_NUM_PORTS > 2)
		case 2: *value = pio2_read (mask); return 1;
#elif (PIO_NUM_PORTS > 3)
		case 3: *value = pio3_read (mask); return 1;
#elif (PIO_NUM_PORTS > 4)
		case 4: *value = pio4_read (mask); return 1;
#elif (PIO_NUM_PORTS > 5)
		case 5: *value = pio5_read (mask); return 1;
#elif (PIO_NUM_PORTS > 6)
		case 6: *value = pio6_read (mask); return 1;
#elif (PIO_NUM_PORTS > 7)
		case 7: *value = pio7_read (mask); return 1;
#elif (PIO_NUM_PORTS > 8)
		case 8: *value = pio8_read (mask); return 1;
#endif
		default: break;
	}
	return 0;
}

u08 pio_exists (u08 port)
{
	return port < PIO_NUM_PORTS;
}
