ALGOS=dijkstra pq-dijkstra floyd-warshall bellman-ford
BINARIOS=$(ALGOS:=.algo)

all: $(BINARIOS)

clean:
	rm -f *.o $(BINARIOS)

%.algo: main.o algos/%.cpp algos/algos.h
	$(CXX) $(CXXFLAGS) $^ -o $@

# Alias para poder correr `make pdf.test` y cosas así
# La salida tiene la siguiente forma:
# 	<test> <salida esperada> <algo> <salida> <tiempo>
%.test: casos/%.test

#TODO: Ver como comprar salida con ciudad.out
casos/%.test: $(BINARIOS) casos/%.in casos/%.out
	@for exe in $(BINARIOS); do \
		echo $$(./$$exe < casos/$*.in); \
	done;

