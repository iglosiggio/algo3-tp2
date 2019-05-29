#!/bin/sh

bellman=$(dirname "$0")/../bellman-ford.algo
dijkstra=$(dirname "$0")/../dijkstra.algo
pqdijkstra=$(dirname "$0")/../pq-dijkstra.algo
floyd=$(dirname "$0")/../floyd-warshall.algo

for file in ../casos/*.in; do 
    a=$(./$bellman < $file | md5sum)
    b=$(./$dijkstra < $file | md5sum)
    c=$(./$pqdijkstra < $file | md5sum)
    d=$(./$floyd < $file | md5sum)

    if [ "$a" == "$b" ] && [ "$a" == "$c" ] && [ "$a" == "$d" ]; then 
        echo $file "md5sum Check Ok!"
    else
        echo $file "md5sum FAIL!"
    fi;
done