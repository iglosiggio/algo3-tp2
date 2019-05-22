#include "algos.h"
#include <iostream>

const char* algo = __FILE__;

using namespace std;
Costes floydWarshall(vector<vector<uint32_t>> g, uint32_t n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if ((g[i][k] * g[k][j] != 0) && (i != j)) {
                    if ((g[i][k] + g[k][j] < g[i][j]) || (g[i][j] == 0)) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
    }
	Costes resultado;
    for (uint32_t i = 0; i < n; i++) {
        for (uint32_t j = 0; j < n; j++) {
			resultado.push_back({i,j, g[i][j]});
        }
    }
	return resultado;
}

Costes ciudades(uint32_t n, uint32_t m, uint32_t* precios, EdgesList g) {

	vector<vector<uint32_t>> gMatriz;

	//armo la matriz
	vector<uint32_t> row;
	row.resize(n, 0);
	gMatriz.resize(n, row);

    for (int i = 0; i < m; i++) {
		gMatriz[get<0>(g[i])][get<1>(g[i])] = get<2>(g[i]);
		gMatriz[get<1>(g[i])][get<0>(g[i])] = get<2>(g[i]);
    }

	return floydWarshall(gMatriz, n);
}