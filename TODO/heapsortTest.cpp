#include <iostream>
#include <vector>
using namespace std;


void maxheap(vector<int>&array,int n,int i){
    int raiz=i;
    int left= 2*i+1;
    int right= 2*i+2;

    if(left<n && array[left]>array[raiz]){
        raiz=left;
    }

    if(right<n && array[right]>array[raiz]){
        raiz=right;
    }

    if(raiz!=i){
        swap(array[i],array[raiz]);
        maxheap(array,n,raiz);
    }
}

void minheap(vector<int>&array,int n,int i){
    int raiz=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && array[left]<array[raiz]){
        raiz=left;
    }

    if(right<n && array[right]<array[raiz]){
        raiz=right;
    }

    if(raiz!=i){
        swap(array[i],array[raiz]);
        minheap(array,n,raiz);
    }
}

void heapsort(vector<int>&array){
    int n= array.size();

    for(int i= (n/2-1);i>=0;i--){
        minheap(array,n,i);
    }

    for(int j=(n-1);j>=0;j--){
        swap(array[0],array[j]);
        minheap(array,j,0);
    }
}

int main(){
    vector<int>array={4,2,7,23,1};

    heapsort(array);
    for(int a:array){
        cout<<a<<",";
    }
    return 0;    
}