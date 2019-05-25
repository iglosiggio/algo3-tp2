#include <iostream>

#define BYTE(v, i) (((v) >> (i)) & 0xFF)

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "Uso: " << argv[0] << " <ancho> <alto>"
			  << std::endl;
	}
	int ancho = std::stoi(argv[1]);
	int alto = std::stoi(argv[2]);
	int C;

	std::cout << "P3" << std::endl;
	std::cout << ancho << ' ' << alto << std::endl;
	std::cout << 255 << std::endl;

	for (int i = 0; i < ancho * alto; i++) {
		std::cin >> C;
		std::cout << BYTE(C, 0) << ' ' << BYTE(C, 1) << ' '
			  << BYTE(C, 2);

		if ((i + 1) % ancho)
			std::cout << std::endl;
		else
			std::cout << ' ';
	}
}
