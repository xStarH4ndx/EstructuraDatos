#include <iostream>
#include "Lista.cpp"

using namespace std;
int main()
{
    Lista* lista = new Lista();
    lista->insertar(5);
    lista->insertar(3);
    lista->insertar(7);
    lista->insertar(9);
    int option;
    do
    {
        int lados;
        cout<<"Ingrese una opcion: "<<endl;
        cout<<"Opcion 1 insertar: "<<endl;
        cout<<"Opcion 2 mostrar datos: "<<endl;
        cout<<"Opcion 3 ordenar: "<<endl;
        cout<<"Opcion 5 salir: "<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Ingrese los lados de la figura: "<<endl;cin>>lados;
            lista->insertar2(lados);
            break;
        case 2:
            cout<<"Los datos son:"<<endl;
            lista->mostrarDatos();
            break;
        case 3:
            lista->ordenarDatos();
            break;
        case 5:
            cout<<"Termino el programa"<<endl;
            break;
        default:
            cout<<"Ingresa un valor valido!!"<<endl;
            break;
        }
    } while (option != 5);
    
    
    
    return 0;
}