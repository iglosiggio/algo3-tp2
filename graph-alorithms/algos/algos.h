#ifndef ALGOS_H
#define ALGOS_H

#include <cstdint>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath> 
#include <string>

//lista de aristas, se ordena por origen, destino, peso.
using ListaDeAristas = std::vector<std::tuple<uint32_t, uint32_t, uint32_t>>;

using Costes = std::vector<std::vector<uint32_t>>;

//Pueden que sea lo mismo que costes en estructura, pero su uso es para la matriz de floydWarshall, no para representar costes.
using Matriz = std::vector<std::vector<uint32_t>>;

/* el máximo siempre lo entendemos como 1 más, ya que en el auto puede haber de 0 a 60 de nafta, 
 * es decir 61 posibles escenarios */
const int MAX_NAFTA = 61;

/* el algoritmo de floyd-warshall lo tomaremos como un caso particular 
* ya que generaremos una matriz en ves de una lista de aristas */
const std::string floydWarshallDirectory = "algos/floyd-warshall.cpp";

extern const char* algo;

Costes ciudades(uint32_t nOriginal, uint32_t n, uint32_t m, ListaDeAristas&, Matriz&);

#endif
