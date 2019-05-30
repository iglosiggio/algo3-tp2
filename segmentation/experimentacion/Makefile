ALGOS=arbol-compr arbol arreglo
EXES=$(ALGOS:=.algo)
VECES=150

all: variar-k variar-g

salidas/%.arbol-compr.txt: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arbol-compr.algo < entrada.txt >/dev/null; \
	done 2>> $@

salidas/%.arbol.txt: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arbol.algo < entrada.txt >/dev/null; \
	done 2>> $@

salidas/%.arreglo.txt: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arreglo.algo < entrada.txt >/dev/null; \
	done 2>> $@

variar-k: binarios-actualizados
	rm -f salidas/k.arreglo.txt salidas/k.arbol.txt salidas/k.arbol-compr.txt
	for i in $$(seq 0 1200 50); do \
		$(MAKE) K=$$i G=-1 salidas/k.arreglo.txt salidas/k.arbol.txt \
			salidas/k.arbol-compr.txt; \
	done \

variar-g: binarios-actualizados
	rm -f salidas/g.arreglo.txt salidas/g.arbol.txt salidas/g.arbol-compr.txt
	for i in $$(seq 0 1200 150); do \
		for j in $$(seq 1 1000 10); do \
			$(MAKE) K=$$i G=$$j salidas/g.arreglo.txt \
				salidas/g.arbol.txt salidas/g.arbol-compr.txt; \
		done; \
	done \

binarios-actualizados:
	$(MAKE) -C ../ all

.PHONY: binarios-actualizados variar-k variar-g all
.PRECIOUS: salidas/k.arreglo.txt salidas/k.arbol.txt salidas/k.arbol-compr.txt \
	salidas/g.arreglo.txt salidas/g.arbol.txt salidas/g.arbol-compr.txt
