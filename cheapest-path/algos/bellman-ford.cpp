#include <iostream>
#include <stdint.h>

#include "algos.h"



const char* algo = __FILE__;
using namespace std;

Costes resultado;

Distancias bellmanFord(ListaDeVecinos& gVecinos, uint32_t n, uint32_t m, uint32_t v_origen) {
	Distancias dist(n, INFINITO);
	queue<uint32_t> q;

	dist[v_origen] = 0;
	q.push(v_origen);

	while(!q.empty()) {
		uint32_t v = q.front();
		q.pop();

		for (int i = 0; i < gVecinos[v].size(); i++) {
			uint32_t destino = gVecinos[v][i].first;
			uint32_t peso = gVecinos[v][i].second;

			if(dist[destino] > dist[v] + peso){
				dist[destino] = dist[v] + peso;
				q.push(destino);
			}
		}
	}
	return dist;
}

Costes ciudades(uint32_t nOriginal, uint32_t n2, uint32_t m2, ListaDeVecinos& gVecinos, Matriz& matriz) {

	for(uint32_t i = 0 ; i < nOriginal ; i++){
		int destino = i * MAX_NAFTA;
		Distancias dcrudas = bellmanFord(gVecinos, n2, m2, destino);

		for(uint32_t k = 0 ; k < nOriginal ; k++) {
			/* Si mi iterador vertice es igual al original la dist
			 * contra si mismo es 0. */
			int minLocal = k * MAX_NAFTA;

			/* Trucaso, el minLocal siempre es llegar a un vertice
			 * con 0 de nafta (posiciones 0,61,122,183 etc). */
			if (i != k)
				resultado.push_back({i, k, dcrudas[minLocal]});
		}
	}
	return resultado;
}
