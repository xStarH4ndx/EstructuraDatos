#include "Camion.h"
using namespace std;

Camion::Camion(int peso,string id){
    this->peso=peso;
    this->id=id;
}
Camion::~Camion(){delete this;}

int Camion::getPeso(){
    return this->peso;
}

void Camion::setPeso(int peso){
    this->peso=peso;
}

string Camion::getId(){
    return this->id;
}

void Camion::setId(string id){
    this->id=id;
}