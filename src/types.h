/** @file
 * @brief This file contains custom types and some general use macros. */
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
/** Get the number of elements of a static array */
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))
/** Intermediate macro for concatenation. @see GLUE */
#define GLUE2( x, y ) x ## y
/** Macro for concatenating 2 C tokens. */
#define GLUE( x, y ) GLUE2( x, y )

#endif
