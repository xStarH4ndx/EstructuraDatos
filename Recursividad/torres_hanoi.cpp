/*
PROBLEMA DE RECURSIVIDAD - TORRES DE HANOI

Palo1       PALO2       PALO3
  1           |           |
  2           |           |
  3           |           |
  4           |           |

Palo1= origen
palo2= auxiliar
palo3= destino

reglas: mover de a una, la más chica siempre arriba

Paso 1: Definir el caso base (solución inmediata)
- caso base: si se tiene 1 solo disco, basta con desplazarlo al destino final


*/
#include <iostream>
using namespace std;

int hanoi(int,String,String,String);

int main()
{
    int elementos,movimiento;
    cout<<"Ingresa cantidad discos: ";
    cin>>elementos;
    movimiento= hanoi(elementos,'ORIGEN','AUX','DESTINO');
    cout<<"Numero de movimientos: "<<movimiento<<endl;
    return 0;
};

int hanoi(int n,String inicio,String aux,String destino){
    int movimientos=0;

    if(n==1){
        cout<<"Mueve el disco "<<n<<" del "<<inicio<<" al "<<destino<<endl;
        movimientos++;
    }else{
        hanoi(n-1,inicio,destino,aux);
        cout<<"Mueve el disco "<<n<<" del "<<inicio<<" al "<<destino;
        movimientos++;
        hanoi(n-1,aux,inicio,destino);
    }



    return movimientos;
}