#include <vector>
#include <cstdint>

struct componente {
	int padre;
	int tamanio;
	int idiff;
};

using disjoint_set = std::vector<struct componente>;

extern "C" {

disjoint_set* ds_new(size_t size) {
	return new disjoint_set(size, {-1, 1, 0});
}

int ds_find(disjoint_set* ds, int a) {
	int padre = (*ds)[a].padre;
	return padre == -1 ? a : ds_find(ds, padre);
}

void ds_union(disjoint_set* ds, int a, int b, uint8_t diff) {
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
		Ca->idiff = diff;
	}
}

int ds_idiff(disjoint_set* ds, int a, int K) {
	a = ds_find(ds, a);
	struct componente Ca = (*ds)[a];
	return Ca.idiff + K / Ca.tamanio;
}

}
