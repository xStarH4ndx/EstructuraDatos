#include <iostream>
#include <stack>
using namespace std;


double calcularPromedio(Nodo*head, string nombre, string ramo){
    if(head==null){return 0.0;}//no hay alumnos
    Nodo* aux=head;
    Nodo* alumno;
    //buscamos el alumno (lista circular)
    do{
        if(aux->getNombre()==nombre){alumno=aux;}
        aux=aux->sig;
    }while(aux!=head);
    //una vez encontrado el alumno
    if(alumno==null){return 0.0}//no existe
    NodoR* aRamo;
    NodoR* auxR;
    aRamo= alumno->ptr;//puntero a los ramos
    //buscamos el ramo (lista simple)
    if(aRamo==null){return 0.0}//no tiene ramos
    do{
        if(aRamo->getRamo()==ramo){auxR=aRamo}
        aRamo= aRamo->sig;
    }while(aRamo!=null);
    if(auxR==null){return 0.0}//ramo no existe
    NodoN*aNota;
    aNota= auxR->ptr;//puntero a las notas y peso
    if(aNota==null){return 0.0}//no tiene notas
    double promedio=0.0;
    do{
        promedio= promedio + ((aNota->getNota)*(aNota->getPeso));
        aNota= aNota->sig;
    }while(aNota!=null);
    return promedio;
}