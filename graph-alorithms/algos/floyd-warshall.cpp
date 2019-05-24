#include "algos.h"
#include <iostream>

const char* algo = __FILE__;

using namespace std;
Costes resultado;

void floydWarshall(Matriz& matriz, uint32_t n) {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (matriz[i][k] + matriz[k][j] < matriz[i][j])
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
}

Costes ciudades(uint32_t nOriginal, uint32_t n, uint32_t m2, ListaDeAristas& gAristas, ListaDeVecinos& gVecinos, Matriz& matriz) {
    floydWarshall(matriz, n);

    for (uint32_t i = 0 ; i < nOriginal; i++){
		int filaTarget = i * MAX_NAFTA;

		for (uint32_t k = 0 ; k < nOriginal; k++) {

			int columnaTarget = k * MAX_NAFTA;

			if (i != k)
				resultado.push_back({i, k, matriz[filaTarget][columnaTarget]});
		}
	}
	return resultado;
}