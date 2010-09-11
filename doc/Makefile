# Generates Doc from asciidoc .txt files.

DOT=dot
DOCGEN=asciidoc
RM=rm -f

# Targets, files to build.
MANUAL=	index.html	\
	manual/pio.html

EXTRA=	../LOG.html	\
	../README.html	\
	../LICENCE.html

GRAPH= arch.svg

HTML=$(MANUAL) $(EXTRA)

%.svg:%.dot
	$(DOT) -Tsvg $< -o $@

%.html:%.txt
	$(DOCGEN) $<

.PHONY: html all clean graph
html:$(HTML)

graph:$(GRAPH)

all:$(HTML) $(GRAPH)

clean:
	$(RM) $(HTML)
