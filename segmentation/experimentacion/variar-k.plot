#!/usr/bin/gnuplot -c

arreglo = "salidas/k.arreglo.resultados"
arbol = "salidas/k.arbol.resultados"
arbol_compr = "salidas/k.arbol-compr.resultados"

set term pdf
set output "variar-k.pdf"
set xlabel "k"
set ylabel "Tiempo Promedio (segmentación) (ms)"
set xrange [0 to 1200]
set title sprintf("Tiempo gastado según representación")

plot arreglo using 1:4 smooth unique with line title "Arreglo de componentes", \
     arbol using 1:4 smooth unique with line title "Árbol", \
     arbol_compr using 1:4 smooth unique with line title "Árbol con path-compression", \
