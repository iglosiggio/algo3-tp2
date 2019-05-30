ALGOS=arbol-compr arbol arreglo
EXES=$(ALGOS:=.algo)
VECES=80

all: variar-k variar-g

salidas/%.arbol-compr.$(K).$(G).data: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arbol-compr.algo $(K) 0.8 $(G) < entrada.txt >/dev/null; \
	done 2>> $@

salidas/%.arbol.$(K).$(G).data: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arbol.algo $(K) 0.8 $(G) < entrada.txt >/dev/null; \
	done 2>> $@

salidas/%.arreglo.$(K).$(G).data: entrada.txt
	for i in $$(seq 1 $(VECES)); do \
		../arreglo.algo $(K) 0.8 $(G) < entrada.txt >/dev/null; \
	done 2>> $@

variar-k: binarios-actualizados
	rm -f salidas/k.arreglo.resultados salidas/k.arbol.resultados \
		salidas/k.arbol-compr.resultados
	for i in $$(seq 0 50 1200); do \
		$(MAKE) K=$$i G=-1 salidas/k.arreglo.$$i.-1.data \
			salidas/k.arbol.$$i.-1.data \
			salidas/k.arbol-compr.$$i.-1.data; \
	done
	cat salidas/k.arbol-compr.*.data > salidas/k.arbol-compr.resultados
	cat salidas/k.arbol.*.data > salidas/k.arbol.resultados
	cat salidas/k.arreglo.*.data > salidas/k.arreglo.resultados

variar-g: binarios-actualizados
	rm -f salidas/g.arreglo.resultados salidas/g.arbol.resultados \
		salidas/g.arbol-compr.resultados
	for i in $$(seq 0 150 1200); do \
		for j in $$(seq 1 10 1000); do \
			$(MAKE) K=$$i G=$$j salidas/g.arreglo.$$i.$$j.data \
				salidas/g.arbol.$$i.$$j.data \
				salidas/g.arbol-compr.$$i.$$j.data; \
		done; \
	done
	cat salidas/g.arbol-compr.*.data > salidas/g.arbol-compr.resultados
	cat salidas/g.arbol.*.data > salidas/g.arbol.resultados
	cat salidas/g.arreglo.*.data > salidas/g.arreglo.resultados

binarios-actualizados:
	$(MAKE) -C ../ all

.PHONY: binarios-actualizados variar-k variar-g all
.PRECIOUS: salidas/k.arreglo.txt salidas/k.arbol.txt salidas/k.arbol-compr.txt \
	salidas/g.arreglo.txt salidas/g.arbol.txt salidas/g.arbol-compr.txt
