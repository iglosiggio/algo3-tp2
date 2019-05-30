#!/bin/sh

algo=$1
exp=$2
ubicacionFile="../series/$algo.$exp.series"

s_n=0
s_m=0
s_tiempo=0.0
cant=0

for filename in $(ls ../data/expA.*.$algo.resultados ) ; do

    echo $filename

	while IFS=' ' read -r name n m tiempo 
	do
        s_n=$(echo "scale=20; $s_n + $n" | bc)
        s_m=$(echo "scale=20; $s_m + $m" | bc)
        s_tiempo=$(echo "scale=20; $s_tiempo + $tiempo" | bc)
        cant=$(echo $cant + 1 | bc)

	done < "$filename"

	if [ $cant -gt 0 ]; then 
	    s_n=$(echo "$s_n / $cant" | bc)
	    s_m=$(echo "$s_m / $cant" | bc)
	    s_tiempo=$(echo "scale=20; $s_tiempo / $cant" | bc)
	    echo $s_n $s_m $s_tiempo >> $ubicacionFile
	fi

    s_n=0
	s_m=0
	s_tiempo=0.0
	cant=0
done