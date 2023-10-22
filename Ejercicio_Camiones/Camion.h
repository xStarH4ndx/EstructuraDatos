#pragma once
#include <iostream>

class Camion{
    private:
        int peso;
        string id;
    public:
        Camion(int,string);
        ~Camion(); 
        int getPeso();
        void setPeso(int);
        string getId();
        void setId(string);
};