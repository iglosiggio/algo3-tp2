#include "algos.h"

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <queue> 
#include <tuple> 
#include <cmath> 

const char* algo = __FILE__;
using namespace std;

using Distancias = vector<uint32_t>;
Costes resultado;

Distancias bellmanFord(EdgesList& g, uint32_t n, uint32_t m, uint32_t v_origen) { 

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



Costes ciudades(uint32_t n, uint32_t m, uint32_t* precios, EdgesList g) {

	uint32_t maxNafta = 61;

	//inicializo mi nuevo grafo de aristas grande
	EdgesList g2;
	uint32_t n2 = n * maxNafta;
	uint32_t m2 = 0;

	//PARTE 1, Transformación del grafo g, al grafo g2
	for (uint32_t i = 0; i < m; i++) {

		int32_t origen = get<0>(g[i]); 
		int32_t destino = get<1>(g[i]); 
		int32_t distancia = get<2>(g[i]);
			

		int32_t litrosCargadosEnB = 0;
		/* itero 61 veces, desde 0 a 60, desde 61 a 121 y así dependiendo si el origen es nodo 0,1 etc.
		*  TODO (ver si hay formas más prolijas de decir esto) */
		for(int32_t verticeA = origen * maxNafta; verticeA < maxNafta * (origen + 1); verticeA++) {

			int32_t litrosCargadosEnA = 0;

			/* Igual al primero itera 61 veces solo que con el nodo del destino. Recordemos #(aristas) <= 61^2 */
			for(int32_t verticeB = destino * maxNafta; verticeB < maxNafta * (destino + 1); verticeB++) {
				

				if(distancia + litrosCargadosEnA < maxNafta) {
					
					int32_t costo = 0;
					if( distancia + litrosCargadosEnA - litrosCargadosEnB >= 0) {
						costo = precios[origen] * (distancia + litrosCargadosEnA - litrosCargadosEnB);
					}
					g2.push_back(std::make_tuple(verticeA, verticeB, costo));
					m2++;
				}

				//las aristas tienen dirección, así que si puedo agregar uno, agrego el espejo.
				if(distancia + litrosCargadosEnB < maxNafta) {
					
					uint32_t costo = 0;
					if(distancia + litrosCargadosEnB - litrosCargadosEnA >= 0) {
						costo = precios[destino] * (distancia + litrosCargadosEnB - litrosCargadosEnA);
					}
					g2.push_back(std::make_tuple(verticeB, verticeA, costo));
					m2++;
				}
				litrosCargadosEnA++;
			}
			litrosCargadosEnB++;

		}
	}

	//no es necesario hacer un sort, pero no hace mal a nadie y me ayudo en el debugging.
	std::sort (g2.begin(), g2.end());


	//PARTE 2, tengo que hacer bellman ford sobre el grafo grande, y recuperar el resultado que importa.
	for(uint32_t i = 0 ; i < n ; i++){

		int verticeTarget = i * maxNafta;

		Distancias dcrudas = bellmanFord(g2, n2, m2, verticeTarget);

		for(uint32_t k = 0 ; k < n ; k++) {
			//si mi iterador vertice es igual al original la dist contra si mismo es 0.
			int minLocal = k * maxNafta;

			//Trucaso, el minLocal siempre es llegar a un vertice con 0 de nafta (posiciones 0,61,122,183 etc).
			if( i != k){
				resultado.push_back({i, k, dcrudas[minLocal]});
			}
		}
	}
	return resultado;
}
