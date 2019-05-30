#!/bin/sh

algo=$1
ubicacionFile="../series/$algo.series"

s_n=0
s_m=0
s_tiempo=0.0
cant=0

for filename in $(ls ../data/expA.*.$algo.resultados ) ; do

    echo $filename

	while IFS=' ' read -r name n m tiempo 
	do

        echo $name $n $m $tiempo 
        s_n=$(echo "scale=20; $s_n + $n" | bc)
        s_m=$(echo "scale=20; $s_m + $m" | bc)
        s_tiempo=$(echo "scale=20; $s_n + $tiempo" | bc)
        cant=$(echo $cant + 1 | bc)

	done < "$filename"

done