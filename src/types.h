#ifndef __TYPES_H
#define __TYPES_H

/* custom types */
typedef unsigned char	u08;
typedef unsigned short	u16;
typedef unsigned int	u32;
typedef unsigned long	u64;

typedef signed char	s08;
typedef signed short	s16;
typedef signed int	s32;
typedef signed long	s64;

/* utilities */
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))
#define GLUE2( x, y ) x ## y
#define GLUE( x, y ) GLUE2( x, y )

#endif
