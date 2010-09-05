all: avr
	@echo $(MCU)

avr:
ifeq ($(ARCH),avr)
	make -f Makefile.avr MCU=$(MCU)
endif

clean:
	make -f Makefile.avr clean
