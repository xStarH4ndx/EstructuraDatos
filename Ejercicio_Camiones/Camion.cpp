#include "Camion.h"
using namespace std;

Camion::Camion(int peso){
    this->peso=peso;
}
Camion::~Camion(){delete this;}

int Camion::getPeso(){
    return this->peso;
}

void Camion::setPeso(int peso){
    this->peso=peso;
}