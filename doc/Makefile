# Generates Doc from asciidoc .txt files.

DOT=dot
DOCGEN=doxygen
RM=rm -f

GRAPH=modules.png

%.svg:%.dot
	$(DOT) -Tsvg $< -o $@

%.ps:%.dot
	$(DOT) -Tps $< -o $@

%.png:%.dot
	$(DOT) -Tpng $< -o $@



.PHONY: all clean graph html
all:$(GRAPH) pdf

html:
	$(DOXYGEN)

graph:$(GRAPH)

clean:
	$(RM) $(HTML) $(GRAPH)
pdf:
	mpost arch.mp
	pdflatex ehal.tex
