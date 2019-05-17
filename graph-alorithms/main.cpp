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

	/* Grafo es un vector de vecindades, cada vecindad es un vector de
	 * aristas con la forma {vecino, distancia} */
	Grafo grafo(n);

	uint32_t origen;
	uint32_t destino;
	uint32_t peso;
	for (int i = 1; i <= n; ++i) {
		std::cin >> origen >> destino >> peso;
		grafo[origen].push_back({destino, peso});
	}

	//entrada parseada, listo para inicializar el algoritmo.
	auto start = std::chrono::steady_clock::now();
	auto resultado = ciudades(n, m, precios, grafo);
	auto end = std::chrono::steady_clock::now();

	double time = std::chrono::duration<double, std::milli>(end - start).count();

	std::cerr << algo << ' ' << time << std::endl;
	/* TODO: Imprimir resultados */
}
