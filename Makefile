fotos_segmentacion=segmentation/salidas/0.8.oso.jpg.500.100.png \
		   segmentation/salidas/0.8.sintetico.png.500.1000.png \
		   segmentation/salidas/0.0.mariquita.jpg.6000.-1.png \
		   segmentation/salidas/0.0.mariquita.jpg.0.1000.png \
		   segmentation/salidas/0.0.mariquita.jpg.600.-1.png \
		   segmentation/salidas/0.0.mariquita.jpg.600.1000.png \
		   segmentation/salidas/0.0.noche.jpg.600.-1.png \
		   segmentation/salidas/0.2.noche.jpg.600.-1.png \
		   segmentation/salidas/0.4.noche.jpg.600.-1.png \
		   segmentation/salidas/0.6.noche.jpg.600.-1.png \
		   segmentation/salidas/0.8.noche.jpg.600.-1.png \
		   segmentation/salidas/1.0.noche.jpg.600.-1.png \
		   segmentation/salidas/0.8.iglesia.jpg.600.-1.png \
		   segmentation/salidas/0.8.iglesia.jpg.600.1000.png \
		   segmentation/salidas/0.8.iglesia_2.jpg.600.-1.png \
		   segmentation/salidas/0.8.iglesia_2.jpg.600.1000.png \
		   segmentation/salidas/0.8.piramide_camello.jpg.300.-1.png \
		   segmentation/salidas/0.8.piramide_camello.jpg.300.1000.png
graficos_segmentacion=graficos/grilla.pdf
experimentos_segmentacion=segmentation/experimentacion/variar-k.pdf \
			  segmentation/experimentacion/variar-g-arreglo.pdf \
			  segmentation/experimentacion/variar-g-arbol.pdf \
			  segmentation/experimentacion/variar-g-arbol-compr.pdf
tex_segmentacion=$(wildcard segmentation/informe/*.tex)

graficos_cheapest=graficos/bidireccional.pdf graficos/direccional.pdf \
		  graficos/caminoNoSimple.pdf \
		  graficos/bellman_ford_correlacion.pdf \
		  graficos/dijkstra_correlacion.pdf \
		  graficos/expA_algos_todos.pdf graficos/expB_algos_todos.pdf \
		  graficos/floyd_warshall_correlacion.pdf \
		  graficos/pq_dijkstra_correlacion.pdf

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
	$(graficos_segmentacion) $(fotos_segmentacion) \
	$(experimentos_segmentacion)
	latexmk -pdf informe.tex

graficos/%:
	$(MAKE) -C graficos $*

segmentation/experimentacion/%:
	$(MAKE) -C segmentation/experimentacion $*

.PHONY: all clean segmentation/% cheapest-path/% graficos/%
