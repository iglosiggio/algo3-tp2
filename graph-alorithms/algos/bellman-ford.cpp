#include "algos.h"

#include <iostream>
#include <stdint.h>
#include <queue> 
#include <tuple> 

const char* algo = __FILE__;
using namespace std;

using Distancias = vector<uint32_t>;
Costes resultado;

Distancias BellmanFord(EdgesList& g, uint32_t n, uint32_t m, uint32_t v_origen) { 

	Distancias dist;
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
	return dist;
} 



Costes ciudades(uint32_t n, uint32_t m, uint32_t* precios, EdgesList g) {

	/* La idea es de nacho, no me hago responsable de si alguien pierde los ojos.
	*
	* dicen que el espiritu santo es como el viento, puede ser tan tierno 
	* como acariciar una hoja o tan violento como para doblar un arbol
	*/

	//multiplico los vertice por 61
	uint32_t n2 = n * 61;

	//las aristas las calculo después ya que puedo podar aristas
	uint32_t m2 = 0;

	//inicializo mi nuevo grafo de aristas
	EdgesList g2;

	//por cada arista dentro de mi grafo original creo 60^2 aristas
	for (uint32_t i = 0; i < m; i++) {

			//parseo el origen, destino y peso
		    uint32_t origen = get<0>(g[i]); 
            uint32_t destino = get<1>(g[i]); 
            uint32_t distancia = get<2>(g[i]); 

			/* Genesis (capitulo 3) La serpiente Lucifer engaña a Eva, Ella y después Adán participan del fruto prohibido 
			* su Simiente herirá la cabeza de la serpiente, Se explica el papel de la mujer y el del hombre
			* Adán y Eva son echados del Jardín de Edén — Adán preside — Eva llega a ser la madre de todos los vivientes.
			*/

			//ADVERTENCIA, mantener este código alejado de los niños, pues su ingesta puede resultar en toxicidad.
			for(uint32_t j = (origen * 61); j < 61 * (origen + 1); j++){
				for (uint32_t z = (destino * 61); z < 61 * (destino + 1); z++){

					/* en particular solo agrego aristas si (z) que representa la cantidad de litros que voy a cargar
					* es mayor o igual a la distancia que tiene el tramo. */
					if(distancia <= z){
						g2.push_back(std::make_tuple(j, z, precios[origen] * z));
						m2++;
					}
				}
			}
	}

	// me quede sin etiquetas de la biblia.
	for (uint32_t i = 0; i < n; i++) {

		Distancias dverdaderas;
		dverdaderas.resize(n, UINT32_MAX);

		for(uint32_t j = i * 61; j < 61 * (i + 1); j++){

			//lo facilito.
			Distancias dcrudas = BellmanFord(g2, n2, m2, i);

			//calculo el min dist a vertice de cada bloque 0..61
			for (uint32_t k = 0; k < n; i++) {

				uint32_t min = UINT32_MAX;
				for(uint32_t w = k * 61; w < 61 * (k + 1); j++) {
					if(min > dcrudas[w]){
						min = w;
					}
				}
				if(dverdaderas[k] > min){
					dverdaderas[k] = min ;
				}
			}
		}

		// legado a este punto acabo de calcular 61 vertices en teoría (61 formas de salir a revisar los vecinos)
		// distancias verdaderas deberían ser los minimos efectivos.
		for (uint32_t t = 0; t < n; t++) {
			resultado.push_back({i, t, dverdaderas[t]});
		}
	}
	return resultado;
}
