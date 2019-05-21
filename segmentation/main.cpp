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
bool misma_region(Eje e, int diff, disjoint_set* ds, int K) {
	int Ci = ds_idiff(ds, e.first, K);
	int Cj = ds_idiff(ds, e.second, K);

	return diff <= MIN(Ci, Cj);
}

/* Devuelve `true` si pudo conseguir un eje y `false` si no quedan más ejes */
bool siguiente_eje(std::vector<Eje> ejes[256], int* i, Eje* e) {
		while (*i < 256 && ejes[*i].empty())
			(*i)++;

		if (*i == 256)
			return false;

		*e = ejes[*i].back();
		ejes[*i].pop_back();

		return true;
}

/* NOTA: Leer directamente un uint8_t lee una letra, no un número,
 *       tenemos que leer un entero y convertirlo a uint8 */
uint8_t leer() {
	unsigned dato;
	std::cin >> dato;
	return dato;
}

int main(int argc, char** argv) {
	int K = 600;
	int ancho;
	int alto;
	uint8_t* imagen;
	std::vector<Eje> ejes[256];

	if (argc == 2)
		K = std::stoi(argv[1]);

	std::cin >> ancho >> alto;
	imagen = new uint8_t[ancho * alto];

	/* Leemos la primera línea que tiene un sólo tipo de aristas */
	imagen[0] = leer();
	for (int i = 1; i < ancho; i++) {
		imagen[i] = leer();
		uint8_t peso_w = abs(imagen[i-1] - imagen[i]);
		ejes[peso_w].emplace_back(i-1, i);
	}

	/* Leemos el resto de la foto */
	for (int i = ancho; i < ancho * alto; i++) {
		imagen[i] = leer();

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
	Eje e;
	while(siguiente_eje(ejes, &diff, &e))
		if (misma_region(e, diff, ds, K))
			ds_union(ds, e.first, e.second, diff);

	for(int i = 0; i < ancho * alto; i++) {
		std::cout << ds_find(ds, i);

		if ((i + 1) % ancho)
			std::cout << ' ';
		else
			std::cout << std::endl;
	}

	return 0;
}

