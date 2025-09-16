#include <iostream>
using namespace std;

class noh{
    friend class pilha;
    private:
        int dado;
        noh* prox;
    public:
        noh(int valor): dado(valor),prox(nullptr){};
};

class pilha{
    private:
        noh* topo;
    public:
        pilha();
        ~pilha();
        void empilha(int valor);
        int desempilha();
        void ordena();
        bool vazia();
        void imprime();
};

pilha::pilha(){
    topo=nullptr;
}

pilha::~pilha(){
    while(!vazia()){
        desempilha();
    }
}

void pilha::empilha(int valor){
    noh* novoNoh = new noh(valor);
    novoNoh->prox = topo;
    topo=novoNoh;
}

int pilha::desempilha(){
    noh* temp = topo;
    int valor = temp->dado;
    topo = topo->prox;
    delete temp;
    return valor;
}

bool pilha::vazia(){
    return topo==nullptr;
}

void pilha::ordena(){
    if (vazia()) {
        return;
    } 

    pilha aux;

    while (!vazia()) {
        int elementoAtual = desempilha();
        while (!aux.vazia() && aux.topo->dado > elementoAtual) {
            empilha(aux.desempilha());
        }
        aux.empilha(elementoAtual);
    }

     while (!aux.vazia()) {
        empilha(aux.desempilha());
    }
}
void pilha::imprime(){
    if(vazia()){
        cout<<"pilha vazia!"<<endl;
        return;
    }

     noh* atual = topo;
        while (atual != nullptr) {
            cout << atual->dado << " "; 
            atual = atual->prox;
        }   
        cout << endl;
}

int main() {
    pilha p;
    int n, valor;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> valor;
        p.empilha(valor);
    }
    
    p.ordena();
    p.imprime();
    cout << endl;
    
    return 0;
}




