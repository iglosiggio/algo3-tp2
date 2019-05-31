#!/usr/bin/gnuplot -c
# Eje X = Algoritmo
# Eje Y = Tiempo

file_bellman_ford = "../../cheapest-path/series/bellman-ford.expA.series"
file_dijkstra = "../../cheapest-path/series/dijkstra.expA.series"
file_pq_dijkstra = "../../cheapest-path/series/pq-dijkstra.expA.series"

salida = "../expA_algos_todos.pdf"

if (ARG1 ne "") salida = ARG1

set term pdf
set output salida
set xlabel "n"
set ylabel "Tiempo (ms)"
set xrange [10 to 100]
set yrange [0 to 65536]
set title sprintf("Tiempo gastado por cada algoritmo")
set logscale y 2

plot file_bellman_ford using 1:3 smooth unique with line title "Bellman Ford", \
     file_dijkstra using 1:3 smooth unique with line title "Dijkstra", \
     file_pq_dijkstra using 1:3 smooth unique with line title "Dijkstra pq"