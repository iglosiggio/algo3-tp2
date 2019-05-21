#include <chrono>
#include <iostream>

#include "algos/algos.h"

int main(int argc, char** argv) {
	uint32_t n;
	uint32_t m;
	uint32_t *precios;

	std::cin >> n >> m;
	precios = new uint32_t[n];

	for (int i = 0; i < n; i++)
		std::cin >> precios[i];

	/* Grafo es un vector de aristas, {origen, destino, distancia} */
	EdgesList grafo(m);

	uint32_t origen;
	uint32_t destino;
	uint32_t peso;
	for (int i = 0; i < m; i++) {
		std::cin >> origen >> destino >> peso;
		grafo[i] = std::make_tuple(origen, destino, peso);
	}

	//entrada parseada, listo para inicializar el algoritmo.
	auto start = std::chrono::steady_clock::now();

	auto resultado = ciudades(n, m, precios, grafo);
	auto end = std::chrono::steady_clock::now();


	double time = std::chrono::duration<double, std::milli>(end - start).count();

	std::cerr << algo << ' ' << time << std::endl;
	if(resultado.size() >= 1){
		for(int i= 0; i < resultado.size(); i++){
			std::cout << resultado[i][0] << ' ' << resultado[i][1] << ' ' << resultado[i][2] << std::endl;
		}
	}
}
