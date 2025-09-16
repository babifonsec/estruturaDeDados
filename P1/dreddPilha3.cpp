#include <iostream>
#include <cstring>
using namespace std;

class Noh {
    friend class Pilha;
private:
    char caractere;
    int posicao;
    Noh* proximo;
public:
    Noh(char c, int pos) : caractere(c), posicao(pos), proximo(nullptr) {}
};

class Pilha {
private:
    Noh* topo;
public:
    Pilha();
    ~Pilha();
    void empilha(char c, int pos);
    void desempilha();
    bool vazia();
    int getPosicaoTopo();
};

Pilha::Pilha() {
    topo = nullptr;
}

Pilha::~Pilha() {
    while (!vazia()) {
        desempilha();
    }
}

void Pilha::empilha(char c, int pos) {
    Noh* novo = new Noh(c, pos);
    novo->proximo = topo;
    topo = novo;
}

void Pilha::desempilha() {
    if (!vazia()) {
        Noh* temp = topo;
        topo = topo->proximo;
        delete temp;
    }
}

bool Pilha::vazia() {
    return topo == nullptr;
}

int Pilha::getPosicaoTopo() {
    if (!vazia()) {
        return topo->posicao;
    }
    return -1;
}

int main() {
    char texto[254];
    Pilha pilha;
    
    cin.getline(texto, 254);
    int tamanho = strlen(texto);
    
    for (int i = 0; i < tamanho; i++) {
        if (texto[i] == '(') {
            pilha.empilha('(', i);
        }
        else if (texto[i] == ')') {
            if (pilha.vazia()) {
                cout << i << endl;
                return 0;
            }
            else {
                pilha.desempilha();
            }
        }
    }
    
    if (pilha.vazia()) {
        cout << "correto" << endl;
    }
    else {
        cout << pilha.getPosicaoTopo() << endl;
    }
    
    return 0;
}