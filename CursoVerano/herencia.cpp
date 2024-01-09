#include <iostream>
using namespace std;

class Poligono {
public:
    int numLados;
    virtual void CalcularArea()=0;
    virtual void CalcularPerimetro()=0;
    Poligono(int numLados) : numLados(numLados) {};
    virtual ~Poligono() {cout<<"Destruyendo Poligono"<<endl;};
};

class Triangulo : public Poligono {
public:
    void CalcularArea() override {cout<<"area Triangulo"<<endl; };
    void CalcularPerimetro() override {cout<<"perimetro Triangulo"<<endl;};
    Triangulo(int numLados) : Poligono(numLados) {};
    ~Triangulo() {cout<<"Destruyendo Triangulo"<<endl;};
};

class Cuadrado : public Poligono {
public:
    void CalcularArea() override {cout<<"valor: area Cuadrado"<<endl;};
    void CalcularPerimetro() override {cout<<"valor: perimetro Cuadrado"<<endl;};
    Cuadrado(int numLados) : Poligono(numLados) {};
    ~Cuadrado() {cout<<"Destruyendo Cuadrado"<<endl;};
};

int main() {
    Cuadrado c1(5);
    Triangulo t1(3);
    Cuadrado* c2= new Cuadrado(4);
    Poligono* t2= new Triangulo(4);
    cout<<"----------------"<<endl;
    c2->CalcularArea();
    t2->CalcularPerimetro();
    cout<<"----------------"<<endl;
    return 0;
}
