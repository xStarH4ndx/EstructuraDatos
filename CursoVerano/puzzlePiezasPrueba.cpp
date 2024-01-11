/*
PROBLEMA DE LA PRUEBA, EL DEL PUZZLE DE LAS PIESAS QUE TENÍAN QUE MOVERSE
*/

Nodo* buscarNodo(int _valor, slidingPuzzle* sp){
    Nodo* auxiliar;
    for(int i=0; i<sp ->filas; i++){
        auxiliar = sp -> cabeceraFilas[i];
        while(auxiliar != nullptr){
            if(auxiliar->valor == _valor){
                return auxiliar;
            }
            auxiliar = auxiliar->siguiente;
        }
    }
}
bool verificarMovimiento(Nodo* nodoCero, Nodo* nodoBuscado){
    int columnaNodoCero = nodoCero->columna;
    int filaNodoCero = nodoCero->fila;
    int columnaNodoBuscado = nodoBuscado->columna;
    int filaNodoBuscado = nodoBuscado->fila;

    //si la pieza buscada tiene la misma fila que la pieza 0, significa que puede estar adelante o atras.
    if(filaNodoBuscado == filaNodoCero){
        //Si está atras o adelante, se retorna true
        if(columnaNodoBuscado == columnaNodoCero+1 || columnaNodoBuscado == columnaNodoCero-1){
            return true;
        }
    }

    //Si la pieza buscada está en la misma columna que la pieza 0, significa que puede estar arriba o abajo del 0
    if(columnaNodoBuscado == columnaNodoCero){
        //
        if(filaNodoBuscado == filaNodoCero+1 || filaNodoBuscado == filaNodoCero-1){
            return true;
        }
    }
    return false;
}