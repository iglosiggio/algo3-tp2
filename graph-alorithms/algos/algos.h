#ifndef ALGOS_H
#define ALGOS_H

#include <cstdint>
#include <vector>
#include <utility>
#include <tuple>

//lista de aristas, se ordena por origen, destino, peso.
using EdgesList = std::vector<std::tuple<uint32_t, uint32_t, uint32_t>>;

using Costes = std::vector<std::vector<uint32_t>>;

extern const char* algo;

Costes ciudades(uint32_t n, uint32_t m, uint32_t* precios, EdgesList);

#endif
