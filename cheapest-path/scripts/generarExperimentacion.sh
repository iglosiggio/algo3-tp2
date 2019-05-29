#!/bin/sh

generar_casosA=$(dirname "$0")/generarcasosA.sh
generar_casosB=$(dirname "$0")/generarcasosB.sh

seed_a="42"
seed_b="7466"

# 500 experimentos
for ((n=100; n<=300; n=n+10))
do
	# Experimento A
    m=$n*4
    seed=$seed_a
	script=$generar_casosA
	./$script $n $((m)) "$((i + seed))" > "$archivo.in"
done

# 250 experimentos
for ((n=100; n<=200; n=n+10))
do
	# Experimento B
    conexo=$((n*n - n))
    m=$((conexo/2 - n*6))
    seed=$seed_b
	script=$generar_casosB
	./$script $n $((m)) "$((i + seed))" > "$archivo.in"
done