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
#include <stack>
using namespace std;

int hanoi(int n,char origen,char auxiliar,char destino);

int main(){
    int elementos,movimiento;
    cout<<"Ingresa cantidad discos: ";
    cin>>elementos;
    movimiento= hanoi(elementos,"Origen","Aux","C");
    cout<<"Numero de movimientos: "<<movimiento<<endl;
};

int hanoi(int n,char a,char b,char c){
    int movimiento=0;

    if(elementos>0){
        hanoi(n-1,a,b,c);
        cout<<"se ha movido el disco "<<n<<" del "<<a<<" hasta la "<<c;
        movimiento++;
        hanoi(n-1,b,a,c)
    }
    return movimiento;
}