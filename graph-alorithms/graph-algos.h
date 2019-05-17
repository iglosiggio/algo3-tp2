#ifndef ALGOS_H
#define ALGOS_H

#include <cstdint>
#include <vector>
#include <list>
#include <utility>

using listaAdjacencia = std::vector< list< pair<uint32_t, uint32_t> > >

uint64_t ciudades(uint32_t n, uint32_t m, uint32_t* naftaprecios, listaAdjacencia grafo);
extern const char* algo;

#endif