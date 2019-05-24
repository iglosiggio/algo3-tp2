#include <chrono>
#include <iostream>

#include "algos/algos.h"

int main(int argc, char** argv) {

	uint32_t nOriginal;
	uint32_t mOriginal;

	std::cin >> nOriginal >> mOriginal;
	uint32_t n2 = nOriginal * MAX_NAFTA;
	uint32_t m2 = 0;

	uint32_t *precios = new uint32_t[nOriginal];

	for (int i = 0; i < nOriginal; i++)
		std::cin >> precios[i];

	//inicializo mi nuevo grafo
	ListaDeAristas g2;


	//PARTE 1, Transformación del grafo (g) -> al grafo (g2)
	for (uint32_t i = 0; i < mOriginal; i++) {

		int32_t origen;
		int32_t destino;
		int32_t distancia;

		std::cin >> origen >> destino >> distancia;			

		int32_t litrosCargadosEnB = 0;
		/* itero 61 veces, desde 0 a 60, desde 61 a 121 y así dependiendo si el origen es nodo 0,1 etc.
		*  TODO (ver si hay formas más prolijas de decir esto) */
		for(int32_t verticeA = origen * MAX_NAFTA; verticeA < MAX_NAFTA * (origen + 1); verticeA++) {

			int32_t litrosCargadosEnA = 0;

			/* Igual al primero itera 61 veces solo que con el nodo del destino. Recordemos #(aristas) <= 61^2 */
			for(int32_t verticeB = destino * MAX_NAFTA; verticeB < MAX_NAFTA * (destino + 1); verticeB++) {
				

				if(distancia + litrosCargadosEnA < MAX_NAFTA) {
					
					int32_t costo = 0;
					if( distancia + litrosCargadosEnA - litrosCargadosEnB >= 0) {
						costo = precios[origen] * (distancia + litrosCargadosEnA - litrosCargadosEnB);
					}
					g2.push_back(std::make_tuple(verticeA, verticeB, costo));
					m2++;
				}

				//las aristas tienen dirección, así que si puedo agregar uno, agrego el espejo.
				if(distancia + litrosCargadosEnB < MAX_NAFTA) {
					
					uint32_t costo = 0;
					if(distancia + litrosCargadosEnB - litrosCargadosEnA >= 0) {
						costo = precios[destino] * (distancia + litrosCargadosEnB - litrosCargadosEnA);
					}
					g2.push_back(std::make_tuple(verticeB, verticeA, costo));
					m2++;
				}
				litrosCargadosEnA++;
			}
			litrosCargadosEnB++;

		}
	}

	std::cout << "termine fase 1 con: " << m2 << " " << n2 << std::endl;

	//entrada parseada, listo para inicializar el algoritmo.
	auto start = std::chrono::steady_clock::now();
	auto resultado = ciudades(nOriginal, n2, m2, g2);
	auto end = std::chrono::steady_clock::now();


	double time = std::chrono::duration<double, std::milli>(end - start).count();

	std::cerr << algo << ' ' << time << std::endl;
	if(resultado.size() >= 1){
		for(int i= 0; i < resultado.size(); i++){
			std::cout << resultado[i][0] << ' ' << resultado[i][1] << ' ' << resultado[i][2] << std::endl;
		}
	}
	
}
