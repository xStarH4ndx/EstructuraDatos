#pragma once
#include <iostream>
#include "Figura.cpp"

class Nodo
{
    private:
        Figura* figura;
        Nodo* next;
    public:
        Nodo(int numLados)
        {
            figura = new Figura(numLados);
            next = nullptr;
        }
        Figura* getFigura()
        {
            return figura;
        }
        Nodo* getNext()
        {
            return next;
        }
        void setNext(Nodo* nodo)
        {
            next = nodo;
        }
        
};