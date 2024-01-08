#include <iostream>
#include <stack>
#include "Camion.h"
using namespace std;

int main(){
    //objetos dinamicos (punteros)
    Camion* c1= new Camion(100);
    Camion* c2= new Camion(13);
    Camion* c3= new Camion(25);
    Camion* c4= new Camion(20);

    stack<Camion*>pila;
    stack<Camion*>Aux1;
    stack<Camion*>Aux2;
    pila.push(c1);
    pila.push(c2);
    pila.push(c3);
    pila.push(c4);

    //ordena de mayor a menor
    while(!pila.empty()){
        if(Aux1.empty()){
            Aux1.push(pila.top());
            pila.pop();
        }else{
            if(pila.top().getPeso() < Aux1.top().getPeso()){
                Aux1.push(pila.top());
                pila.pop();
            }else{
                while(!Aux1.empty() && pila.top().getPeso() > Aux1.top().getPeso()){
                    Aux2.push(Aux1.top());
                    Aux1.pop();
                }
                Aux1.push(pila.top());
                pila.pop();
                while(!Aux2.empty()){
                    Aux1.push(Aux2.top());
                    Aux2.pop();
                }
            }
        }
    }
}