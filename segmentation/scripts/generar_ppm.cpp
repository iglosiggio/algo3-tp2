#include <iostream>
#include <unordered_map>
#include <cstdint>

/* La componente actual */
int C;

struct color {
	uint8_t r;
	uint8_t g;
	uint8_t b;

	color() {
		srand(C);
		r = random();
		g = random();
		b = random();
	}
};

void print_color(struct color c) {
	std::cout << (int) c.r << ' ' << (int) c.g << ' ' << ' ' << (int) c.b;
}

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "Uso: " << argv[0] << " <ancho> <alto>"
			  << std::endl;
	}
	int ancho = std::stoi(argv[1]);
	int alto = std::stoi(argv[2]);
	std::unordered_map<int, struct color> colores;

	std::cout << "P3" << std::endl;
	std::cout << ancho << ' ' << alto << std::endl;
	std::cout << 255 << std::endl;

	for (int i = 0; i < ancho * alto; i++) {
		std::cin >> C;
		print_color(colores[C]);

		if ((i + 1) % ancho)
			std::cout << std::endl;
		else
			std::cout << ' ';
	}
}
