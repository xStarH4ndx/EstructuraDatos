#include <iostream>
#include "Camion.h"
#include <stack>

using namespace std;

int main(){
    //objetos dinamicos (punteros)
    Camion* c1= new Camion(100,"1");
    Camion* c2= new Camion(13,"2");
    Camion* c3= new Camion(3,"3");
    Camion* c4= new Camion(7,"4");

    stack<Camion*> pila;//SE CREA LA PILA
    //ingresar "carga" a la pila
    pila.push(c1);
    pila.push(c2);
    pila.push(c3);
    pila.push(c4);

    //pilas auxiliares
    stack<Camion*> sAux1;
    stack<Camion*> sAux2;

    if(pila.empty()){
        cout<<"La pila está vacía"<<endl;
    }

}