ALGOS=arbol-compr arbol arreglo
EXES=$(ALGOS:=.algo)
VECES=150

all: variar-k variar-g

salidas/arbol-compr.$(K).$(G).txt: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arbol-compr.algo < entrada.txt; \
	done >resultados/arbol-compr.$(K).$(G).txt 2> salidas/arbol-compr.$(K).$(G).txt

salidas/arbol.$(K).$(G).txt: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arbol.algo < entrada.txt; \
	done >resultados/arbol.$(K).$(G).txt 2> salidas/arbol.$(K).$(G).txt

salidas/arreglo.$(K).$(G).txt: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arreglo.algo < entrada.txt; \
	done >resultados/arreglo.$(K).$(G).txt 2> salidas/arreglo.$(K).$(G).txt

variar-k: binarios-actualizados
	for i in $$(seq 0 1200 50); do \
		$(MAKE) K=$$i G=-1 salidas/arreglo.$$i.-1.txt \
			salidas/arbol.$$i.-1.txt salidas/arbol-compr.$$i.-1.txt; \
	done; \
	touch variar-k.done

variar-g: binarios-actualizados
	for i in $$(seq 0 1200 150); do \
		for j in $$(seq 1 1000 10); do \
			$(MAKE) K=$$i G=$$j salidas/arreglo.$$i.$$j.txt \
				salidas/arbol.$$i.$$j.txt \
				salidas/arbol-compr.$$i.$$j.txt; \
		done; \
	done; \
	touch variar-g.done

binarios-actualizados:
	$(MAKE) -C ../ all

.PHONY: binarios-actualizados variar-k variar-g all
