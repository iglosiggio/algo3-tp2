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

			//En caso de querer un bellman ford bidireccional

			/*if (dist[destino] != UINT32_MAX && dist[destino] + peso < dist[origen]) 
            *    dist[origen] = dist[destino] + peso; 
			*/
        } 
    }
	return dist;
} 



Costes ciudades(uint32_t n, uint32_t m, uint32_t* precios, EdgesList g) {

	//max posible de nafta en el auto (util para debugging)
	uint32_t maxNafta = 61;
	//vertices
	uint32_t n2 = n * maxNafta;
	//aristas
	uint32_t m2 = 0;

	//inicializo mi nuevo grafo de aristas
	EdgesList g2;

	//por cada arista dentro de mi grafo original creo 60^2 aristas
	for (uint32_t i = 0; i < m; i++) {

		//parseo el origen, destino y peso
		int32_t origen = get<0>(g[i]); 
		int32_t destino = get<1>(g[i]); 
		int32_t distancia = get<2>(g[i]);
			
		//PARTE 1, transformacion del grafo
		int32_t litrosCargadosEnA = 0;

		for(int32_t verticeA = origen * maxNafta; verticeA < maxNafta * (origen + 1); verticeA++) {

			int32_t litrosCargadosEnB = 0;

			for(int32_t verticeB = destino * maxNafta; verticeB < maxNafta * (destino + 1); verticeB++) {
				
				if(distancia + litrosCargadosEnB < maxNafta) {
					
					int32_t costo = 0;
					if( distancia + litrosCargadosEnB - litrosCargadosEnA >= 0) {
						costo = precios[origen] * (distancia + litrosCargadosEnB - litrosCargadosEnA);
					}
					g2.push_back(std::make_tuple(verticeA, verticeB, costo));
					m2++;
				}

				if(distancia + litrosCargadosEnA < maxNafta) {
					
					uint32_t costo = 0;
					if(distancia + litrosCargadosEnA - litrosCargadosEnB >= 0) {
						costo = precios[destino] * (distancia + litrosCargadosEnA - litrosCargadosEnB);
					}
					g2.push_back(std::make_tuple(verticeB, verticeA, costo));
					m2++;
				}
				litrosCargadosEnB++;
			}
			litrosCargadosEnA++;

		}
	}

	//un sort no hace mal a nadie, y me sirvio un montonaso para debuggear esto. 
	std::sort (g2.begin(), g2.end());

	//PARTE 2, bellman ford sobre el grafo grande, y recuperar el resultado que importa.
	for(uint32_t i = 0 ; i < n ; i++){

		int verticeTarget = i * maxNafta;

		//tiene distancias a todos los bloques 0..61 por eso crudas, necesito reducirlas
		Distancias dcrudas = bellmanFord(g2, n2, m2, verticeTarget);

		cout << "bellamanFord ejecutado con nodo: " << verticeTarget << endl;

		Distancias dverdaderas;
		dverdaderas.resize(n, UINT32_MAX);

		for(int k = 0 ; k < n ; k++) {
			//si mi iterador vertice es igual al original la dist contra si mismo es 0.
			int minLocal = k * maxNafta;

			//Trucaso, el minLocal siempre es llegar a un vertice con 0 de nafta (posiciones 0,61,122,183 etc).
			dverdaderas[k] = dcrudas[minLocal];

		}

		// legado a este punto acabo de calcular todos los minimos, los agrego a los resultados.
		for (uint32_t t = 0; t < n; t++) {
			if (i != t) {
				resultado.push_back({i, t, dverdaderas[t]});
			}
		}
	}

	

	return resultado;
}
