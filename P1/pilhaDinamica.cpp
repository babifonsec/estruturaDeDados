#include    <iostream>
using namespace std;

class noh{
    friend class pilha;
    private:
        int dado;
        noh* prox;
    public:
        noh(int valor);
};

noh::noh(int valor){
    dado=valor;
    prox=nullptr;
}

class pilha{
    private:
        noh* topo;
    public:
        pilha();
        ~pilha();
        void empilha(int valor);
        int desempilha();
        bool vazia();
        int verTopo();
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

bool pilha::vazia() {
    return topo == nullptr;
}

void pilha::empilha(int valor){
    noh* novoNoh = new noh(valor); //ponteiro para um noh
    novoNoh->prox = topo; //o campo prox do noh apontado por novoNoh armazena o mesmo endereço que está armazenado na variável topo; traducao seria: "novo noh, seu proximo noh e o noh que atualmente e o topo
    topo = novoNoh;// "agora a bandeirinha do topo vai para o novo noh"
}

int pilha::desempilha(){
    if(vazia()){
        cout<<"pilha vazia"<<endl;
        return -1;
    }

    noh* temp = topo;     // guarda o endereco do topo atual
    int valor = temp->dado; // salva o valor do topo
    topo = topo->prox;    // atualiza topo para o proximo noh
    delete temp;          // libera a memoria do noh removido

    return valor;         // retorna o valor removido
}

int pilha::verTopo(){
    return topo->dado;
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

int main (){
    pilha pilha;
    
    pilha.empilha(10);
    pilha.empilha(20);
    pilha.empilha(30);
    
    pilha.imprime(); // 30 20 10
    cout << "topo: " << pilha.verTopo() << endl; // 30
    cout << "desempilha: " << pilha.desempilha() << endl;  // 30
    pilha.imprime(); // 20 10
    
    return 0;
}