#include <iostream>

int main() {
    // Definir el laberinto como una matriz 5x5
    int laberinto1[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    
    int laberinto2[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0}
    };

    // Imprimir el laberinto
    std::cout << "Laberinto:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << laberinto[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
