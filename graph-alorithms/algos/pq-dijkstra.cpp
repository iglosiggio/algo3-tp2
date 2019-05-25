#include <queue>
#include <iostream>

#include "algos.h"

using namespace std;

const char* algo = __FILE__;

using distPair = pair<uint32_t,uint32_t>;

Costes resultado;

Distancias pqDijkstra(ListaDeVecinos gVecinos, uint32_t n, uint32_t m, uint32_t v_origen) {
	Distancias dist(n, INFINITO);
	priority_queue<distPair, vector<distPair>, greater<distPair>> pq;

	dist[v_origen] = 0;
	pq.push({0, v_origen});

	while(!pq.empty()) {
		uint32_t v = pq.top().second;
		pq.pop();

		for (int i = 0; i < gVecinos[v].size(); i++) {
			uint32_t destino = gVecinos[v][i].first;
			uint32_t peso = gVecinos[v][i].second;

			if(dist[destino] > dist[v] + peso){
				dist[destino] = dist[v] + peso;
				pq.push({peso, destino});
			}
		}
	}
	return dist;
}

Costes ciudades(uint32_t nOriginal, uint32_t n, uint32_t m, ListaDeAristas& gAristas, ListaDeVecinos& gVecinos, Matriz& matriz) {
	for (uint32_t i = 0 ; i < nOriginal ; i++) {
		int verticeTarget = i * MAX_NAFTA;
		Distancias dcrudas = pqDijkstra(gVecinos, n, m, verticeTarget);

		for (uint32_t k = 0 ; k < nOriginal ; k++) {

			int minLocal = k * MAX_NAFTA;

			if (i != k)
				resultado.push_back({i, k, dcrudas[minLocal]});
		}
	}
	return resultado;
}
