# Se pueden pasar para configurar
veces   ?= 25
timeout ?= 20
RUN=../scripts/run_test.sh

.PRECIOUS: %.resultados %.series %.stats

casos_a=$(wildcard ../casos/expA.*.in)
casos_b=$(wildcard ../casos/expB.*.in)

nombres_a=$(casos_a:../casos/%.in=%)
nombres_b=$(casos_b:../casos/%.in=%)

%.bellman-ford.resultados: ../bellman-ford.algo ../casos/%.in
	$(RUN) ../casos/$*.in ../bellman-ford.algo $(veces) $(timeout) 2> $*.bellman-ford.resultados

%.dijkstra.resultados: ../dijkstra.algo ../casos/%.in
	$(RUN) ../casos/$*.in ../dijkstra.algo $(veces) $(timeout) 2> $*.dijkstra.resultados 

%.pq-dijkstra.resultados: ../pq-dijkstra.algo ../casos/%.in
	$(RUN) ../casos/$*.in ../pq-dijkstra.algo $(veces) $(timeout) 2> $*.pq-dijkstra.resultados 

%.floyd-warshall.resultados: ../floyd-warshall.algo ../casos/%.in
	$(RUN) ../casos/$*.in ../floyd-warshall.algo $(veces) $(timeout) 2> $*.floyd-warshall.resultados 