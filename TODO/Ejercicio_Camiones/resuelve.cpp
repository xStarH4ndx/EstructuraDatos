#include <iostream>
#include "Camion.h"
#include <stack>
using namespace std;

int main(){
    stack<Camion*>pila;
    stack<Camion*>aux1;
    stack<Camion*>aux2;

    Camion* c1= new Camion(100);
    Camion* c2= new Camion(3);
    Camion* c3= new Camion(14);
    Camion* c4= new Camion(2);
    Camion* c5= new Camion(1);

    pila.push(c1);
    pila.push(c2);
    pila.push(c3);
    pila.push(c4);
    pila.push(c5);

    while(!pila.empty()){
        if(aux1.empty()){
            aux1.push(pila.top());
            pila.pop();
        }else{
            if(pila.top().getPeso()<aux1.top().getPeso()){
                aux1.push(pila.top());
                pila.pop();
            }else{
                while(!aux1.empty() && pila.top().getPeso()>aux1.top().getPeso()){
                    aux2.push(aux1.top());
                    aux1.pop();
                }
                aux1.push(pila.top());
                pila.pop();
                while(!aux2.empty()){
                    aux1.push(aux2.top());
                    aux2.pop();
                }
            }
        }
    }

    return 0;
}