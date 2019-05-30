#!/usr/bin/gnuplot -c

arreglo = "salidas/g.arreglo.resultados"
arbol = "salidas/g.arbol.resultados"
arbol_compr = "salidas/g.arbol-compr.resultados"

set term pdf
set xlabel "g"
set ylabel "Tiempo Promedio (ms)"
set logscale y 2

filtrarK(k) = column(1) == k ? column(5) : 1/0
inv(col) = 1 / column(col)

set title "Tiempo gastado en simplificación (Arreglo de componentes)"
set output "variar-g-arreglo.pdf"
plot arreglo using (inv(3)):(filtrarK(0)) smooth unique with line title "K=0", \
     arreglo using (inv(3)):(filtrarK(150)) smooth unique with line title "K=150", \
     arreglo using (inv(3)):(filtrarK(300)) smooth unique with line title "K=300", \
     arreglo using (inv(3)):(filtrarK(450)) smooth unique with line title "K=450", \
     arreglo using (inv(3)):(filtrarK(600)) smooth unique with line title "K=600", \
     arreglo using (inv(3)):(filtrarK(750)) smooth unique with line title "K=750", \
     arreglo using (inv(3)):(filtrarK(900)) smooth unique with line title "K=900", \
     arreglo using (inv(3)):(filtrarK(1050)) smooth unique with line title "K=1050", \
     arreglo using (inv(3)):(filtrarK(1200)) smooth unique with line title "K=1200"

set title "Tiempo gastado en simplificación (Árbol)"
set output "variar-g-arbol.pdf"
plot arbol using (inv(3)):(filtrarK(0)) smooth unique with line title "K=0", \
     arbol using (inv(3)):(filtrarK(150)) smooth unique with line title "K=150", \
     arbol using (inv(3)):(filtrarK(300)) smooth unique with line title "K=300", \
     arbol using (inv(3)):(filtrarK(450)) smooth unique with line title "K=450", \
     arbol using (inv(3)):(filtrarK(600)) smooth unique with line title "K=600", \
     arbol using (inv(3)):(filtrarK(750)) smooth unique with line title "K=750", \
     arbol using (inv(3)):(filtrarK(900)) smooth unique with line title "K=900", \
     arbol using (inv(3)):(filtrarK(1050)) smooth unique with line title "K=1050", \
     arbol using (inv(3)):(filtrarK(1200)) smooth unique with line title "K=1200"

set title "Tiempo gastado en simplificación (Árbol con compresión)"
set output "variar-g-arbol-compr.pdf"
plot arbol_compr using (inv(3)):(filtrarK(0)) smooth unique with line title "K=0", \
     arbol_compr using (inv(3)):(filtrarK(150)) smooth unique with line title "K=150", \
     arbol_compr using (inv(3)):(filtrarK(300)) smooth unique with line title "K=300", \
     arbol_compr using (inv(3)):(filtrarK(450)) smooth unique with line title "K=450", \
     arbol_compr using (inv(3)):(filtrarK(600)) smooth unique with line title "K=600", \
     arbol_compr using (inv(3)):(filtrarK(750)) smooth unique with line title "K=750", \
     arbol_compr using (inv(3)):(filtrarK(900)) smooth unique with line title "K=900", \
     arbol_compr using (inv(3)):(filtrarK(1050)) smooth unique with line title "K=1050", \
     arbol_compr using (inv(3)):(filtrarK(1200)) smooth unique with line title "K=1200"
