#!/bin/sh

for filename in $(ls ../casos/expA.n*.in ) ; do
    base=$(basename $filename)
    name=${base::-3}

    make $name.bellman-ford.resultados
    make $name.dijkstra.resultados
    make $name.pq-dijkstra.resultados
done