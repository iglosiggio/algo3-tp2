#include "algos.h"

#include <iostream>


const char* algo = __FILE__;

Costes resultado;

//Dijkstra es un algorimto 1-node to n-node así que el algoritmo en si se debe ejecutar n veces.
void dijkstra(ListaDeAristas g, uint32_t v_inicial, uint32_t* precios){

}

Costes ciudades(uint32_t nOriginal, uint32_t n, uint32_t m, ListaDeAristas& gAristas, ListaDeVecinos& gVecinos, Matriz& matriz) {

	for(int j = 0 ; j < gVecinos[0].size(); j++){
		std::cout << get<0>(gVecinos[0][j]) << std::endl;
	}
	std::cout << "-----------------" << std::endl;
	for(int j = 0 ; j < gVecinos[61].size(); j++){
		std::cout << get<0>(gVecinos[61][j]) << std::endl;
	}

	return resultado;
}


