#!/bin/sh
# Uso: salida2foto.sh <archivo>
# Notas:
#   * No se puede usar "-" como entrada porque cuenta las filas el archivo
#   * La salida de este script es por salida estándar en formato png
# Bugs:
#   * Siempre marca 255 como valor mayor aunque no sea necesario

ancho=$(awk '{if (NR == 2) { print NF; exit(0); }}' "$1")
alto=$(($(wc -l < "$1") - 1))
scripts=$(dirname "$0")

"$scripts/generar_ppm" "$ancho" "$alto" < "$1" | convert ppm:- png:-
