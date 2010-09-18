# /dev/null to discard the log or a filename to store it.
OUTPUT=log
CP=cp
AVR_INCLUDE_INSTALL=$(which avr-gcc)
AVR_INSTALL_LIB_DIR=$(shell dirname $(shell which avr-gcc))/../avr/lib/

.PHONY: all doc clean avr all-avr all-avr-clean

all: avr
	@echo
	@echo done!

doc:
	make -C doc -f Makefile all

clean: avr-clean

install: avr-install

avr:
	@echo
	@echo building AVRs ...
	# FIXME: Is the clearing realy needed? Find solution.
# mega
	make -f Makefile.avr ARCH=avr MCU=atmega8 clean		>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega8		>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega88 clean	>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega88		>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega128 clean	>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega128		>> $(OUTPUT)
# tiny
	make -f Makefile.avr ARCH=avr MCU=attiny25 clean	>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=attiny25		>> $(OUTPUT)

avr-clean:
	make -f Makefile.avr ARCH=avr MCU=atmega8 clean		>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega88 clean	>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega128 clean	>> $(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=attiny25 clean	>> $(OUTPUT)

avr-install: all-avr
	make -f Makefile.avr install ARCH=avr MCU=atmega8	>> $(OUTPUT)
	make -f Makefile.avr install ARCH=avr MCU=atmega88	>> $(OUTPUT)
	make -f Makefile.avr install ARCH=avr MCU=atmega128	>> $(OUTPUT)
	make -f Makefile.avr install ARCH=avr MCU=attiny25	>> $(OUTPUT)
