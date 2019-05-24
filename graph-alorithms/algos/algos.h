#ifndef ALGOS_H
#define ALGOS_H

#include <cstdint>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath> 
#include <string>

using namespace std;

//aristas representadas como origen, destino, peso.
using ListaDeAristas = vector<tuple<uint32_t, uint32_t, uint32_t>>;

//vecinos representados como claves origen -> pares(destino, peso)
using ListaDeVecinos = vector<vector<pair<uint32_t, uint32_t>>>;

//matriz columna indica origen, fila indica destino, pos[origen][destino] el peso.
using Matriz = vector<vector<uint32_t>>;


//el resultado final se representa con esta estructura. En cada fila 3 valores.
using Costes = vector<vector<uint32_t>>;

/* el máximo siempre lo entendemos como 1 más, ya que en el auto puede haber de 0 a 60 de nafta, 
 * es decir 61 posibles escenarios */
const int MAX_NAFTA = 61;

extern const char* algo;

Costes ciudades(uint32_t nOriginal, uint32_t n, uint32_t m, ListaDeAristas&, ListaDeVecinos&, Matriz&);

#endif
