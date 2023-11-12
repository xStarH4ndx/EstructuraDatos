class Node{
    private: 
        int dato;
        Node*next;
    public:
        Node(int dato);
        ~Node();
        Node* getNext();
        void setNext();
        
};


//PRIMERO INSERTAMOS EL ELEMENTO
void insertar(Node*&head, int dato){
    Node*nuevoNodo=new Node(dato);
    if(head==nullptr){
        head=nuevoNodo;
    }else{
        Node*aux=head;
        while(aux->getNext()!=nullptr){
            aux=aux->getNext();
        }
        aux->getNext()=nuevoNodo;
    }
}

//INSERTAR ELEMENTO AL INICIO DE LA LISTA
void insertarInicio(Node*&head,int dato){
    Node*nuevoNodo=new Node(dato);
    if(head==nullptr){
        head=nuevoNodo;
    }else{
        Node*aux=head;
        while(aux->getNext()!=nullptr){
            aux=aux->getNext();
        }
        nuevoNodo->getNext()=head;//ES LO MISMO QUE EL OTRO, SOLO SE LE AGREGA ESTA LINEA DE CODIGO
        head=nuevoNodo;//este pasa a ser primero, es decir, se agrega al inicio de la lista
    }
}






void insertar(Node*&head,int dato){
    Node*nuevoNodo= new Node(dato);
    if(head==nullptr){
        head=nuevoNodo;
    }else{
        Node*aux=head;
        while(aux->getNext()!=nullptr){
            aux=aux->getNext();
        }
        aux->setNext(nuevoNodo);
    }
}

void insertarInicio(Node*&head,int dato){
    Node* nuevoNodo= new Node(dato);
    if(head==nullptr){
        head=nuevoNodo;
    }else{
        Node*aux=head;
        while(aux->getNext()!=nullptr){
            aux= aux->getNext();
        }
        nuevoNodo->getNext()=head;
        head=nuevoNodo;
    }

}