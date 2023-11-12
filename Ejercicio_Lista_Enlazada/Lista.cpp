#include <iostream>
#include "Nodo.cpp"

class Lista{
    private:
        Nodo* first,*last;
    public:
        Lista()
        {
            first = nullptr;
            last = nullptr;
        }
        void insertar(int lados){
            Nodo* nuevo = new Nodo(lados);
            if(first == nullptr)
            {
                first = nuevo;
                last = nuevo;
                first->setNext(last);
                last->setNext(first);
                return;
            }
            else
            {
                nuevo->setNext(first);
                last->setNext(nuevo);
                last = nuevo;
                return;
            }
        }
        void insertar2(int lados){
            Nodo*nuevo = new Nodo(lados);
            if(first==nullptr)
            {
                first=nuevo;
                last=nuevo;
                first->setNext(last);
                last->setNext(first);
            }
            else
            {
                if(nuevo->getFigura()->getNumLados()<first->getFigura()->getNumLados())
                {
                    nuevo->setNext(first);
                    last->setNext(nuevo);
                    first=nuevo;
                }
                else
                {
                    Nodo* actual = first;
                    Nodo* anterior = actual;
                    while(lados>=actual->getFigura()->getNumLados() && actual->getNext()!=first)
                    {
                        anterior = actual;
                        actual = actual->getNext();
                    }
                    if(lados>=actual->getFigura()->getNumLados())
                    {
                        actual->setNext(nuevo);
                        nuevo->setNext(first);
                        last=nuevo;
                    }
                    else
                    {
                        anterior->setNext(nuevo);
                        nuevo->setNext(actual);
                    }
                }
            }
        }
        void mostrarDatos()
        {
            Nodo* actual = first;
            if(actual == nullptr)
            {
                cout<<"No hay datos que mostrar"<<endl;
                return;
            }
            do
            {
                cout<<actual->getFigura()->getNumLados()<<endl;
                actual=actual->getNext();
            } while (actual!=first);
            
        }
        void ordenarDatos()
        {
            Nodo* actual = first;
            Nodo* siguiente;
            int num;
            do{
                siguiente= actual->getNext();

                do{
                    if(actual->getFigura()->getNumLados()>siguiente->getFigura()->getNumLados())
                    {
                        int num =actual->getFigura()->getNumLados();
                        actual->getFigura()->setNumLados(siguiente->getFigura()->getNumLados());
                        siguiente->getFigura()->setNumLados(num);   
                    }
                    siguiente = siguiente->getNext();
                } while (siguiente!=first);
                actual = actual->getNext();
                siguiente = actual->getNext();//esta linea esta demas?
                
            } while (actual!=first);
            
            if(first->getFigura()->getNumLados()>last->getFigura()->getNumLados())
            {
                int num =first->getFigura()->getNumLados();
                first->getFigura()->setNumLados(last->getFigura()->getNumLados());
                last->getFigura()->setNumLados(num);   
            }
            
        }
};