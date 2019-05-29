#!/bin/sh

generar_casosA=$(dirname "$0")/generarcasosA.sh
generar_casosB=$(dirname "$0")/generarcasosB.sh

seed_a="42"
seed_b="7466"

# 500 experimentos
for ((n=10; n<=105; n=n+5))
do
	# Experimento A
    m=$n*2
    seed=$seed_a
	script=$generar_casosA
	./$script $n $((m)) "$((i + seed))" > "$archivo.in"
done

# 250 experimentos
for ((n=10; n<=55; n=n+5))
do
	# Experimento B
    conexo=$((n*n - n))
    m=$((conexo/2 - n*2))
    seed=$seed_b
	script=$generar_casosB
	./$script $n $((m)) "$((i + seed))" > "$archivo.in"
done