ALGOS=arbol-compr arbol arreglo
EXES=$(ALGOS:=.algo) scripts/generar_ppm

ALGO ?= arbol-compr
BLUR ?= 0.8
K    ?= 600
MIN  ?= -1

all: main.o $(EXES)

clean:
	rm -f main.o $(EXES) entradas/* salidas/*

%.algo: main.o ds-%.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

entradas/%.txt: entradas-posta/%
	scripts/foto2entrada.sh $^ > $@

salidas/$(BLUR).%.$(K).$(MIN).txt: entradas/%.txt $(ALGO).algo
	./$(ALGO).algo $(K) $(BLUR) $(MIN) < entradas/$*.txt > $@

salidas/$(BLUR).%.$(K).$(MIN).png: salidas/$(BLUR).%.$(K).$(MIN).txt \
				   scripts/generar_ppm
	scripts/salida2foto.sh $^ > $@

ver_%: salidas/$(BLUR).%.$(K).$(MIN).png
	xdg-open $^

ver_todo: $(subst entradas-posta/,ver_,$(wildcard entradas-posta/*))

.PHONY: all clean ver_%
.PRECIOUS: salidas/$(BLUR).%.$(K).$(MIN).txt \
	   salidas/$(BLUR).%.$(K).$(MIN).png entradas/%.txt
