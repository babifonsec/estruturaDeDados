#include <iostream>

using namespace std;

class noh {
    friend class pilha; // permite que a classe pilha acesse os membros privados de noh
    private:
        int mValor;     // valor armazenado no no
        noh* mProximo;  // ponteiro para o proximo no na pilha
    public:
        noh(int valor);
};

noh::noh(int valor){
    mValor = valor;
    mProximo = NULL; // inicialmente nao aponta para nenhum 
}

class pilha {
    private:
        noh* mTopo;     // ponteiro para o topo da pilha
        unsigned mTamanho; // tamanho atual da pilha (unsigned e smpre positivo)
    
    public:
        pilha();
        ~pilha();
        unsigned tamanho();
        void empilha(int dado);
        int desempilha();
        bool vazia();     
        void limpaPilha();
};

pilha::pilha(){
    mTopo = NULL;    // topo aponta para nada
    mTamanho = 0;
}

pilha::~pilha(){
    limpaPilha();
}

void pilha::limpaPilha(){
    while (mTamanho > 0){
        desempilha();
    };
}

// retorna o tamanho atual da pilha
unsigned pilha::tamanho(){
    return mTamanho;
}

void pilha::empilha(int valor){
    noh* novo = new noh(valor); // cria um novo no
    novo->mProximo = mTopo;     // novo no aponta para o antigo topo
    mTopo = novo;               // topo agora e o novo no
    mTamanho++;                 // incrementa o tamanho
}

int pilha::desempilha(){
    int valor = mTopo->mValor; // guarda o valor do topo
    noh* temp = mTopo;         // guarda o endereco do topo atual
    mTopo = mTopo->mProximo;   // topo agora e o proximo elemento
    delete temp;               // libera a memoria do no removido
    mTamanho--;                // decrementa o tamanho
    return valor;              // retorna o valor removido
}

bool pilha::vazia(){
    return (mTamanho == 0);
}

int main (){
    pilha p1;
    int num;
    
    cin >> num;

    while (num >= 0) {
        p1.empilha(num);
        cin >> num;
    }

    cout << "tamanho: " << p1.tamanho() << endl;
    cout << "elementos: ";
    
    while (not p1.vazia()){
        cout << p1.desempilha() << " ";
    }
    
    cout << endl;
    return 0; 
}