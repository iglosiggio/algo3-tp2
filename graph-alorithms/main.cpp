#include <chrono>
#include <iostream>

#include "algos/algos.h"


//Exclusivo de floyd warshall
bool targetIsFloydWarshall = floydWarshallDirectory.compare(algo) == 0;

void generarMatriz(uint32_t n, Matriz& matriz){

	//armo la matriz
	matriz.resize(n);
	uint32_t mitadMax = UINT32_MAX / 2;
	for(int i = 0; i < n; i++) {
		std::vector<uint32_t> row;
		row.resize(n, mitadMax);
		row[i] = 0;
		matriz[i] = row;
	}
}

void AgregarArista(ListaDeAristas& g2, Matriz& matriz, int32_t a, int32_t  b, int32_t costo){

	//no es lo más limpio que me gustaría pero es: o hacer esto o replicar todo el código.
	if(targetIsFloydWarshall){
		matriz[a][b] = costo;
	} else {
		g2.push_back(std::make_tuple(a, b, costo));
	}
}


//Trasnformacion del grafo original.
void TrasnformarGrafo(ListaDeAristas& g2, Matriz& matriz, uint32_t& m2, uint32_t n2, uint32_t* precios, uint32_t mOriginal){
	
	for (uint32_t i = 0; i < mOriginal; i++) {

		int32_t origen;
		int32_t destino;
		int32_t distancia;
		std::cin >> origen >> destino >> distancia;			


		int32_t litrosCargadosEnB = 0;
		for(int32_t verticeA = origen * MAX_NAFTA; verticeA < MAX_NAFTA * (origen + 1); verticeA++) {


			int32_t litrosCargadosEnA = 0;
			for(int32_t verticeB = destino * MAX_NAFTA; verticeB < MAX_NAFTA * (destino + 1); verticeB++) {
				
				if(distancia + litrosCargadosEnA < MAX_NAFTA) {
					
					int32_t costo = 0;
					if( distancia + litrosCargadosEnA - litrosCargadosEnB >= 0) {
						costo = precios[origen] * (distancia + litrosCargadosEnA - litrosCargadosEnB);
					}
					AgregarArista(g2, matriz, verticeA, verticeB, costo);
					m2++;
				}

				//las aristas tienen dirección, así que si puedo agregar uno, agrego el espejo con su respectivo costo.
				if(distancia + litrosCargadosEnB < MAX_NAFTA) {
					
					uint32_t costo = 0;
					if(distancia + litrosCargadosEnB - litrosCargadosEnA >= 0) {
						costo = precios[destino] * (distancia + litrosCargadosEnB - litrosCargadosEnA);
					}
					AgregarArista(g2, matriz, verticeB, verticeA, costo);
					m2++;
				}
				litrosCargadosEnA++;
			}
			litrosCargadosEnB++;
		}
	}
}





int main(int argc, char** argv) {

	uint32_t nOriginal;
	uint32_t mOriginal;

	std::cin >> nOriginal >> mOriginal;
	uint32_t n2 = nOriginal * MAX_NAFTA;
	uint32_t m2 = 0;

	uint32_t *precios = new uint32_t[nOriginal];

	for (int i = 0; i < nOriginal; i++)
		std::cin >> precios[i];

	//inicializo mi nuevo grafo de aristas
	ListaDeAristas g2;

	//o nueva matriz si el algoritmo target es floyd warshall.
	Matriz matriz;
	if(targetIsFloydWarshall) {
		generarMatriz(n2, matriz);
	}

	TrasnformarGrafo(g2, matriz, m2, n2, precios, mOriginal);

	//entrada parseada, listo para inicializar el algoritmo.
	auto start = std::chrono::steady_clock::now();
	auto resultado = ciudades(nOriginal, n2, m2, g2, matriz);
	auto end = std::chrono::steady_clock::now();

	double time = std::chrono::duration<double, std::milli>(end - start).count();

	std::cerr << algo << ' ' << time << std::endl;
	if(resultado.size() >= 1){
		for(int i= 0; i < resultado.size(); i++){
			std::cout << resultado[i][0] << ' ' << resultado[i][1] << ' ' << resultado[i][2] << std::endl;
		}
	}
	
}
