#!/usr/bin/gnuplot -c
# Eje X = Algoritmo
# Eje Y = Tiempo

file_bellman_ford = "../cheapest-path/series/bellman-ford.expB.series"
file_dijkstra = "../cheapest-path/series/dijkstra.expB.series"
file_pq_dijkstra = "../cheapest-path/series/pq-dijkstra.expB.series"
file_floyd_warshall = "../cheapest-path/series/floyd-warshall.expB.series"

salida = "expB.todos.pdf"

if (ARG1 ne "") salida = ARG1

set term pdf
set output salida
set xlabel "n"
set ylabel "Tiempo (ms)"
set xrange [16 to 24]
set yrange [0 to 65536]
set title sprintf("Tiempo gastado por cada algoritmo")
set logscale y 2

plot file_bellman_ford using 1:3 smooth unique with line title "bellman ford", \
     file_dijkstra using 1:3 smooth unique with line title "dijkstra", \
     file_pq_dijkstra using 1:3 smooth unique with line title "pq-dijkstra", \
     file_floyd_warshall using 1:3 smooth unique with line title "floyd"