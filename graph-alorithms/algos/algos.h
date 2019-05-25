#ifndef ALGOS_H
#define ALGOS_H

#include <cstdint>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <string>

#define INFINITO (UINT32_MAX / 2)

using namespace std;

/* ListaDeAristas[i] = { origen, destino, peso } */
using ListaDeAristas = vector<tuple<uint32_t, uint32_t, uint32_t>>;

/* ListaDeVecinos[vertice][i] = { destino, peso } */
using ListaDeVecinos = vector<vector<pair<uint32_t, uint32_t>>>;

/* Matriz[desde][hasta] = peso */
using Matriz = vector<vector<uint32_t>>;

/* Distancias[hasta|] = costo */
using Distancias = vector<uint32_t>;

/* Costes[desde][hasta] = costo */
using Costes = vector<Distancias>;

/* Esta es la cantidad de estados del tanque. 0 a 60 litros de carga. */
const int MAX_NAFTA = 61;

extern const char* algo;

Costes ciudades(uint32_t nOriginal, uint32_t n, uint32_t m, ListaDeAristas&, ListaDeVecinos&, Matriz&);

#endif
