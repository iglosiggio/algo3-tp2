ALGOS=arbol-compr arbol arreglo
EXES=$(ALGOS:=.algo)
VECES=80

ENTRADA:=entrada.txt

all: variar-k variar-g distintas-fotos

salidas/%.arbol-compr.$(K).$(G).data: $(ENTRADA)
	for i in $$(seq 1 $(VECES)); do \
		../arbol-compr.algo $(K) 0.8 $(G) < $(ENTRADA) >/dev/null; \
	done 2>> $@

salidas/%.arbol.$(K).$(G).data: $(ENTRADA)
	for i in $$(seq 1 $(VECES)); do \
		../arbol.algo $(K) 0.8 $(G) < $(ENTRADA) >/dev/null; \
	done 2>> $@

salidas/%.arreglo.$(K).$(G).data: $(ENTRADA)
	for i in $$(seq 1 $(VECES)); do \
		../arreglo.algo $(K) 0.8 $(G) < $(ENTRADA) >/dev/null; \
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

distintas-fotos: binarios-actualizados
	rm -f salidas/foto_a.arreglo.resultados salidas/foto_a.arbol.resultados \
		salidas/foto_a.arbol-compr.resultados
	rm -f salidas/foto_b.arreglo.resultados salidas/foto_b.arbol.resultados \
		salidas/foto_b.arbol-compr.resultados
	rm -f salidas/foto_c.arreglo.resultados salidas/foto_c.arbol.resultados \
		salidas/foto_c.arbol-compr.resultados
	for foto in $$(seq 100 100 700); do \
		$(MAKE) K=300 G=-1 ENTRADA=a.$$foto.txt \
			salidas/foto_a.$$foto.arreglo.300.-1.data \
			salidas/foto_a.$$foto.arbol.300.-1.data \
			salidas/foto_a.$$foto.arbol-compr.300.-1.data; \
		$(MAKE) K=300 G=-1 ENTRADA=b.$$foto.txt \
			salidas/foto_b.$$foto.arreglo.300.-1.data \
			salidas/foto_b.$$foto.arbol.300.-1.data \
			salidas/foto_b.$$foto.arbol-compr.300.-1.data; \
		$(MAKE) K=300 G=-1 ENTRADA=c.$$foto.txt \
			salidas/foto_c.$$foto.arreglo.300.-1.data \
			salidas/foto_c.$$foto.arbol.300.-1.data \
			salidas/foto_c.$$foto.arbol-compr.300.-1.data; \
	done
	cat salidas/foto_a.*.arbol-compr.*.data > salidas/foto_a.arbol-compr.resultados
	cat salidas/foto_a.*.arbol.*.data > salidas/foto_a.arbol.resultados
	cat salidas/foto_a.*.arreglo.*.data > salidas/foto_a.arreglo.resultados
	cat salidas/foto_b.*.arbol-compr.*.data > salidas/foto_b.arbol-compr.resultados
	cat salidas/foto_b.*.arbol.*.data > salidas/foto_b.arbol.resultados
	cat salidas/foto_b.*.arreglo.*.data > salidas/foto_b.arreglo.resultados
	cat salidas/foto_c.*.arbol-compr.*.data > salidas/foto_c.arbol-compr.resultados
	cat salidas/foto_c.*.arbol.*.data > salidas/foto_c.arbol.resultados
	cat salidas/foto_c.*.arreglo.*.data > salidas/foto_c.arreglo.resultados

binarios-actualizados:
	$(MAKE) -C ../ all

variar-k.pdf: variar-k.plot
	./variar-k.plot

distintas-fotos-%.pdf: distintas-fotos.done
	@

distintas-fotos.done: distintas-fotos.plot binarios-actualizados
	./distintas-fotos.plot
	touch distintas-fotos.done

variar-g-%.pdf: variar-g.done
	@

variar-g.done: variar-g.plot binarios-actualizados
	./variar-g.plot
	touch variar-g.done

clean:
	rm -f *.pdf *.done

.PHONY: binarios-actualizados variar-k variar-g all clean
.PRECIOUS: salidas/k.arreglo.txt salidas/k.arbol.txt salidas/k.arbol-compr.txt \
	salidas/g.arreglo.txt salidas/g.arbol.txt salidas/g.arbol-compr.txt
