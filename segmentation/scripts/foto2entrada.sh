#!/bin/sh
# Uso: foto2entrada.sh <archivo>
# Notas:
#   * Se puede usar "<formato>:-" para usar la entrada estándar como entrada
#   * La salida de este script es por salida estándar en el formato pedido por
#     la cátedra

formatear() {
	read -r ancho alto
	echo "$ancho" "$alto"
	xargs -n"$ancho"
}

convert "$1" -colorspace Gray -compress none -depth 8 pgm:- | sed '1d;3d' \
	| formatear
