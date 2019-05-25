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

void TransformarGrafo(uint32_t& m2, uint32_t n2, uint32_t* precios, uint32_t mOriginal) {
	for (uint32_t i = 0; i < mOriginal; i++) {
		int32_t origen;
		int32_t destino;
		int32_t distancia;

		std::cin >> origen >> destino >> distancia;

		int32_t verticeA = origen * MAX_NAFTA;
		int32_t verticeB = destino * MAX_NAFTA;

		for (int32_t litrosEnA = 0; litrosEnA < MAX_NAFTA; litrosEnA++) {

			for (int32_t litrosEnB = 0; litrosEnB < MAX_NAFTA; litrosEnB++) {

				if (distancia + litrosEnB < MAX_NAFTA && litrosEnA - distancia <= litrosEnB) {
					uint32_t costo = 0;

					if(distancia >= litrosEnA - litrosEnB)
						costo = precios[origen] * (distancia + litrosEnB - litrosEnA);

					AgregarArista(verticeA + litrosEnA, verticeB + litrosEnB, costo);
					m2++;
				}

				//las aristas tienen dirección, así que si puedo agregar uno, agrego el espejo con su respectivo costo.
				if (distancia + litrosEnA < MAX_NAFTA && litrosEnB - distancia <= litrosEnA) {
					uint32_t costo = 0;

					if(distancia >= litrosEnB - litrosEnA)
						costo = precios[destino] * (distancia + litrosEnA - litrosEnB);

					AgregarArista(verticeB + litrosEnB, verticeA + litrosEnA, costo);
					m2++;
				}
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

	TransformarGrafo(m2, n2, precios, mOriginal);

	cout << "vertices generados: " << n2 << " aristas generadas: " << m2 << endl;

	auto start = std::chrono::steady_clock::now();
	auto resultado = ciudades(nOriginal, n2, m2, gVecinos, matriz);
	auto end = std::chrono::steady_clock::now();

	double time = std::chrono::duration<double, std::milli>(end - start).count();

	std::cerr << algo << ' ' << time << std::endl;

	if(resultado.size() >= 1)
		for(int i= 0; i < resultado.size(); i++)
			std::cout << resultado[i][0] << ' ' << resultado[i][1]
				  << ' ' << resultado[i][2] << std::endl;

}
