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

	/* La idea es de nacho, no me hago responsable de si alguien pierde los ojos.
	*
	* dicen que el espiritu santo es como el viento, puede ser tan tierno 
	* como acariciar una hoja o tan violento como para doblar un arbol
	*/

	//multiplico los vertice por 61
	uint32_t n2 = n * 61;

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
			for(uint32_t j = (origen * 62); j < 62 * (origen + 1); j++){
				for (uint32_t z = (destino * 62); z < 62 * (destino + 1); z++){

					/* en particular solo agrego aristas si (z) que representa la cantidad de litros que voy a cargar
					* es mayor o igual a la distancia que tiene el tramo. */
					if(distancia <= z){
						g2.push_back(std::make_tuple(j, z, precios[origen] * z));
					}
				}
			}
	}



	for (uint32_t i = 0; i < n; i++) {
		BellmanFord(g, n, m, i);
	}

	return resultado;
}
