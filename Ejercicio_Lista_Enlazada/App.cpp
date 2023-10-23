#include <iostream>
#include "Lista.cpp"


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
        cout<<"Opción 1 insertar: "<<endl;
        cout<<"Opción 2 mostrar datos: "<<endl;
        cout<<"Opción 3 ordenar: "<<endl;
        cout<<"Opción 5 salir: "<<endl;
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