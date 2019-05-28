#!/bin/sh

generar_a=$(dirname "$0")/experimentos
casos=$(dirname "$0")/../casos

n="$1"
m="$2"
seed_a="$3"

for i in $(seq 1 5); do
	# Experimento A
	script=$generar_a
	seed=$seed_a
	archivo="$casos/exp.n$n.m$m.i$i"
	./$script $n $m "$((i + seed))" > "$archivo.in"
done