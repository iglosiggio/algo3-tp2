#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdint>
#include <cmath>

#include "disjoint-set.h"

/* Esta implementación trata la imagen como un arreglo contiguo y enumera a los
 * píxeles como idx = y * ancho + x. */

#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define DIFF(a, b) fabs((a) - (b))
#define VERT(x, y) ((y) * ancho + (x))
#define PIX(foto, x, y) (foto)[VERT(x, y)]
#define PIXDIFF(foto, x, y, dx, dy) DIFF(PIX(foto, x, y), \
					 PIX(foto, (x) + (dx), (y) + (dy)))

/* Eje: {desde, hasta, peso} */
struct Eje {
	int desde;
	int hasta;
	float peso;
};

bool operator<(const Eje& a, const Eje& b) {
	return a.peso < b.peso;
}

bool misma_region(Eje e, disjoint_set* ds) {
	float a = ds_idiff(ds, e.desde);
	float b = ds_idiff(ds, e.hasta);

	return e.peso <= MIN(a, b);
}

/* NOTA: Leer directamente un uint8_t lee una letra, no un número,
 *       tenemos que leer un entero y convertirlo a uint8 */
uint8_t leer() {
	unsigned dato;
	std::cin >> dato;
	return dato;
}

/* Chafado del paper original */
#define GAUSSIAN_WIDTH 4
void blur(int ancho, int alto, float* imagen, float sigma) {
	sigma = MAX(sigma, 0.01);

	/* Crear la máscara */
	int width = ceil(GAUSSIAN_WIDTH * sigma) + 1;
	float sum = 0;
	std::vector<float> mask(width);

	/* Cargo la máscara */
	for (int i = 0; i < width; i++)
		sum += mask[i] = exp(-0.5 * (i/sigma) * (i/sigma));
	sum = 2 * sum - 1;

	/* Normalizo la máscara */
	for (int i = 0; i < width; i++)
		mask[i] /= sum;

	/* Hago la convolución en el eje X */
	for (int y = 0; y < alto; y++)
		for (int x = 0; x < ancho; x++) {
			float sum = PIX(imagen, x, y);

			for (int i = 1; i < width; i++)
				sum += mask[i] * (
					PIX(imagen, MAX(x - i, 0), y)
					+ PIX(imagen, MIN(x + i, ancho - 1), y)
				);

			PIX(imagen, x, y) = sum;
		}

	/* Hago la convolución en el eje Y */
	for (int y = 0; y < alto; y++)
		for (int x = 0; x < ancho; x++) {
			float sum = mask[0] * PIX(imagen, x, y);

			for (int i = 1; i < width; i++)
				sum += mask[i] * (
					PIX(imagen, x, MAX(y - i, 0))
					+ PIX(imagen, x, MIN(y + i, alto - 1))
				);

			PIX(imagen, x, y) = sum;
		}
}

std::vector<Eje> generarEjes(int ancho, int alto, float* imagen) {
	std::vector<Eje> ejes;
	ejes.reserve(ancho * alto * 4);

	for (int y = 0; y < alto - 1; y++)
		for (int x = 0; x < ancho; x++) {
			int v = y * ancho + x;

			float peso_s = PIXDIFF(imagen, x, y, 0, 1);
			ejes.push_back({v, v + ancho, peso_s});

			if (x) {
				float peso_sw = PIXDIFF(imagen, x, y, -1, 1);
				ejes.push_back({v, v + ancho - 1, peso_sw});
			}

			if (x + 1 != ancho) {
				float peso_e = PIXDIFF(imagen, x, y, 1, 0);
				ejes.push_back({v, v + 1, peso_e});

				float peso_se = PIXDIFF(imagen, x, y, 1, 1);
				ejes.push_back({v, v + ancho + 1, peso_se});
			}
		}

	return ejes;
}

int main(int argc, char** argv) {
	float K = 600;
	float sigma = 0.8;
	int ancho;
	int alto;
	float* imagen;

	if (argc >= 2)
		K = std::stof(argv[1]);
	if (argc >= 3)
		sigma = std::stof(argv[2]);

	std::cin >> ancho >> alto;
	imagen = new float[ancho * alto];

	for (int i = 0; i < ancho * alto; i++)
		imagen[i] = leer();

	blur(ancho, alto, imagen, sigma);

	std::vector<Eje> ejes = generarEjes(ancho, alto, imagen);

	/* Ordeno */
	std::sort(ejes.begin(), ejes.end());

	disjoint_set* ds = ds_new(ancho * alto, K);

	/* Segmento */
	for (Eje& e : ejes)
		if (misma_region(e, ds))
			ds_union(ds, e.desde, e.hasta, e.peso, K);

	/* Escribo */
	for (int i = 0; i < ancho * alto; i++) {
		std::cout << ds_find(ds, i);

		if ((i + 1) % ancho)
			std::cout << ' ';
		else
			std::cout << std::endl;
	}

	return 0;
}
