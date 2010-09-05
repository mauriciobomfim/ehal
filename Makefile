all: avr

avr:
	make -f Makefile.avr MCU=$(MCU) ARCH=$(ARCH)

all-avr:
	make -f Makefile.avr clean MCU=atmega8 ARCH=atmega
	make -f Makefile.avr MCU=atmega8 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega88 ARCH=atmega
	make -f Makefile.avr MCU=atmega88 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega16 ARCH=atmega
	make -f Makefile.avr MCU=atmega16 ARCH=atmega

clean:
	make -f Makefile.avr clean
