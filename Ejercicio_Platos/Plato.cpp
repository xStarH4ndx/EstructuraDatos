#include "Plato.h"
Plato::Plato(int orden,int preferencia){
    this->orden=orden;
    this->preferencia=preferencia;
    this->prioridad=0;
}

int Plato::getOrden(){
    return this->orden;
}

int Plato::getPreferencia(){
    return this->preferencia;
}

int Plato::getPrioridad(){
    return this->prioridad;
}

void Plato::setPrioridad(int prioridad){
    this->prioridad=prioridad;
}