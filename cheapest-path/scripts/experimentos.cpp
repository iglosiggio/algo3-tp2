#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>

#include <stdlib.h>

using namespace std;

using Precios = vector<int>;
using Aristas = vector<vector<int>>;



void imprimirResultados(int n, int m, Precios precios, Aristas aristas) {
    cout << n << " " << m << endl;

    for(int i = 0; i < precios.size(); i++){
        cout << precios[i] << endl;
    }

    for(int i = 0; i < aristas.size(); i++){
        cout << aristas[i][0] << " " << aristas[i][1] << " " << aristas[i][2] << endl;
    }
}

//pasasr vertices por param
int main(int argc, char** argv) {
    if(argc < 3) {
        cerr << "Se necesitan vertices como parametro" << endl;
        return 0;
    }

    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);

    if (argc >= 4)
        srand(std::stoi(argv[3]));
    
    Precios precios(n);

    Aristas aristas;
    set<pair<int,int>> aristasSet; 

    if (n <= 0){
        cerr << "Los vertices tienen que ser mayores a 0."  << endl;
        return 0;
    }
    
    if (m < 0){
        cerr << "Las aristas tienen que vivir entre 0 y (n -1)"  << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        // Buscamos un precio que dificulte determinar cual es el costo minimo.
        int precio = rand() % 101 + 100;
		precios[i] = precio;
    }

    //primero generamos un arbol conexo
    for(int i = 1; i < n; i++) {
        // buscamos distancias entre 1 y 3/4 de W.
        int dist = rand() % 61;
        int vRandom = rand() % i;

        aristasSet.insert({vRandom, i});
        aristas.push_back({vRandom, i, dist});
    }

    for(int i = 0; i < m; i++){
        do {
            int va = rand() % (n -1);
            int vb = va + rand() % (n - va);
            int dist = rand() % 61;

            if(!aristasSet.count({va, vb})){
                aristasSet.insert({va, vb});
                aristas.push_back({va, vb, dist});
                break;
            }
        } while(1);
    }

    imprimirResultados(n, m + n - 1, precios, aristas);
}
