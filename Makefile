
all: informe.pdf

clean:
	rm -f informe.pdf informe.aux informe.log informe.fls \
		informe.fdb_latexmk
	$(MAKE) -C segmentation clean
	$(MAKE) -C graficos clean
	$(MAKE) -C cheapest-path clean

informe.pdf: informe.tex segmentation/informe/introduccion.tex \
	graficos/caminoSimple.pdf graficos/caminoSimple2.pdf \
	graficos/caminoNoSimple.pdf graficos/grilla.pdf
	latexmk -pdf informe.tex

graficos/%:
	$(MAKE) -C graficos $*

.PHONY: all clean graficos/%
