#pragma once
#include <iostream>

class Plato{
    private:
        int orden;
        int preferencia;
        int prioridad;
    public:
        Plato(int orden,int preferencia);
        int getOrden();
        int getPreferencia();
        int getPrioridad();
        void setPrioridad(int);
};
