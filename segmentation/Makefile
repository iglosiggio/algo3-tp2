ALGOS=arbol-compr arbol arreglo
EXES=$(ALGOS:=.algo) scripts/generar_ppm

ALGO ?= arbol-compr
BLUR ?= 0.8
K    ?= 600

all: main.o $(EXES)

clean:
	rm -f main.o $(EXES) entradas/* salidas/*

%.algo: main.o ds-%.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

entradas/%.txt: entradas-posta/%
	scripts/foto2entrada.sh $^ > $@

salidas/$(BLUR).%.$(K).txt: entradas/%.txt $(ALGO).algo
	./$(ALGO).algo $(K) $(BLUR) < entradas/$*.txt > $@

salidas/$(BLUR).%.$(K).png: salidas/$(BLUR).%.$(K).txt scripts/generar_ppm
	scripts/salida2foto.sh $^ > $@

ver_%: salidas/$(BLUR).%.$(K).png
	feh $^

.PHONY: all clean ver_%
.PRECIOUS: salidas/$(BLUR).%.$(K).txt salidas/$(BLUR).%.$(K).png entradas/%.txt
