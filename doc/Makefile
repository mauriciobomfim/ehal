# Generates Doc from asciidoc .txt files.

DOT=dot
DOCGEN=doxygen
RM=rm -f

IMAGES=images
# Targets, files to build.

GRAPH=$(IMAGES)/arch.png

%.svg:%.dot
	$(DOT) -Tsvg $< -o $@

%.png:%.dot
	$(DOT) -Tpng $< -o $@

.PHONY: all clean graph html
all:$(GRAPH)

html:
	$(DOXYGEN)

graph:$(GRAPH)

clean:
	$(RM) $(HTML) $(GRAPH)
