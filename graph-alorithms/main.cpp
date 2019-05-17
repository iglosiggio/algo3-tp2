#include <stdint.h>

#include <chrono>
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <iostream>

#include "graph-algos.h"

using namespace std;
using listaAdjacencia = vector< list< pair<uint32_t, uint32_t> > >


int main(int argc, char** argv) {
	uint32_t n;
	uint32_t m;
	uint32_t *naftaprecios;

	cin >> n >> m;
	naftaprices = new uint32_t[n];

	for (int i = 0; i < n; i++)
		cin >> naftaprecios[i];

    // grafo es una lista de vector de lista - pair.first es el vecino - pair.second es el peso
    listaAdjacencia grafo(n);
     
	uint32_t origen;
	uint32_t destino;
	uint32_t peso;
    for (int i = 1; i <= edges; ++i) {
         
        cin >> origen >> destino >> peso;
        grafo[origen].push_back(make_pair(destino, peso));
    }

    //entrada parseada, listo para inicializar el algoritmo.
	auto start = chrono::steady_clock::now();
	resultado = ciudades(n, m, naftaprecios, grafo);
	auto end = chrono::steady_clock::now();

	double time = chrono::duration<double, milli>(end - start).count();

	cout << algo << ' ' << resultado << ' ' << time << endl;
}