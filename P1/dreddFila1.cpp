#include <iostream>
using namespace std;

class noh {
    friend class fila;
private:
    int dado;
    noh* prox;
public:
    noh(int valor) : dado(valor), prox(nullptr) {};
};

class fila {
private:
    noh* inicio;
    noh* fim;
    int tam;
public:
    fila();
    fila(const fila& outra);
    fila& operator=(const fila& outra);
    ~fila();
    void enfileira(int valor);
    int desenfileira();
    bool vazia();
    void remove(fila& f2);
    void imprime();
};

fila::fila() : inicio(nullptr), fim(nullptr), tam(0) {}

fila::fila(const fila& outra) : inicio(nullptr), fim(nullptr), tam(0) {
    noh* atual = outra.inicio;
    while (atual != nullptr) {
        enfileira(atual->dado);
        atual = atual->prox;
    }
}

fila& fila::operator=(const fila& outra) {
    if (this != &outra) {
        
        while (!vazia()) {
            desenfileira();
        }
        noh* atual = outra.inicio;
        while (atual != nullptr) {
            enfileira(atual->dado);
            atual = atual->prox;
        }
    }
    return *this;
}

fila::~fila() {
    while (!vazia()) {
        desenfileira();
    }
}

bool fila::vazia() {
    return inicio == nullptr;
}

void fila::enfileira(int valor) {
    noh* novoNoh = new noh(valor);
    if (vazia()) {
        inicio = fim = novoNoh;
    } else {
        fim->prox = novoNoh;
        fim = novoNoh;
    }
    tam++;
}

int fila::desenfileira() {
    if (vazia()) {
        cout << "vazia" << endl;
        return -1;
    }

    noh* temp = inicio;
    int valor = temp->dado;
    inicio = inicio->prox;
    delete temp;
    tam--;

    if (inicio == nullptr) {
        fim = nullptr;
    }

    return valor;
}

void fila::remove(fila& f2) {
    if (vazia() || f2.vazia()) {
        return;
    }

    fila temp;

    while (!vazia()) {
        int elem = desenfileira();
        bool remover = false;

        fila copiaf2 = f2;

        while (!copiaf2.vazia()) {
            int elemf2 = copiaf2.desenfileira();
            if (elem == elemf2) {
                remover = true;
                break;
            }
        }

        if (!remover) {
            temp.enfileira(elem);
        }
    }

    while (!temp.vazia()) {
        enfileira(temp.desenfileira());
    }
}

void fila::imprime() {
    if (vazia()) {
        return;
    }

    fila temp;

    while (!vazia()) {
        int elemento = desenfileira();
        cout << elemento << " ";
        temp.enfileira(elemento);
    }

    while (!temp.vazia()) {
        enfileira(temp.desenfileira());
    }
}


int main() {
    fila f1;
    int n1;
    fila f2;
    int n2;

    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int valor;
        cin >> valor;
        f1.enfileira(valor);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int valor;
        cin >> valor;
        f2.enfileira(valor);
    }

    f1.remove(f2);

    f1.imprime();
    cout << endl;

    return 0;
}
