#include <iostream>
using namespace std;


class A{
    public:
        int a1;
        A(int _a1){a1=_a1;};
        virtual void imprimir(){cout<<a1<<endl;};
        virtual void imprimir(int b1){cout<<a1<<"|"<<b1<<endl;};
};

class B:public A{
    public:
        int b1;
        B(int _b1,int _a1):A(_a1){b1=_b1;};
        virtual void imprimir(){cout<<a1<<"|"<<b1<<endl;};
        virtual void imprimir(int c1){cout<<a1<<"|"<<b1<<"|"<<c1<<endl;};
};

int main(){
    A a1(5);
    B b1(6,7);
    a1.imprimir();
    a1.imprimir(3);
    b1.imprimir();
    b1.imprimir(8);
    
    return 0;
}