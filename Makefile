all: avr


avr:
ifneq ($(MCU), "")
	make -f Makefile.avr MCU=$(MCU) ARCH=$(ARCH)
endif

all-avr:
	make -f Makefile.avr clean MCU=atmega8 ARCH=atmega
	make -f Makefile.avr MCU=atmega8 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega88 ARCH=atmega
	make -f Makefile.avr MCU=atmega88 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega16 ARCH=atmega
	make -f Makefile.avr MCU=atmega16 ARCH=atmega

avr-clean:
	make -f Makefile.avr clean

all-avr-clean:
	make -f Makefile.avr clean MCU=atmega8 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega88 ARCH=atmega
	make -f Makefile.avr clean MCU=atmega16 ARCH=atmega
