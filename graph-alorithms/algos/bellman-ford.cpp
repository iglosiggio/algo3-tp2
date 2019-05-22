#include "algos.h"

#include <iostream>
#include <stdint.h>
#include <queue> 
#include <tuple> 
#include <cmath> 

const char* algo = __FILE__;
using namespace std;

using Distancias = vector<uint32_t>;
Costes resultado;

Distancias BellmanFord(EdgesList& g, uint32_t n, uint32_t m, uint32_t v_origen) { 

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

	//vertices
	uint32_t n2 = n * 61;
	//aristas
	uint32_t m2 = 0;

	//inicializo mi nuevo grafo de aristas
	EdgesList g2;

	//por cada arista dentro de mi grafo original creo 60^2 aristas
	for (uint32_t i = 0; i < m; i++) {

			//parseo el origen, destino y peso
		    uint32_t origen = get<0>(g[i]); 
            uint32_t destino = get<1>(g[i]); 
            uint32_t distancia = get<2>(g[i]); 

			uint32_t listrosACargarEnOrigen = 0;

			for(uint32_t j = (origen * 61); j < 61 * (origen + 1); j++){

				uint32_t listrosACargarEnDestino = 0;

				for (uint32_t z = (destino * 61); z < 61 * (destino + 1); z++){
					
					if(distancia <= listrosACargarEnOrigen){
						g2.push_back(std::make_tuple(j, z, precios[origen] * listrosACargarEnOrigen));
						m2++;
					}

					//ya que es unidireccional agregamos las aristas en sentido contrario con su precio.
					if(distancia <= listrosACargarEnDestino){
						g2.push_back(std::make_tuple(z, j, precios[destino] * listrosACargarEnDestino));
						m2++;
					}
					listrosACargarEnDestino++;
				}
				listrosACargarEnOrigen++;
			}
	}


	uint32_t iteracion = 0;
	for (uint32_t i = 1; i <= n; i++) {

		Distancias dverdaderas;
		dverdaderas.resize(n, UINT32_MAX);

		for(uint32_t j = (i-1) * 61; j < 61 * i; j++){

			Distancias dcrudas = BellmanFord(g2, n2, m2, iteracion);

			//para saber en que lote de 61 estoy
			uint32_t verticeReal = floor(double (j / 61));

			cout << "termine bellman ford: " << iteracion << ' ' << verticeReal << endl;

			//calculo el min dist a vertice de cada bloque 0..61


			for (uint32_t k = 1; k <= n; k++) {

				uint32_t min = UINT32_MAX;
				for(uint32_t w = (i-1) * 61; w < 61 * i; w++){
					if(min > dcrudas[w]){
						min = w;
					}
				}

				//actualizo el minimo total
				if(dverdaderas[k] > min){
					dverdaderas[k] = min;
				}
				//la distancia con si mismo es 0
				if(k == verticeReal){
					dverdaderas[k] = 0;
				}
			}


			iteracion++;
		}
		// legado a este punto acabo de calcular 61 vertices en teoría (61 formas de salir a revisar los vecinos)
		// distancias verdaderas deberían ser los minimos efectivos.
		for (uint32_t t = 0; t < n; t++) {
			resultado.push_back({i -1, t, dverdaderas[t]});
		}
	}

	return resultado;
}
