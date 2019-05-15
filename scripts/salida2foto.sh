#!/bin/sh
# Uso: salida2foto.sh <archivo>
# Notas:
#   * Se puede usar "-" para usar la entrada estándar cómo entrada
#   * La salida de este script es por salida estándar en formato png

sed "1i\\
P2
2i\\
255" "$1" | convert pgm:- png:-
