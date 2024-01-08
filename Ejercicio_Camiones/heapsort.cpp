#include <iostream>
#include <vector>
using namespace std;

void maxHeap(vector<int>&array,int n,int i){
    int raiz=i;
    int left=2*i+1;
    int right= 2*i+2;
    
    //Mientras el hijo izquierdo no sea un nodo terminal
    //Y si el hijo izquierdo es mayor a la raiz, se cambia igualando posicion
    if(left<n && array[left]<array[raiz]){
        raiz=left;
    }
    //Si el hijo derecho es mayor a la raiz, se cambia igualando posicion
    if(right<n && array[right]<array[raiz]){
        raiz=right;
    }
    
    //Si la raiz(posicion) es distinto a la posicion inicial
    //significa que se cambiaron, entonces cambiamos los elementos.
    if(raiz!=i){
        swap(array[i],array[raiz]);
        maxHeap(array,n,raiz);
    }
}

void heapSort(vector<int>&array){
    int n= array.size();
    
    //Construimos el maxHeap
    for(int i= n/2 -1;i>=0;i--){
        maxHeap(array,n,i);
    }
    
    for(int i=(n-1);i>=0;i--){
        swap(array[0],array[i]);//mover el elemento de la raiz al final
        maxHeap(array,i,0);//volvemos a hacer el maxHeap
    }
}

int main()
{
    vector<int>array={4,2,58,29,63};
    cout<<"Array original: ";
    for(int i:array){
        cout<<i<<",";
    }
    cout<<endl;
    
    heapSort(array);
    
    cout<<"Array ordenado con heapSort: ";
    for(int i:array){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}