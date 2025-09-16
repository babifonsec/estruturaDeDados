#include <iostream>
#include <string>
using namespace std;

struct Atividade {
    int nota;
    int tentativas;
};

struct Aluno {
    int matricula;
    string nome;
    double media;
    int tentativas;
};

bool melhorAluno(const Aluno& a, const Aluno& b) {
    if (a.media != b.media)
        return a.media > b.media;
    if (a.tentativas != b.tentativas)
        return a.tentativas < b.tentativas;
    return a.nome < b.nome;
}

class Heap {
private:
    Aluno* dados;
    int capacidade;
    int tamanho;

    void sobeHeap(int i) {
        while (i > 0) {
            int pai = (i - 1) / 2;
            if (melhorAluno(dados[i], dados[pai])) {
                swap(dados[i], dados[pai]);
                i = pai;
            } else break;
        }
    }

    void desceHeap(int i) {
        while (true) {
            int esq = 2 * i + 1;
            int dir = 2 * i + 2;
            int maior = i;

            if (esq < tamanho && melhorAluno(dados[esq], dados[maior]))
                maior = esq;
            if (dir < tamanho && melhorAluno(dados[dir], dados[maior]))
                maior = dir;

            if (maior != i) {
                swap(dados[i], dados[maior]);
                i = maior;
            } else break;
        }
    }

public:
    Heap(int cap) {
        capacidade = cap;
        tamanho = 0;
        dados = new Aluno[cap];
    }

    ~Heap() {
        delete[] dados;
    }

    void insere(const Aluno& a) {
        if (tamanho == capacidade) return;
        dados[tamanho] = a;
        sobeHeap(tamanho);
        tamanho++;
    }

    Aluno remove() {
        Aluno topo = dados[0];
        dados[0] = dados[tamanho - 1];
        tamanho--;
        desceHeap(0);
        return topo;
    }

    bool vazia() {
        return tamanho == 0;
    }
};

int main() {
    int qtdAlunos, qtdAtividades;
    cin >> qtdAlunos >> qtdAtividades;

    Heap heap(qtdAlunos);

    for (int i = 0; i < qtdAlunos; i++) {
        Aluno aluno;
        cin >> aluno.matricula >> aluno.nome;

        int somaNotas = 0;
        int somaTentativas = 0;

        for (int j = 0; j < qtdAtividades; j++) {
            int nota, tent;
            cin >> nota >> tent;
            somaNotas += nota;
            somaTentativas += tent;
        }

        aluno.media = (double)somaNotas / qtdAtividades;
        aluno.tentativas = somaTentativas;

        heap.insere(aluno);
    }

    Aluno destaque = heap.remove();
    cout << "[" << destaque.matricula << "] " << destaque.nome << endl;

    return 0;
}
