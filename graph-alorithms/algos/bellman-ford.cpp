#include "algos.h"

#include <iostream>
#include <stdint.h>
#include <queue> 
#include <tuple> 

const char* algo = __FILE__;
using namespace std;

Costes resultado;

void BellmanFord(EdgesList g, uint32_t n, uint32_t m, uint32_t v_origen) { 

	vector<uint32_t> dist;
	dist.resize(n, UINT32_MAX);
    dist[v_origen] = 0; 

    for (int i = 0; i <= n - 1; i++) 
    { 
        for (int j = 0; j < m; j++) 
        { 
            uint32_t origen = get<0>(g[j]); 
            uint32_t destino = get<1>(g[j]); 
            uint32_t peso = get<2>(g[j]); 

            if (dist[origen] != UINT32_MAX && dist[origen] + peso < dist[destino]) 
                dist[destino] = dist[origen] + peso; 

			//asumiendo grafo bidireccional
			if (dist[destino] != UINT32_MAX && dist[destino] + peso < dist[origen]) 
                dist[origen] = dist[destino] + peso; 
        } 
    }
	for (uint32_t i = 0; i < n; i++) {
		if(i != v_origen){
			resultado.push_back({v_origen, i, dist[i]});
		}
	}
} 



Costes ciudades(uint32_t n, uint32_t m, uint32_t* precios, EdgesList g) {

	for (uint32_t i = 0; i < n; i++) {
		BellmanFord(g, n, m, i);
	}

	return resultado;
}
