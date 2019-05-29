#!/bin/sh

generar_b=$(dirname "$0")/experimentos
casos=$(dirname "$0")/../casos

n="$1"
m="$2"
seed_a="$3"



for i in $(seq 1 25); do
	# Experimento A
	script=$generar_b
	seed=$seed_a
	archivo="$casos/expB.n$n.m"$((m+n))".i$i"
	./$script $n $((m+1)) "$((i + seed))" > "$archivo.in"
done