fotos_segmentacion=segmentation/salidas/0.8.oso.jpg.600.100.png
graficos_segmentacion=graficos/grilla.pdf

graficos_cheapest=graficos/caminoSimple.pdf graficos/caminoSimple2.pdf \
		  graficos/caminoNoSimple.pdf

all: informe.pdf


segmentation/salidas/%.png:
	$(MAKE) -C segmentation \
		BLUR=$(word 1,$(subst ., ,$*)).$(word 2,$(subst ., ,$*)) \
		K=$(word 5,$(subst ., ,$*)) MIN=$(word 6,$(subst ., ,$*)) \
		salidas/$*.png
segmentation/%:
	$(MAKE) -C segmentation $*

cheapest-path/%:
	$(MAKE) -C cheapest-path $*

clean:
	rm -f informe.pdf informe.aux informe.log informe.fls \
		informe.fdb_latexmk
	$(MAKE) -C segmentation clean
	$(MAKE) -C graficos clean
	$(MAKE) -C cheapest-path clean

informe.pdf: informe.tex $(graficos_cheapest) $(tex_segmentacion) \
	$(graficos_segmentacion) $(fotos_segmentacion)
	latexmk -pdf informe.tex

graficos/%:
	$(MAKE) -C graficos $*

.PHONY: all clean segmentation/% cheapest-path/% graficos/%
