#include <chrono>
#include <iostream>

#include "algos/algos.h"


string floydWarshallDir = "algos/floyd-warshall.cpp";
string bellmanFordDir = "algos/bellman-ford.cpp";
string dijkstraDir = "algos/dijkstra.cpp";
string pqDijkstraDir = "algos/pq-dijkstra.cpp";

ListaDeAristas gAristas;
ListaDeVecinos gVecinos;
Matriz matriz;


void generarMatriz(uint32_t n){

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

void generarVecinos(uint32_t n){

	//armo la lista de vecinos
	vector<tuple<uint32_t, uint32_t>> vect;
	gVecinos.resize(n, vect);
}

//no es lo más limpio que me gustaría pero es: o hacer esto o replicar todo el código.
void AgregarArista(int32_t a, int32_t  b, int32_t costo){

	//floyd warshall implementa matriz
	if(floydWarshallDir.compare(algo) == 0){
		matriz[a][b] = costo;
	}

	//bellman ford implementa lista de aristas
	if(bellmanFordDir.compare(algo) == 0) {
		gAristas.push_back(std::make_tuple(a, b, costo));
	}

	//Ambos dijstras implementan listas de vecinos
	if(dijkstraDir.compare(algo) == 0) {
		gVecinos[a].push_back({b, costo});
	}
	if(pqDijkstraDir.compare(algo) == 0) {
		gVecinos[a].push_back({b, costo});
	}
}


//Trasnformacion del grafo original.
void TrasnformarGrafo(uint32_t& m2, uint32_t n2, uint32_t* precios, uint32_t mOriginal){
	
	for (uint32_t i = 0; i < mOriginal; i++) {

		int32_t origen;
		int32_t destino;
		int32_t distancia;
		std::cin >> origen >> destino >> distancia;			


		int32_t litrosCargadosEnB = 0;
		for(int32_t verticeA = origen * MAX_NAFTA; verticeA < MAX_NAFTA * (origen + 1); verticeA++) {


			int32_t litrosCargadosEnA = 0;
			for(int32_t verticeB = destino * MAX_NAFTA; verticeB < MAX_NAFTA * (destino + 1); verticeB++) {
				
				if(distancia + litrosCargadosEnA < MAX_NAFTA && litrosCargadosEnA - distancia <= litrosCargadosEnB) {
					
					int32_t costo = 0;
					if( distancia + litrosCargadosEnA - litrosCargadosEnB >= 0) {
						costo = precios[origen] * (distancia + litrosCargadosEnA - litrosCargadosEnB);
					}
					AgregarArista(verticeA, verticeB, costo);
					m2++;
				}

				//las aristas tienen dirección, así que si puedo agregar uno, agrego el espejo con su respectivo costo.
				if(distancia + litrosCargadosEnB < MAX_NAFTA && litrosCargadosEnB - distancia <= litrosCargadosEnA) {
					
					uint32_t costo = 0;
					if(distancia + litrosCargadosEnB - litrosCargadosEnA >= 0) {
						costo = precios[destino] * (distancia + litrosCargadosEnB - litrosCargadosEnA);
					}
					AgregarArista(verticeB, verticeA, costo);
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

	if(floydWarshallDir.compare(algo) == 0) {
		generarMatriz(n2);
	}

	if(dijkstraDir.compare(algo) == 0) {
		generarVecinos(n2);
	}


	TrasnformarGrafo(m2, n2, precios, mOriginal);
	cout << "vertices generados: " << n2 << " aristas generadas: " << m2 << endl;

	//entrada parseada, listo para inicializar el algoritmo.
	auto start = std::chrono::steady_clock::now();
	auto resultado = ciudades(nOriginal, n2, m2, gAristas, gVecinos, matriz);
	auto end = std::chrono::steady_clock::now();

	double time = std::chrono::duration<double, std::milli>(end - start).count();

	std::cerr << algo << ' ' << time << std::endl;
	if(resultado.size() >= 1){
		for(int i= 0; i < resultado.size(); i++){
			std::cout << resultado[i][0] << ' ' << resultado[i][1] << ' ' << resultado[i][2] << std::endl;
		}
	}
	
}
