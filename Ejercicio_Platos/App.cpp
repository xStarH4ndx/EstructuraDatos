#include <iostream>
#include <stack>
#include <queue>
#include "Plato.h"
using namespace std;

//funcion
stack<Plato> calcularPrioridad(stack<Plato> src){
    stack<Plato> aux;
    int cantP1=0;
    int cantP2=0;

    //ESTO CALCULA LA CANTIDAD DE CADA ORDEN (TIPO ORDEN: 1 Y 2)
    while(!src.empty()){
        if(src.top().getOrden()==1){
            aux.push(src.top());
            src.pop();
            cantP1++;//platos de tipo 1
        }else if(src.top().getOrden()==2){
            aux.push(src.top());
            src.pop();
            cantP2++;//platos de tipo 2
        }
    }

    while(!aux.empty()){
        if(aux.top().getOrden()==1){
            int prioridad= cantP1*(aux.top().getPreferencia());
            aux.top().setPrioridad(prioridad);
            src.push(aux.top());
            aux.pop();
        }else if(aux.top().getOrden()==2){
            int prioridad= cantP2*(aux.top().getPreferencia());
            aux.top().setPrioridad(prioridad);
            src.push(aux.top());
            aux.pop();
        }
    }
    return src;//devolvemos todo a la pila, pero ya tenemos la prioridad de cada plato
    //calculada.
}

int main(){
    //Pila principal y auxiliares (por tipos)
    stack<Plato> src;
    stack<Plato> s1;
    stack<Plato> s2;
    //esto es la cola de salida (el último es el primero que sale)
    queue<Plato> salida;

    src.push(Plato(1,1));
    src.push(Plato(2,2));
    src.push(Plato(1,3));

    s1.push(src.top());//movemos el primer plato al aux1
    src.pop();
    //EMPEZAMOS A ORDENAR LA PILA AUXILIAR
    while(!src.empty()){
        if(src.top().getPrioridad() < s1.top().getPrioridad()){//PILA ORDENAR DE MENOR A MAYOR
            s1.push(src.top());
            src.pop();
        }else{

            while(!s1.empty() && src.top().getPrioridad() > s1.top().getPrioridad()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(src.top());
            src.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

    }

    //Ahora que están ordenados, los tiramos a la salida
    while(!s1.empty()){
        salida.push(s1.top());
        s1.pop();
    }

    //Mostramos por pantalla para corroborar
    cout<<"Cola ordenada:"<<endl;
    while(!salida.empty()){
        cout<<salida.front().getPrioridad()<<" - ";
        salida.pop();
    }
    return 0;
}