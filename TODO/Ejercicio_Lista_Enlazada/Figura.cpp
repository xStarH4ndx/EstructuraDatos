#include <iostream>
using namespace std;

class Figura
{
    private:
        int numLados;
    public:
        Figura(int numLados)
        {
            this->numLados=numLados;
        }
        int getNumLados()
        {
            return numLados;
        }
        void setNumLados(int numLados)
        {
            this->numLados=numLados;
        }
};