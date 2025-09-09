#include <iostream>

using namespace std;
typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class pilhav {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;
    public:
        pilhav(int cap = 100);
        ~pilhav();
        void empilha(Dado valor);
        Dado desempilha();
        Dado espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

pilhav::pilhav(int cap) {
    capacidade = cap;
    dados = new Dado[capacidade];
    tamanho = 0;
    posTopo = -1; // pilha vazia
}

pilhav::~pilhav() {
    delete[] dados;
}

void pilhav::empilha(Dado valor){
    posTopo++;
    dados[posTopo] = valor;
    tamanho++;
}

Dado pilhav::desempilha(){
    Dado elem = dados[posTopo];
    posTopo--;
    tamanho--;
    return elem;
}

Dado pilhav::espia(){
    return dados[posTopo];
}

void pilhav::depura(){
    for(int i=0;i<=posTopo;i++){
        cout << dados[i];
        if (i < posTopo) {
            cout << " ";
        }
    }
    cout<<endl;
}

void pilhav::info(){
    cout<<tamanho<<" "<<posTopo<<endl;
}

int  main (){
    pilhav p(20);
    
    Dado valor;
    for (int i = 0; i < 5; i++) {
        cin >> valor;
        p.empilha(valor);
    }
    
    for (int i = 0; i < 3; i++) {
        cout << p.desempilha();
        if (i < 2) {
            cout << " ";
        }
    }
    cout << endl;
    
    for (int i = 0; i < 4; i++) {
        cin >> valor;
        p.empilha(valor);
    }
    
    for (int i = 0; i < 3; i++) {
        cout << p.desempilha();
        if (i < 2) {
            cout << " ";
        }
    }
    cout << endl;
    
    cout << p.espia() << endl;
    p.depura();
    p.info();
    return 0;
}