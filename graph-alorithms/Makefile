ALGOS=dijkstra pq-dijkstra floyd-warshall bellman-ford
BINARIOS=$(ALGOS:=.algo)

all: $(BINARIOS)

clean:
	rm -f *.o $(BINARIOS)

%.algo: main.o algos/%.cpp algos/algos.h
	$(CXX) $(CXXFLAGS) $^ -o $@
