#include <iostream>
#include "Camion.h"
#include <stack>

using namespace std;

int main(){
    //objetos dinamicos (punteros)
    Camion* c1= new Camion(100);
    Camion* c2= new Camion(13);
    Camion* c3= new Camion(25);
    Camion* c4= new Camion(20);

    stack<Camion*> pila;//SE CREA LA PILA
    //ingresar "carga" a la pila
    pila.push(c1);
    pila.push(c2);
    pila.push(c3);
    pila.push(c4);

    //pilas auxiliares
    stack<Camion*> sAux1;
    stack<Camion*> sAux2;

    while(!pila.empty()){
        if(sAux1.empty()){
            sAux1.push(pila.top());
            pila.pop();
        }else{
            if((pila.top()->getPeso()) < (sAux1.top()->getPeso())){
                sAux1.push((pila.top()));
                pila.pop();
            }else{

                while (!sAux1.empty() && pila.top()->getPeso() > sAux1.top()->getPeso()) {
                    sAux2.push(sAux1.top());
                    sAux1.pop();
                }

                sAux1.push((pila.top()));
                pila.pop();
                while(!sAux2.empty()){
                    sAux1.push(sAux2.top());
                    sAux2.pop();
                } 
            }
        }
    }

    // Mostrar contenido de la pila original
    cout << "Contenido de la pila original:" << endl;
    while (!pila.empty()) {
        cout <<pila.top()->getPeso() << ", ";
        pila.pop();
    }
    cout<<endl;
    // Mostrar contenido de la pila ordenada
    cout << "\nContenido de la pila ordenada:" << endl;
    while (!sAux1.empty()) {
        cout <<sAux1.top()->getPeso() << ", ";
        sAux1.pop();
    }
    cout<<endl;
    return 0;
}