#include <chrono>
#include <iostream>

#include "algos/algos.h"


string floydWarshallDir = "algos/floyd-warshall.cpp";

ListaDeVecinos gVecinos;
Matriz matriz;


void generarMatriz(uint32_t n) {
	std::vector<uint32_t> fila(n, INFINITO);
	matriz.resize(n, fila);
}

void generarVecinos(uint32_t n) {
	vector<pair<uint32_t, uint32_t>> vect;
	gVecinos.resize(n, vect);
}

/* No es lo más limpio que me gustaría pero es: o hacer esto o replicar todo el
 * código. */
void AgregarArista(int32_t a, int32_t  b, int32_t costo){
	if(floydWarshallDir.compare(algo) == 0){
		matriz[a][b] = costo;
	} else {
		gVecinos[a].push_back({b, costo});
	}
}

void TransformarGrafo(uint32_t& m2, uint32_t n2, uint32_t* precios, uint32_t mOriginal, uint32_t nOriginal) {
	
	for(uint32_t i = 0; i < nOriginal; i++){
		int32_t vertice = i * MAX_NAFTA;

		for (int32_t litros = 1; litros < MAX_NAFTA; litros++) {
				AgregarArista(vertice + litros - 1, vertice + litros, precios[i]);
				m2++;
		}
	}
	
	for (uint32_t i = 0; i < mOriginal; i++) {
		int32_t origen;
		int32_t destino;
		int32_t distancia;

		std::cin >> origen >> destino >> distancia;

		int32_t verticeA = origen * MAX_NAFTA;
		int32_t verticeB = destino * MAX_NAFTA;

		for (int32_t litros = 0; litros < MAX_NAFTA; litros++) {

			if(litros >= distancia){
				AgregarArista(verticeA + litros, verticeB + litros - distancia, 0);
				AgregarArista(verticeB + litros, verticeA + litros - distancia, 0);
				m2 = m2 + 2;
			}
		}
	}
}

int main(int argc, char** argv) {
	uint32_t nOriginal;
	uint32_t mOriginal;

	std::cin >> nOriginal >> mOriginal;

	uint32_t *precios = new uint32_t[nOriginal];
	uint32_t n2 = nOriginal * MAX_NAFTA;
	uint32_t m2 = 0;

	for (int i = 0; i < nOriginal; i++)
		std::cin >> precios[i];

	if(floydWarshallDir.compare(algo) == 0) {
		generarMatriz(n2);
	} else {
		generarVecinos(n2);
	}


	auto start = std::chrono::steady_clock::now();
	TransformarGrafo(m2, n2, precios, mOriginal, nOriginal);
	
	auto resultado = ciudades(nOriginal, n2, m2, gVecinos, matriz);
	auto end = std::chrono::steady_clock::now();

	double time = std::chrono::duration<double, std::milli>(end - start).count();

	std::cerr << algo << ' ' << nOriginal << ' ' << mOriginal << ' ' << time << std::endl;

	if(resultado.size() >= 1)
		for(int i= 0; i < resultado.size(); i++)
			std::cout << resultado[i][0] << ' ' << resultado[i][1]
				  << ' ' << resultado[i][2] << std::endl;

}
