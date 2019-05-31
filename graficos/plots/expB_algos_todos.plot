#!/usr/bin/gnuplot -c
# Eje X = Algoritmo
# Eje Y = Tiempo

file_bellman_ford = "../../cheapest-path/series/bellman-ford.expB.series"
file_dijkstra = "../../cheapest-path/series/dijkstra.expB.series"
file_pq_dijkstra = "../../cheapest-path/series/pq-dijkstra.expB.series"
file_floyd_warshall = "../../cheapest-path/series/floyd-warshall.expB.series"

salida = "../expB_algos_todos.pdf"

if (ARG1 ne "") salida = ARG1

set term pdf
set output salida
set xlabel "n"
set ylabel "Tiempo (ms)"
set xrange [3 to 12]
set yrange [0 to 4096]
set title sprintf("Tiempo gastado por cada algoritmo")
set logscale y 2

plot file_bellman_ford using 1:3 smooth unique with line title "Bellman Ford", \
     file_dijkstra using 1:3 smooth unique with line title "Dijkstra", \
     file_pq_dijkstra using 1:3 smooth unique with line title "Dijkstra pq", \
     file_floyd_warshall using 1:3 smooth unique with line title "Floyd Warshall"