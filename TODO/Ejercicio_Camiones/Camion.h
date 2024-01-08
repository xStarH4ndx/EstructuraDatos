#pragma once
#include <iostream>
using namespace std;
class Camion{
    private:
        int peso;
    public:
        Camion(int);
        ~Camion(); 
        int getPeso();
        void setPeso(int);
        string getId();
        void setId(string);
};