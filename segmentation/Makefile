ALGOS=arbol-compr arbol arreglo
EXES=$(ALGOS:=.algo) scripts/generar_ppm

ALGO ?= arbol-compr
BLUR ?= 1x0.6
K    ?= 600

all: main.o $(EXES)

clean:
	rm -f main.o $(EXES) entradas/* salidas/*

%.algo: main.o ds-%.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

entradas/$(BLUR).%.png: entradas-posta/%
	convert $^ -gaussian-blur $(BLUR) -colorspace gray $@

entradas/$(BLUR).%.txt: entradas/$(BLUR).%.png
	scripts/foto2entrada.sh $^ > $@

salidas/$(BLUR).%.$(K).txt: entradas/$(BLUR).%.txt $(ALGO).algo
	./$(ALGO).algo $(K) < entradas/$(BLUR).$*.txt > $@

salidas/$(BLUR).%.$(K).png: salidas/$(BLUR).%.$(K).txt scripts/generar_ppm
	scripts/salida2foto.sh $^ > $@

ver_%: salidas/$(BLUR).%.$(K).png
	feh $^

.PHONY: all clean ver_%
.PRECIOUS: entradas/$(BLUR).%.txt entradas/$(BLUR).%.png \
	   salidas/$(BLUR).%.$(K).txt salidas/$(BLUR).%.$(K).png
