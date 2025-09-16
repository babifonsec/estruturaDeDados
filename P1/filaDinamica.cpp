#include <iostream>
using namespace std;

class noh {
    friend class fila;

    private:
        int dado;
        noh* prox;
    public:
        noh(int valor) : dado(valor), prox(nullptr) {}
};

class fila{
    private:
        noh* inicio;
        noh* fim;
        int tam;
    public:
        fila();
        ~fila();
        void enfileira(int valor);
        int desenfileira();
        bool vazia();
        int frente();
        int getTamanho();
        void imprime();
};

fila::fila(): inicio(nullptr), fim(nullptr), tam(0){}; //construtor

fila::~fila(){
    while(!vazia()){
        desenfileira();
    }
}

bool fila::vazia(){
    return inicio==nullptr;
}

void fila::enfileira(int valor){

    noh* novoNoh = new noh(valor);
    if(vazia()){ //primeiro elemento da fila
        inicio=fim=novoNoh; //inicio e fim apontam para o novo noh, esse noh aponta para null
    } else { //add apos o ultimo elemento
        fim->prox = novoNoh; 
        fim =novoNoh; //att fim para o novo noh
    }
    tam++;
}

int fila::desenfileira(){
    if(vazia()){
        cout<<"vazia"<<endl;
        return -1;
    }

    noh* temp =inicio; //guarda o endereco do noh que sera removido
    int valor = temp->dado; //guarda o valor do noh que sera removido
    inicio = inicio->prox; //avanca o inicio para o proximo noh
    delete temp;
    tam--;

    // se ficou vazia, atualiza fim tb
    if (inicio == nullptr) {
        fim = nullptr;
    }
    
    return valor;
}

int fila::frente(){
    if(vazia()){
        cout<<"vazia"<<endl;
        return -1;
    }
    return inicio->dado;
}

int fila::getTamanho(){
    return tam;
}

void fila::imprime(){
    if(vazia()){
        cout<<"vazia"<<endl;
        return;
    }
    noh* atual = inicio;
    while (atual != nullptr) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    cout << endl;
}

int main(){
    fila fila;
    
    fila.enfileira(10);
    fila.enfileira(20);
    fila.enfileira(30);
    
    fila.imprime(); // 10 20 30
    
    cout << "frente: " << fila.frente() << endl; // 10
    cout << "tamanho: " << fila.getTamanho() << endl; // 3
    
    cout << "desenfileira: " << fila.desenfileira() << endl; // 10
    fila.imprime(); // 20 30
    
    cout << "nova frente: " << fila.frente() << endl; // 20
    cout << "novo tamanho: " << fila.getTamanho() << endl; // 2
    
    return 0;
}

