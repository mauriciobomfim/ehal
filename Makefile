# /dev/null to discard the log or a filename to store it.
OUTPUT=
CP=cp
AVR_INCLUDE_INSTALL=$(which avr-gcc)
AVR_INSTALL_LIB_DIR=$(shell dirname $(shell which avr-gcc))/../avr/lib/

.PHONY: all doc clean avr all-avr all-avr-clean

all: avr lpc21xx
	@echo
	@echo done!

doc:
	make -C doc -f Makefile all

clean: avr-clean

############################ AVR #######################################

avr:
	@echo
	@echo building AVRs ...
	# tiny
	make -f Makefile.avr ARCH=avr MCU=attiny25 clean	$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=attiny25		$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=attiny25 install 	$(OUTPUT)
	# mega
	make -f Makefile.avr ARCH=avr MCU=atmega88 clean	$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega88		$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega88 install 	$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega128 clean	$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega128		$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega128 install 	$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega8 clean		$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega8		$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega8 install 	$(OUTPUT)

avr-clean:
	make -f Makefile.avr ARCH=avr MCU=atmega88 clean	$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega128 clean	$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=attiny25 clean	$(OUTPUT)
	make -f Makefile.avr ARCH=avr MCU=atmega8 clean		$(OUTPUT)

############################ LPC21XX @###################################

lpc21xx:
	@echo
	@echo building LPC21xx ...
	make -f Makefile.lpc21xx ARCH=lpc21xx MCU=lpc2101 clean	$(OUTPUT)
	make -f Makefile.lpc21xx ARCH=lpc21xx MCU=lpc2101	$(OUTPUT)
	make -f Makefile.lpc21xx ARCH=lpc21xx MCU=lpc2101 install $(OUTPUT)

