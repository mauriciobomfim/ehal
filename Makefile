# /dev/null to discard the log or a filename to store it.
OUTPUT=/dev/null
CP=cp
AVR_INCLUDE_INSTALL=$(which avr-gcc)
AVR_INSTALL_LIB_DIR=$(shell dirname $(shell which avr-gcc))/../avr/lib/

all: all-avr
	@echo
	@echo done!

clean: all-avr-clean

avr:
	make -f Makefile.avr MCU=$(MCU) ARCH=$(ARCH)

all-avr:
	@echo
	@echo building AVRs ...
	# FIXME: Is the clearing realy needed? Find solution.
# mega
	make -f Makefile.avr ARCH=atmega MCU=atmega8 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega8		1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega88 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega88		1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega16 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega16		1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega128 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega128		1> $(OUTPUT)
# tiny
	make -f Makefile.avr ARCH=attiny MCU=attiny25 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=attiny MCU=attiny25		1> $(OUTPUT)

all-avr-clean:
	make -f Makefile.avr ARCH=atmega MCU=atmega8 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega88 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega16 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=atmega MCU=atmega128 clean	1> $(OUTPUT)
	make -f Makefile.avr ARCH=attiny MCU=attiny25 clean	1> $(OUTPUT)

avr-install: avr
	make -f Makefile.avr install ARCH=$(ARCH) MCU=$(MCU)

all-avr-install: all-avr
	make -f Makefile.avr install ARCH=atmega MCU=atmega8	1> $(OUTPUT)
	make -f Makefile.avr install ARCH=atmega MCU=atmega88	1> $(OUTPUT)
	make -f Makefile.avr install ARCH=atmega MCU=atmega16	1> $(OUTPUT)
	make -f Makefile.avr install ARCH=atmega MCU=atmega128	1> $(OUTPUT)
	make -f Makefile.avr install ARCH=attiny MCU=attiny25	1> $(OUTPUT)
	

install: avr-install
