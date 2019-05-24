#include "algos.h"

#include <iostream>
#include <algorithm>
#include <stdint.h>

const char* algo = __FILE__;
using namespace std;

using Distancias = vector<uint32_t>;
Costes resultado;

Distancias bellmanFord(ListaDeAristas& g, uint32_t n, uint32_t m, uint32_t v_origen) { 

	Distancias dist;
	dist.resize(n, UINT32_MAX);
    dist[v_origen] = 0; 

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {

            uint32_t origen = get<0>(g[j]); 
            uint32_t destino = get<1>(g[j]); 
            uint32_t peso = get<2>(g[j]); 

            if (dist[origen] != UINT32_MAX && dist[origen] + peso < dist[destino]) 
                dist[destino] = dist[origen] + peso; 

			//En caso de querer un bellman ford bidireccional, usar el código

			/*if (dist[destino] != UINT32_MAX && dist[destino] + peso < dist[origen]) 
            *    dist[origen] = dist[destino] + peso; 
			*/
        } 
    }
	return dist;
} 

Costes ciudades(uint32_t nOriginal, uint32_t n2, uint32_t m2, ListaDeAristas& gAristas, ListaDeVecinos& gVecinos, Matriz& matriz) {

	for(uint32_t i = 0 ; i < nOriginal ; i++){

		int verticeTarget = i * MAX_NAFTA;

		Distancias dcrudas = bellmanFord(gAristas, n2, m2, verticeTarget);

		for(uint32_t k = 0 ; k < nOriginal ; k++) {
			//si mi iterador vertice es igual al original la dist contra si mismo es 0.
			int minLocal = k * MAX_NAFTA;

			//Trucaso, el minLocal siempre es llegar a un vertice con 0 de nafta (posiciones 0,61,122,183 etc).
			if( i != k){
				resultado.push_back({i, k, dcrudas[minLocal]});
			}
		}
	}
	return resultado;
}
