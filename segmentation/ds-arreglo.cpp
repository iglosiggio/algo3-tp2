#include <vector>
#include <cstdint>
#include <cassert>

struct componente {
	std::vector<int> nodos;
	int padre;
	float idiff;
};


using disjoint_set = std::vector<struct componente>;

extern "C" {

disjoint_set* ds_new(size_t size) {
	disjoint_set* ds = new disjoint_set(size);

	for (int i = 0; i < size; i++) {
		componente& C = (*ds)[i];
		C.nodos.push_back(i);
		C.padre = i;
	}

	return ds;
}

int ds_find(disjoint_set* ds, int a) {
	return (*ds)[a].padre; 
}

void ds_union(disjoint_set* ds, int a, int b, float diff) {
	a = ds_find(ds, a);
	b = ds_find(ds, b);

	if (a != b) {
		struct componente* Ca = &(*ds)[a];
		struct componente* Cb = &(*ds)[b];

		if (Ca->nodos.size() < Cb->nodos.size()) {
			std::swap(a, b);
			std::swap(Ca, Cb);
		}

		for (int v : Cb->nodos) {
			Ca->nodos.push_back(v);
			(*ds)[v].padre = a;
		}

		Ca->idiff = diff;
		Cb->nodos.clear();
	}
}

float ds_idiff(disjoint_set* ds, int a, float K) {
	a = ds_find(ds, a);
	struct componente& Ca = (*ds)[a];
	return Ca.idiff + K / Ca.nodos.size();
}

}
