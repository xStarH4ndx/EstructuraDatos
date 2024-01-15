#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
bool calculo(stack<char>computo){
    while(!computo){
        if(computo.top()!='a' || computo.top()!='b'){
            int
        }
    }
}

bool resolver2(string r){
    stack<char>pila;
    stack<char>computo;
    
    for(int i=0;i<r.size();i++){
        if(!pila.empty()){
            if(pila.top()=='{' && r[i]=='}'){
                pila.pop();
            }else if(pila.top()=='[' && r[i]==']'){
                pila.pop();
            }else if(pila.top()=='(' && r[i]==')'){
                pila.pop();
            }else{
                if(r[i]!='{' || r[i]!='}' || r[i]!='(' || r[i]!=')' || r[i]!='[' || r[i]!=']'){
                    computo.push(r[i]);
                }
                pila.push(r[i]);
            }
            
            
        }else{
            pila.push(r[i]);
        }
    }
    
    if(pila.empty()){
        return true;
    }else{
        return false;
    }
}
*/

bool resolver(string r){
    stack<char>pila;
    
    for(int i=0;i<r.size();i++){
        if(!pila.empty()){
            if(pila.top()=='{' && r[i]=='}'){
                pila.pop();
            }else if(pila.top()=='[' && r[i]==']'){
                pila.pop();
            }else if(pila.top()=='(' && r[i]==')'){
                pila.pop();
            }else{
                pila.push(r[i]);
            }
        }else{
            pila.push(r[i]);
        }
    }
    
    if(pila.empty()){
        return true;
    }else{
        return false;
    }
}

int main()
{
    //string r="(a+b)*[(1+b)*a]";
    string r= "";
    if(resolver(r)){
        cout<<"Se resuelve";
    }else{
        cout<<"No se resuelve";
    }
    return 0;
}