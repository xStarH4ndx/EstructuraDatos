#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Plato{
    private:
        int nOrden;
        int preferencia;
        int prioridad;
    public:
        Plato(int nOrden,int preferencia){
            this->nOrden=nOrden;
            this->preferencia=preferencia;
            this->prioridad=0;
        };
        int getOrden(){return this->nOrden;};
        int getPreferencia(){return this->preferencia;};
        int getPrioridad(){return this->prioridad;};
        void setPrioridad(int prioridad){this->prioridad=prioridad;};
};

int main(){
    queue<Plato*>cola;
    stack<Plato*>src;
    stack<Plato*>aux1;
    stack<Plato*>aux2;

    Plato*p1= new Plato(1,2);//6
    Plato*p2= new Plato(2,4);//8
    Plato*p3= new Plato(3,2);//2
    Plato*p4= new Plato(1,3);//9
    Plato*p5= new Plato(1,4);//12
    Plato*p6= new Plato(2,3);//6

    src.push(p1);
    src.push(p2);
    src.push(p3);
    src.push(p4);
    src.push(p5);
    src.push(p6);

    //primera vuelta, calcular prioridad
    while(cola.empty()){
        if(!src.empty()){
            int contCola=1;
            cola.push(src.top());
            src.pop();
            //tomamos orden por orden
            while(!src.empty()){
                if(src.top()->getOrden()==cola.front()->getOrden()){
                    cola.push(src.top());
                    src.pop();
                    contCola++;//cantidad de platos de esa orden
                }else{
                    aux1.push(src.top());
                    src.pop();
                }
            }
            //mover las prioridades calculadas al aux2
            while(!cola.empty()){
                int prioridad= ((cola.front()->getPreferencia())*contCola);
                cola.front()->setPrioridad(prioridad);//Calculo de prioridades (preferencia*cantidad de esa orden)
                aux2.push(cola.front());
                cola.pop();
            }
            //mover el resto de los platos al src (bdd)
            while(!aux1.empty()){
                src.push(aux1.top());
                aux1.pop();
            }
            //esto me dejará aux2 como la nueva bdd

        }else{
            while(!aux2.empty()){
                src.push(aux2.top());
                aux2.pop();
            }
            break;
        }
    }
    //SEGUNDA VUELTA, ORDENAR SEGUN PRIORIDAD EN LA COLA
    while(!src.empty()){
        if(aux1.empty()){
            aux1.push(src.top());
            src.pop();
        }else{
            if(src.top()->getPrioridad()>aux1.top()->getPrioridad()){
                aux1.push(src.top());
                src.pop();
            }else{
                while(!aux1.empty() && src.top()->getPrioridad()<aux1.top()->getPrioridad()){
                    aux2.push(aux1.top());
                    aux1.pop();
                }
                aux1.push(src.top());
                src.pop();
                while(!aux2.empty()){
                    aux1.push(aux2.top());
                    aux2.pop();
                }
            }
        }
    }

    while(!aux1.empty()){
        cola.push(aux1.top());
        aux1.pop();
    }

    while(!cola.empty()){
        cout<<"Plato: "<<cola.front()->getOrden()<<" Prioridad: "<<cola.front()->getPrioridad()<<endl;
        cola.pop();
    }
    return 0;
}