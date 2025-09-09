#include <iostream>
using namespace std;

class noh {
    friend class pilha; 
    private:
        int dado;
        noh* prox;

    public:
        noh(int dado);
};

noh::noh(int valor) {
    dado = valor;
    prox = nullptr;
}

class pilha {
    private:
        noh* topo;
        int tamanho;

    public:
        pilha();
        ~pilha();
        bool vazia();
        void empilha(int valor);
        int desempilha();
        void exibir();
};

pilha::pilha(){
    topo = NULL;    
    tamanho = 0;
}

pilha::~pilha(){
    while (!vazia()) {
            desempilha();
        }
}

bool pilha::vazia(){
    return (tamanho==0);
}

void pilha::empilha(int valor){
    noh* novo = new noh(valor); 
    novo->prox = topo;     
    topo = novo;               
    tamanho++; 
}



void pilha::exibir() {
    noh* atual = topo;
    while (atual != nullptr) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}

int pilha::desempilha(){
    int valor = topo->dado;
    noh* temp = topo;         
    topo = topo->prox;   
    delete temp;               
    tamanho--;                
    return valor;              
}

int main() {
    pilha original;
    pilha aux;
    pilha resultado;

    original.empilha(8);
    original.empilha(2);
    original.empilha(9);
    original.empilha(1);
    original.exibir();

    while (!original.vazia()) {
        int temp = original.desempilha();

        while (!aux.vazia() && aux.topoValor() > temp) {
            original.empilha(aux.desempilha());
        }

        aux.empilha(temp);
    }

    while (!aux.vazia()) {
        resultado.empilha(aux.desempilha());
    }
 
    resultado.exibir();

    return 0;
}
