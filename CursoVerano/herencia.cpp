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
    Poligono* c2= new Cuadrado(5);
    c2->~Poligono();
    cout<<"-------"<<endl;
    Poligono p1(4);
    return 0;
}
