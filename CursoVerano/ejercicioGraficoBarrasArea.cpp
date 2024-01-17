#include <iostream>
#include <vector>
#include <cstdlib> // Necesario para la generación de números aleatorios
#include <ctime>   // Necesario para inicializar la semilla del generador de números aleatorios
#include <cmath>
using namespace std;

class Elemento{
    public:
        int barra;//altura de la barra
        Elemento(int barra){this->barra=barra;}
};


int generarAlturaAleatoria() {
    return rand() % 10 + 1; // Generar número aleatorio entre 1 y 10
};

//esto es de orden n o(n)->lineal || Quedo buenardo
void calcularArea(const vector<Elemento>& elementos) {
    int mayorArea=-1,pos1=-1,pos2=-1;
    int n= elementos.size();
    int izquierda=0;
    int derecha=n-1;

    while(izquierda<derecha) {
        int altura1= elementos[izquierda].barra;
        int altura2= elementos[derecha].barra;
        int base= (derecha-izquierda);

        int areaRectangulo= min(altura1,altura2)*base;
        int areaTriangulo= abs(altura1-altura2)*base/2;
        int areaTotal= areaRectangulo+areaTriangulo;
        
        cout<<areaTotal<<endl;
        if(areaTotal>mayorArea) {
            mayorArea=areaTotal;
            pos1=izquierda;
            pos2=derecha;
        }

        //Mover los punteros hacia el interior de la lista
        if(altura1 < altura2) {
            izquierda++;
        } else {
            derecha--;
        }
    }
    cout<<"Área mayor: "<<mayorArea<<endl;
    cout<<"Elementos: "<<elementos[pos1].barra<<" y "<<elementos[pos2].barra<<endl;
    
    for(int k=0;k<n;k++){
        if(elementos[k].barra==elementos[pos1].barra||elementos[k].barra==elementos[pos2].barra){
            cout<<"->"<<(k+1)<<")";
        }else{
            cout<<"  "<<(k+1)<<")";
        }
        for(int m=0;m<(elementos[k].barra);m++){
            cout<<"o";
        }
        cout<<endl;
    }
}

/*
void calcularArea(const vector<Elemento>& elementos) {
    int mayorArea = -1;
    int indiceBarra1 = -1;
    int indiceBarra2 = -1;
    int n = elementos.size();

    for (int i = 0; i < n; ++i) {
        int altura1 = elementos[i].barra;

        for (int j = i + 1; j < n; ++j) {
            int altura2 = elementos[j].barra;
            int base = j - i;
            int areaRectangulo = min(altura1, altura2) * base;
            int areaTriangulo = abs(altura1 - altura2) * base / 2;
            int areaTotal = areaRectangulo + areaTriangulo;

            if (areaTotal > mayorArea) {
                mayorArea = areaTotal;
                indiceBarra1 = i;
                indiceBarra2 = j;
            }
        }
    }

    cout << "Área mayor: " << mayorArea << endl;
    cout<< "Elementos: "<<elementos[indiceBarra1].barra<<" y "<<elementos[indiceBarra2].barra<<endl;
}
*/
int main() {
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios
    vector<Elemento> elementos;
    
    for (int i = 0; i < 5; ++i) { // Crear 5 elementos con alturas aleatorias
        int alturaAleatoria = generarAlturaAleatoria();
        Elemento nuevoElemento = Elemento(alturaAleatoria);
        elementos.push_back(nuevoElemento);
    }

    // Imprimir las alturas de las barras de los elementos
    for (const Elemento& elemento : elementos) {
        cout << "Altura de la barra: " << elemento.barra << endl;
    }
    
    
    calcularArea(elementos);
    return 0;
}