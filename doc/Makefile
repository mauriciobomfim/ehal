# You must have a UNIX system to run this!
DOT=dot
DOCGEN=asciidoc
RM=rm -f

# Targets, files to build.
MANUAL=	index.html	\
	manual/pio.html

EXTRA=	../LOG.html	\
	../README.html	\
	../LICENCE.html

HTML=$(MANUAL) $(EXTRA)

%.html:%.txt
	$(DOCGEN) $<

.PHONY: html all clean
html:$(HTML)

all:$(HTML)

clean:
	$(RM) $(HTML)
