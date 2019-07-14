#!/usr/bin/gnuplot -c

a_arreglo = "salidas/foto_a.arreglo.resultados"
b_arreglo = "salidas/foto_b.arreglo.resultados"
c_arreglo = "salidas/foto_c.arreglo.resultados"
arbol = "salidas/g.arbol.resultados"
a_arbol = "salidas/foto_a.arbol.resultados"
b_arbol = "salidas/foto_b.arbol.resultados"
c_arbol = "salidas/foto_c.arbol.resultados"
a_arbol_compr = "salidas/foto_a.arbol-compr.resultados"
b_arbol_compr = "salidas/foto_b.arbol-compr.resultados"
c_arbol_compr = "salidas/foto_c.arbol-compr.resultados"

set term pdf
set xlabel "Tamaño del lado (raiz cuadrada de la cantidad de píxeles)"
set ylabel "Tiempo (ms)"
#set logscale y 2
set key top left

set title "Tiempo gastado en segmentación según imagen y resolución (Arreglo)"
set output "distintas-fotos-arreglo.pdf"
plot a_arreglo using 6:4 smooth unique with line title "mondrian.jpg (promedio)", \
     a_arreglo using 6:4 with point title "mondrian.jpg (puntos)", \
     b_arreglo using 6:4 smooth unique with line title "edificios.png (promedio)", \
     b_arreglo using 6:4 with point title "edificios.png (puntos)", \
     c_arreglo using 6:4 smooth unique with line title "bosque.jpg (promedio)", \
     c_arreglo using 6:4 with point title "bosque.jpg (puntos)"

set title "Tiempo gastado en segmentación según imagen y resolución (Árbol)"
set output "distintas-fotos-arbol.pdf"
plot a_arbol using 6:4 smooth unique with line title "mondrian.jpg (promedio)", \
     a_arbol using 6:4 with point title "mondrian.jpg (puntos)", \
     b_arbol using 6:4 smooth unique with line title "edificios.png (promedio)", \
     b_arbol using 6:4 with point title "edificios.png (puntos)", \
     c_arbol using 6:4 smooth unique with line title "bosque.jpg (promedio)", \
     c_arbol using 6:4 with point title "bosque.jpg (puntos)"

set title "Tiempo gastado en segmentación según imagen y resolución (Árbol c/compresión)"
set output "distintas-fotos-arbol-compr.pdf"
plot a_arbol_compr using 6:4 smooth unique with line title "mondrian.jpg (promedio)", \
     a_arbol_compr using 6:4 with point title "mondrian.jpg (puntos)", \
     b_arbol_compr using 6:4 smooth unique with line title "edificios.png (promedio)", \
     b_arbol_compr using 6:4 with point title "edificios.png (puntos)", \
     c_arbol_compr using 6:4 smooth unique with line title "bosque.jpg (promedio)", \
     c_arbol_compr using 6:4 with point title "bosque.jpg (puntos)", \
