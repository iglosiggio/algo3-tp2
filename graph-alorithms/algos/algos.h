#ifndef ALGOS_H
#define ALGOS_H

#include <cstdint>
#include <vector>
#include <utility>
#include <tuple>

//lista de aristas, se ordena por origen, destino, peso.
using ListaDeAristas = std::vector<std::tuple<uint32_t, uint32_t, uint32_t>>;

using Costes = std::vector<std::vector<uint32_t>>;

/* el máximo siempre lo entendemos como 1 más, ya que en el auto puede haber de 0 a 60 de nafta, 
 * es decir 61 posibles escenarios */
const int MAX_NAFTA = 61;

extern const char* algo;

Costes ciudades(uint32_t nOriginal, uint32_t n, uint32_t m, ListaDeAristas);

#endif
