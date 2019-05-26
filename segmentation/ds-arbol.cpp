#include <vector>
#include <cstdint>

struct componente {
	int padre;
	int tamanio;
	float idiff;
};

using disjoint_set = std::vector<struct componente>;

extern "C" {

disjoint_set* ds_new(size_t size, float K) {
	return new disjoint_set(size, {-1, 1, K});
}

int ds_find(disjoint_set* ds, int a) {
	int padre = (*ds)[a].padre;
	return padre == -1 ? a : ds_find(ds, padre);
}

void ds_union(disjoint_set* ds, int a, int b, float diff, float K) {
	a = ds_find(ds, a);
	b = ds_find(ds, b);

	if (a != b) {
		struct componente* Ca = &(*ds)[a];
		struct componente* Cb = &(*ds)[b];

		if (Ca->tamanio < Cb->tamanio) {
			std::swap(Ca, Cb);
			std::swap(a, b);
		}

		Cb->padre = a;
		Ca->tamanio += Cb->tamanio;
		Ca->idiff = diff + K / Ca->tamanio;
	}
}

float ds_idiff(disjoint_set* ds, int a) {
	a = ds_find(ds, a);
	return (*ds)[a].idiff;
}

}
