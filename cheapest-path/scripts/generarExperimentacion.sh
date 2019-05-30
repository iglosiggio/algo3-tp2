#!/bin/sh

generar_casosA=$(dirname "$0")/generarcasosA.sh
generar_casosB=$(dirname "$0")/generarcasosB.sh

seed_a="42"
seed_b="7466"

# 100 experimentos
for ((n=3; n<=12; n=n+1))
do
	# Experimento B
    conexo=$((n*n - n))
    m=$((conexo/2 - n))
    seed=$seed_b
	script=$generar_casosB
	./$script $n $((m)) "$((i + seed))" > "$archivo.in"
done