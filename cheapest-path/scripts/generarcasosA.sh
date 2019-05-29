#!/bin/sh

generar_a=$(dirname "$0")/experimentos
casos=$(dirname "$0")/../casos

n="$1"
m="$2"
seed_a="$3"



for i in $(seq 1 25); do
	# Experimento A
	script=$generar_a
	seed=$seed_a
	archivo="$casos/expA.n$n.m"$((m+n))".i$i"
	./$script $n $((m+1)) "$((i + seed))" > "$archivo.in"
done