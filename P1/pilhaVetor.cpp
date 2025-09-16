#include    <iostream>
using namespace std;

class Pilha{
    private:
        int *vetor;
        int capacidade;
        int topo;

    public:
        Pilha(int cap);
        ~Pilha();
        bool vazia();
        void empilha(int valor);
        int desempilha();
        int verTopo();
        void imprimir();
        bool cheia();
};

//construtor
Pilha::Pilha(int cap=10){
    capacidade=cap;
    vetor = new int[capacidade];
    topo=-1; //pilha vazia
}

//destrutor
Pilha::~Pilha(){
    delete[] vetor;
}

//verifica se a pilha esta vazia
bool Pilha::vazia(){
    return topo==-1;
}

//verifica se esta cheia
bool Pilha::cheia(){
    return topo==capacidade-1;
}

void Pilha::empilha(int valor){

    if(cheia()){
        cout<<"Pilha cheia"<<endl;
        return;
    }

    vetor[++topo]=valor;
}

int Pilha::desempilha(){
    if(vazia()){
        cout<<"Pilha vazia"<<endl;
    }
    return vetor[topo--];
}

int Pilha::verTopo(){
     if(vazia()){
        cout<<"Pilha vazia"<<endl;
    }
    return vetor[topo];
}

void Pilha::imprimir(){
    if(vazia()){
        cout<<"Pilha vazia"<<endl;
    }

    for(int i=topo; i>=0;i--){
        cout<<vetor[i]<<" ";
    }
    cout<<endl;
}

int main(){

    Pilha pilha(5);

    pilha.empilha(1);
    pilha.empilha(9);
    pilha.empilha(34);

    pilha.imprimir();
    cout<<"topo: "<<pilha.verTopo()<<endl;
    cout<<"desempilha: "<<pilha.desempilha()<<endl;
    pilha.imprimir();


    return 0;
}





