#include <iostream>
#include <vector>
#include <cstdint>

#include "disjoint-set.h"

/* Éste algoritmo trata la imagen como un arreglo contiguo y enumera a los
 * píxeles como idx = y * ancho + x. */

#define MIN(x, y) ((x) > (y) ? (y) : (x))

/* Eje: {desde, hasta} */
using Eje = std::pair<int, int>;

/* TODO: K es constante ahora, estaría bueno probar variándolo */
bool misma_region(Eje e, int diff, disjoint_set* ds) {
	int Ci = ds_mint(ds, e.first, 600);
	int Cj = ds_mint(ds, e.second, 600);

	return diff <= MIN(Ci, Cj);
}

int main(int argc, char** argv) {
	int ancho;
	int alto;
	uint8_t* imagen;
	std::vector<Eje> ejes[256];

	std::cin >> ancho >> alto;
	imagen = new uint8_t[ancho * alto];

	/* Leemos la primera línea que tiene un sólo tipo de aristas */
	std::cin >> imagen[0];
	for (int i = 1; i < ancho; i++) {
		std::cin >> imagen[i];
		uint8_t peso_w = abs(imagen[i-1] - imagen[i]);
		ejes[peso_w].emplace_back(i-1, i);
	}

	/* Leemos el resto de la foto */
	for (int i = ancho; i < ancho * alto; i++) {
		std::cin >> imagen[i];

		/* Estas aristas requieren que el píxel no sea el primero de la
		 * fila */
		if (i % ancho) {
			uint8_t peso_w = abs(imagen[i-1] - imagen[i]);
			ejes[peso_w].emplace_back(i-1, i);
			uint8_t peso_nw = abs(imagen[i-1 - ancho] - imagen[i]);
			ejes[peso_nw].emplace_back(i-1 - ancho, i);
		}

		uint8_t peso_n = abs(imagen[i - ancho] - imagen[i]);
		ejes[peso_n].emplace_back(i - ancho, i);

		/* Esta arista requiere que el píxel no sea el último de la
		 * fila */
		if ((i + 1) % ancho) {
			uint8_t peso_ne = abs(imagen[i+1 - ancho] - imagen[i]);
			ejes[peso_ne].emplace_back(i+1 - ancho, i);
		}
	}

	disjoint_set* ds = ds_new(ancho * alto);

	int diff = 0;
	while(diff != 255 && !ejes[diff].empty()) {
		while (ejes[diff].empty() && diff < 256)
			diff++;
		if (diff == 256)
			break;

		Eje e = ejes[diff].back();
		ejes[diff].pop_back();

		if (misma_region(e, diff, ds))
			ds_union(ds, e.first, e.second, diff);
	}

	for(int i = 0; i < ancho * alto; i++) {
		std::cout << ds_find(ds, i);

		if ((i + 1) % ancho)
			std::cout << ' ';
		else
			std::cout << std::endl;
	}

	return 0;
}

