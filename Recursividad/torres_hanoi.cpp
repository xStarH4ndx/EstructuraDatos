/*
Burno Toro Elgueta
20864066-6
ICCI
-------------------------------------------
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

int hanoi(int,string,string,string);

int main()
{
    int elementos,movimiento;
    cout<<"Ingresa cantidad discos: ";
    cin>>elementos;
    movimiento= hanoi(elementos,"ORIGEN","AUX","DESTINO");
    cout<<"Numero de movimientos: "<<movimiento<<endl;
    return 0;
};

int hanoi(int n, string inicio, string aux, string destino) {
    int movimientos = 0;

    if (n == 1) {//Caso base (1 disco pasa directo)
        cout << "Mueve el disco " << n << " del " << inicio << " al " << destino << endl;
        movimientos++;
    } else {//Caso general (origen->Auxiliar; Auxiliar->Destino)
        movimientos += hanoi(n - 1, inicio, destino, aux); //Movimiento al destino
        cout << "Mueve el disco " << n << " del " << inicio << " al " << destino << endl;
        movimientos++;
        movimientos += hanoi(n - 1, aux, inicio, destino); //Movimiento del aux al destino
    }
    return movimientos;
}