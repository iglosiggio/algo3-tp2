#!/usr/bin/gnuplot -c
# Eje X = Algoritmo
# Eje Y = Tiempo

file = "../../cheapest-path/series/pq-dijkstra.expB.series"

salida = "../pq_dijkstra_correlacion.pdf"

f(x) = k * x**3 

fit f(x) file using 1:3 via k
stats file using 3:(f($1)) name "DATA"


if (ARG1 ne "") salida = ARG1

set term pdf
set output salida
set xlabel "cota"
set ylabel "Tiempo (ms)"
set title sprintf("Experimentos vs best-fit\nCorrelacion: %f", DATA_correlation)

plot file using 1:3 with point pointtype 15 pointsize 0.3 title "Dijkstra pq", \
	 f(x) with line title "Best fit para f(x) = kn^3"