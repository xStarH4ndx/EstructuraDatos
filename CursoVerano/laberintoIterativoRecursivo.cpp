#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int filas=5;
const int columnas=5;

bool movimientoValido(int fila,int columna){
    if(fila>=0 && fila<filas && columna>=0 && columna<columnas){
        return true;
    }
    return false;
}

bool resolverLaberinto(int laberinto[filas][columnas]){
    int filaInicial=0,columnaInicial=0,filaFinal=filas-1,columnaFinal=columnas-1;
    queue<pair<int,int>>q;
    q.push(make_pair(filaInicial,columnaInicial));
    laberinto[filaInicial][columnaInicial]=2;
    int cambioFila[]={1,0,-1,0};
    int cambioColumna[]={0,1,0,-1};
    while(!q.empty()){
        int fila=q.front().first;
        int columna= q.front().second;
        q.pop();
        if(fila==filaFinal && columna==columnaFinal){
            return true;
        }
        for(int i=0;i<4;i++){
            int nuevaFila= fila+cambioFila[i];
            int nuevaColumna=columna + cambioColumna[i];
            if(movimientoValido(nuevaFila,nuevaColumna) && laberinto[nuevaFila][nuevaColumna]==0){
                q.push(make_pair(nuevaFila,nuevaColumna));
                laberinto[nuevaFila][nuevaColumna]=2;
            }
        }
    }
    return false;
}


int main() {
    // Definir el laberinto como una matriz 5x5
    int laberinto1[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    
    int laberinto2[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0}
    };
    
    if(resolverLaberinto(laberinto2)){
        cout<<"Si se puede resolver"<<endl;
    }else{
        cout<<"No se puede"<<endl;
    }
    return 0;
}
