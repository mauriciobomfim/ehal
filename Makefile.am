ARCH=virtual
MCU=.

AUTOMAKE_OPTIONS=foreign

noinst_LIBRARIES=libehau.a
libehau_a_SOURCES=$(pio_SOURCES)
libehau_a_CFLAGS=-mmcu=atmega8 -Os -Isrc -Isrc/modules/ -Isrc/specific/\
	-Isrc/specific/$(ARCH)/$(MCU)/

pio_SOURCES=\
	src/specific/$(ARCH)/$(MCU)/pio.c
