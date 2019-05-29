#!/bin/sh

base=$(dirname "$0")

bellman=$base/../bellman-ford.algo
dijkstra=$base/../dijkstra.algo
pqdijkstra=$base/../pq-dijkstra.algo
floyd=$base/../floyd-warshall.algo

for file in "$base"/../casos/*.in; do
    a=$("$bellman"    < "$file" | md5sum)
    b=$("$dijkstra"   < "$file" | md5sum)
    c=$("$pqdijkstra" < "$file" | md5sum)
    d=$("$floyd"      < "$file" | md5sum)

    if [ "$a" = "$b" ] && [ "$a" = "$c" ] && [ "$a" = "$d" ]; then
        echo "$file" "md5sum Check Ok!"
    else
        echo "$file" "md5sum FAIL!"
    fi;
done
