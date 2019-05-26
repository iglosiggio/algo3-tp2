#ifndef __DISJOINT_SET_H__
#define __DISJOINT_SET_H__

#include <cstdint>

extern "C" {

/* NOTA: La biblioteca del disjoint_set maneja la diferencia interna de los
 *       compontentes. ¿Está bien esto? */

typedef void disjoint_set;

disjoint_set*	ds_new	(size_t size, float K);

void	ds_union	(disjoint_set*, int a, int b, float diff, float K);
int	ds_find		(disjoint_set*, int a);
int	ds_size		(disjoint_set*, int a);
float	ds_idiff	(disjoint_set*, int a);

}

#endif
