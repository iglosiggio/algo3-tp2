#ifndef __DISJOINT_SET_H__
#define __DISJOINT_SET_H__

#include <cstdint>

extern "C" {

typedef void disjoint_set;

disjoint_set* ds_new(size_t size);
void ds_union(disjoint_set* ds, int a, int b, uint8_t diff);
int ds_find(disjoint_set*, int a);

/* NOTE: Este observador es específico del problema a resolver ¿Está bien
 *       ponerlo como parte de la biblioteca de disjoint_set? */
int ds_idiff(disjoint_set*, int a, int K);

}

#endif
