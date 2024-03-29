#include <iostream>
#define PALABRADELDIA "using"
using namespace std;

class Nodo{
    public:
        char caracter;
        int columna;
        Nodo* next;
        Nodo(char x,int col,Nodo*ptr){
            this->caracter=x;
            this->columna=col;
            this->next=ptr;
        };
};

/*
pasarALista es una funcion que me transforma un string a una lista enlazada.
*/
Nodo* pasarALista(string palabra){
    Nodo*head= new Nodo(palabra[0],1,nullptr);
    Nodo*aux=head;
    int i=1;
    while(i<6){
        Nodo* newNodo= new Nodo(palabra[i],(i+1),nullptr);
        aux->next= newNodo;
        aux=newNodo;
        i++;
    }
    return head;
};

/*
verificarPalabra es una funcion que me retorna un booleano, esta función tiene 3 auxiliares
aux1 corresponde a la palabra del usuario
aux2 corresponde a la palabra del día
Estos dos auxiliares siempre irán a la par

aux3 corresponde a la palabra del día, esta se tomará desde el inicio de la palabra todo el tiempo,
sirve para comprobar si la letra donde "estoy parado" existe o no.
*/
bool verificarPalabra(string palabra){
    Nodo*head1= pasarALista(palabra);
    Nodo*head2= pasarALista(PALABRADELDIA);
    Nodo*aux1=head1;//palabra ingresada
    Nodo*aux2=head2;//palabra del dia
    Nodo*aux3=head2;
    int acertadas=0;
    
    do{
        if((aux1->caracter==aux2->caracter)){
            acertadas++;
            cout<<aux1->caracter<<" - correcto"<<endl;
        }else if(aux1->caracter!=aux2->caracter){
            int cantLetras=0;
            do{
                if((aux1->caracter==aux3->caracter)){
                    cout<<aux1->caracter<<"- Existe"<<endl;
                    break;
                }else{
                    cantLetras++;
                }
                if(cantLetras==5){
                    cout<<aux1->caracter<<" - incorrecto"<<endl;
                }
                aux3=aux3->next;
            }while(aux3->next!=nullptr);
            aux3=head2;
        }
        aux1=aux1->next;
        aux2=aux2->next;
    }while(aux2->next!=nullptr);
    
    if(acertadas==5){
        return true;
    }else{
        return false;
    }
};

int main(){
    int intentos=1;
    while(intentos!=6){
        cout<<"--Intento número "<<intentos<<"--"<<endl;
        string word;
        cout<<"ingresar palabra: ";
        cin>>word;
        while(word.size()!=5){
            cout<<"Palabra de 5 letras"<<endl;
            cout<<"ingresar palabra: ";
            cin>>word;
        }
        if(verificarPalabra(word)){
            cout<<"--Palabra encontrada--"<<endl;
            break;
        }else{
            intentos++;
            if(intentos<6){
                cout<<"--Prueba otra vez--"<<endl;
            }else{
                cout<<"--GAME OVER--"<<endl;
            }
        }
    }
    return 0;
}
