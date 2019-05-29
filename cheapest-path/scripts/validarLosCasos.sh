#!/bin/sh

bellman=$(dirname "$0")/../bellman-ford.algo
dijkstra=$(dirname "$0")/../dijkstra.algo
pqdijkstra=$(dirname "$0")/../pq-dijkstra.algo
floyd=$(dirname "$0")/../floyd-warshall.algo



for file in ../casos/*.in; do 

    a=$(md5sum <<< ./$bellman < $file)
    b=$(md5sum <<< ./$dijkstra < $file)
    c=$(md5sum <<< ./$pqdijkstra < $file)
    d=$(md5sum <<< ./$floyd < $file)

    if [ "$a" == "$b" ] && [ "$a" == "$c" ] && [ "$a" == "$d" ]; then 
        echo $file "md5sum Check Ok!"
    else
        echo $file "md5sum FAIL!"
    fi;

done