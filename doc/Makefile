# Generates Doc from asciidoc .txt files.

DOT=dot
DOCGEN=asciidoc
RM=rm -f

IMAGES=images
# Targets, files to build.
MANUAL=	index.html	\
	pio.html

EXTRA=	../LOG.html		\
	../README.html		\
	../LICENCE.html

HTML=$(MANUAL) $(EXTRA)
GRAPH=$(IMAGES)/arch.png

%.svg:%.dot
	$(DOT) -Tsvg $< -o $@

%.png:%.dot
	$(DOT) -Tpng $< -o $@

%.html:%.txt
	$(DOCGEN) $<

.PHONY: html all clean graph
all:$(HTML) $(GRAPH)

html:$(HTML)

graph:$(GRAPH)

clean:
	$(RM) $(HTML) $(GRAPH)
