#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Función para buscar una palabra en una dirección específica
bool buscarPalabraEnDireccion(const vector<vector<char>>& sopa, const string& palabra, int fila, int columna, int dirFila, int dirColumna) {
    int longitud = palabra.length();

    for (int i = 0; i < longitud; ++i) {
        int nuevaFila = fila + i * dirFila;
        int nuevaColumna = columna + i * dirColumna;

        // Verificar si estamos dentro de los límites de la sopa de letras
        if (nuevaFila < 0 || nuevaFila >= sopa.size() || nuevaColumna < 0 || nuevaColumna >= sopa[0].size()) {
            return false;
        }

        // Verificar si la letra actual coincide con la letra de la palabra
        if (sopa[nuevaFila][nuevaColumna] != palabra[i]) {
            return false;
        }
    }

    return true;
}

// Función para buscar una palabra en todas las direcciones
bool buscarPalabra(const vector<vector<char>>& sopa, const string& palabra) {
    int filas = sopa.size();
    int columnas = sopa[0].size();

    // Iterar sobre cada celda de la sopa
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            // Intentar encontrar la palabra en todas las direcciones posibles
            for (int dirFila = -1; dirFila <= 1; ++dirFila) {
                for (int dirColumna = -1; dirColumna <= 1; ++dirColumna) {
                    if (dirFila != 0 || dirColumna != 0) {  // Evitar la dirección (0, 0)
                        if (buscarPalabraEnDireccion(sopa, palabra, i, j, dirFila, dirColumna)) {
                            cout << "Palabra encontrada: " << palabra << " en la posicion (" << i << ", " << j << ")" << endl;
                            return true;  // Se encontró la palabra
                        }
                    }
                }
            }
        }
    }

    return false;  // La palabra no se encontró
}

int main() {
    // Definir la sopa de letras
    vector<vector<char>> sopa = {
        {'r', 's', 'p', 'c', 'p', 'p', 'x', 'i'},
        {'k', 'o', 'w', 'o', 'r', 'e', 'x', 'x'},
        {'r', 'c', 'w', 'c', 'z', 's', 'z', 'd'},
        {'q', 'o', 'm', 'i', 'l', 'c', 'q', 'o'},
        {'r', 'r', 'r', 'n', 'z', 'a', 'r', 'c'},
        {'x', 'r', 'n', 'e', 'q', 'd', 'q', 't'},
        {'z', 'i', 'w', 'r', 'm', 'o', 'n', 'o'},
        {'p', 's', 'q', 'o', 'k', 'r', 'v', 'r'},
        {'l', 't', 'k', 'w', 'n', 's', 'u', 'a'},
        {'u', 'a', 'v', 'm', 'o', 'v', 'n', 'l'},
        {'o', 'n', 'x', 'v', 'z', 'n', 'x', 'w'},
        {'c', 'a', 'm', 'a', 'r', 'e', 'r', 'o'}
    };

    // Lista de palabras a buscar
    vector<string> palabras = {"pescador", "cocinero", "camarero", "doctora", "socorrista"};

    // Buscar cada palabra en la sopa de letras
    for (const string& palabra : palabras) {
        if (!buscarPalabra(sopa, palabra)) {
            cout << "Palabra no encontrada: " << palabra << endl;
        }
    }

    return 0;
}
