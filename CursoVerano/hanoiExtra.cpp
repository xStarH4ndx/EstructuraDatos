#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

void hanoiIterativo(stack<int>& origen, stack<int>& aux, stack<int>& destino) {
    int cantMovimientos= (pow(2,origen.size()))-1;

    if(origen.size()%2==0) {
        swap(aux, destino);
    }

    for(int i=1;i<=cantMovimientos;i++) {
        if (i%3==1) { // origen -> auxiliar
            if(!origen.empty() && (aux.empty() || origen.top()<aux.top())) {
                aux.push(origen.top());
                origen.pop();
                cout<<"Mover de origen a aux"<<endl;
            }else{ // auxiliar -> origen
                origen.push(aux.top());
                aux.pop();
                cout<<"Mover de aux a origen"<<endl;
            }
        }else if(i%3==2){ // origen -> destino
            if (!origen.empty() && (destino.empty() || origen.top()<destino.top())) {
                destino.push(origen.top());
                origen.pop();
                cout<<"Mover de origen a destino"<<endl;
            }else{ // destino -> origen
                origen.push(destino.top());
                destino.pop();
                cout<<"Mover de destino a origen"<<endl;
            }
        }else{ // auxiliar -> destino
            if(!aux.empty() && (destino.empty() || aux.top()<destino.top())) {
                destino.push(aux.top());
                aux.pop();
                cout<<"Mover de aux a destino"<<endl;
            }else{ // destino -> auxiliar
                aux.push(destino.top());
                destino.pop();
                cout<<"Mover de destino a aux"<<endl;
            }
        }
    }
}

void imprimirPila(stack<int>&pila) {
    while(!pila.empty()) {
        cout<<pila.top()<<" ";
        pila.pop();
    }
    cout << endl;
}

void hanoi(int cont,string origen,string aux,string destino){
    if(cont==1){
        cout<<"La pieza "<<cont<<" se mueve del "<<origen<<" al "<<destino<<endl;
    }else{
        hanoi(cont-1,origen,destino,aux);
        cout<<"La pieza "<<cont<<" se mueve del "<<origen<<" al "<<destino<<endl;
        hanoi(cont-1,aux,origen,destino);
    }
}

int main(){
    //hanoi(3,"Origen","Aux","Destino");//recursivo
    stack<int>origen;
    stack<int>aux;
    stack<int>destino;
    origen.push(3);
    origen.push(2);
    origen.push(1);
    hanoiIterativo(origen,aux,destino);//iterativo
    
    cout<<"pila Origen"<<endl;
    imprimirPila(origen);
    cout<<"pila Aux"<<endl;
    imprimirPila(aux);
    cout<<"pila Destino"<<endl;
    imprimirPila(destino);
    return 0;
}