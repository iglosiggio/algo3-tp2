#include <iostream>

#include "algos.h"

using namespace std;

const char* algo = __FILE__;

Costes resultado;


uint32_t sigVertice(const Distancias& dist, vector<bool>& visitados, uint32_t n) {
	uint32_t v = 0;
	uint32_t min = UINT32_MAX;

	
	for(int i = 0; i < n; i++) {
		if(!visitados[i] && dist[i] < min) {
			v = i;
			min = dist[i];
		}
	}

	visitados[v] = true;

	return v;
}

Distancias dijkstra(ListaDeVecinos gVecinos, uint32_t n, uint32_t m, uint32_t v_origen) {
	Distancias dist(n, INFINITO);
	dist[v_origen] = 0;

	vector<bool> visitados(n, false);

	for (int k = 0; k < n; k++) {
		uint32_t v = sigVertice(dist, visitados, n);

		for (int i = 0; i < gVecinos[v].size(); i++) {
			uint32_t destino = gVecinos[v][i].first;
			uint32_t peso = gVecinos[v][i].second;

			if(dist[destino] > dist[v] + peso)
				dist[destino] = dist[v] + peso;
		}
	}
	return dist;
}

Costes ciudades(uint32_t nOriginal, uint32_t n, uint32_t m, ListaDeVecinos& gVecinos, Matriz& matriz) {
	/* Dijkstra da todas las distancias al origan, por lo que lo corremos n
	 * veces. */
	for (uint32_t i = 0 ; i < nOriginal ; i++) {
		int verticeTarget = i * MAX_NAFTA;
		Distancias dcrudas = dijkstra(gVecinos, n, m, verticeTarget);

		for (uint32_t k = 0 ; k < nOriginal ; k++) {
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


