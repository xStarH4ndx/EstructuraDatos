#include <iostream>
using namespace std;

//ESTO ES SOLO PARA RUTEAR, NO SE EJECUTA
int main()
{
    int m[3][4];
    int*h= &m[0][0];

    for (int i = 0; i <= 3; i++){
        for (int j = 0; j <= 4; j++){
            if ((i % 2) && (j % 2)){
                *(h + i)= i + j;
            }
            if (!(i % 2) && (j % 2)){
                *(h + j)= i + j;
            }else{
                *(h+ (i * j))= *h + (i * j);
            }
        }
    }
    
    for(int i=0;i<5;i++){
        for(int j=0;j<10;j++){
            cout<<m[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}

/*
RESULTADO:

0, 10, 2, 12, 4, 5, 6, 7, 8, 9, 
10, 0, 12, 0, 14, 15, 16, 0, 18, 0, 
20, 21, 0, 0, 24, 0, 0, 27, 28, 0, 
0, 0, 32, 0, 0, 0, 36, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0


PARA INSTANCIAR UN VECTOR DE PUNTEROS, SE HACE ASÍ
int* listaPunteros[5]
*/