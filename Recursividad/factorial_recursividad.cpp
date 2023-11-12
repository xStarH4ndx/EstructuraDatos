/*
Recursividad: aquella función que se llama a ella misma
Posee 2 cosas:

- Caso base: La solución
- Caso General: para llegar a la solución

EJEMPLO: FACTORIAL
si n=0, el factorial es 1
si n>0, se calcula.
*/

#include <iostream>
using namespace std;

//se declaran las funciones
int factorial(int);

int main(){

};

int factorial(int n){
    //caso base
    if(n==0){
        n=1;
    }else{//caso general
        n=n*factorial(n-1);//es recursiva porque se llama a ella misma
    }
    return n;
}

