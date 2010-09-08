all: avr


avr:
	make -f Makefile.avr MCU=$(MCU) ARCH=$(ARCH)

all-avr:
	# FIXME: Is the clearing realy needed? Find solution.
# mega
	make -f Makefile.avr clean MCU=atmega8 ARCH=atmega
	make -f Makefile.avr MCU=atmega8 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega88 ARCH=atmega
	make -f Makefile.avr MCU=atmega88 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega16 ARCH=atmega
	make -f Makefile.avr MCU=atmega16 ARCH=atmega
# tiny
	make -f Makefile.avr clean MCU=attiny25 ARCH=attiny
	make -f Makefile.avr MCU=attiny25 ARCH=attiny

avr-clean:
	make -f Makefile.avr clean

all-avr-clean:
	make -f Makefile.avr clean MCU=atmega8 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega88 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega16 ARCH=atmega
