#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* 3 Questão da ficha de árvores  binárias. As questões 1 e 2 foram feitas no meu caderno,
onde estou enviando como pdf também. Veja o readme para ler as questões no pdf, caso esteja
difícil de lê-las diretamente pelo pdf(digitei no readme para melhor leitura).

*/
struct No {
    int valor;
    No* esquerda;
    No* direita;
};

No* inserir(No* raiz, int valor) {
    if (raiz == nullptr) {
        No* novo = new No;
        novo->valor = valor;
        novo->esquerda = nullptr;
        novo->direita = nullptr;
        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

bool buscar(No* raiz, int valor) {
    if (raiz == nullptr) {
        return false;
    }

    if (raiz->valor == valor) {
        return true;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }

    return buscar(raiz->direita, valor);
}

// Pre-ordem: visita a raiz, depois a esquerda e depois a direita.
void preOrdem(No* raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Em ordem: visita a esquerda, depois a raiz e depois a direita.
void emOrdem(No* raiz) {
    if (raiz != nullptr) {
        emOrdem(raiz->esquerda);
        cout << raiz->valor << " ";
        emOrdem(raiz->direita);
    }
}

// Pos-ordem: visita a esquerda, depois a direita e por fim a raiz.
void posOrdem(No* raiz) {
    if (raiz != nullptr) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->valor << " ";
    }
}

void liberarArvore(No* raiz) {
    if (raiz != nullptr) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        delete raiz;
    }
}

int main() {
    No* raiz = nullptr;

    int valores[] = {45, 25, 65, 15, 35, 55, 75};

    for (int i = 0; i < 7; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    cout << "Percurso Pre-ordem: ";
    preOrdem(raiz);
    cout << endl;

    cout << "Percurso em ordem: ";
    emOrdem(raiz);
    cout << endl;

    cout << "Percurso Pos-ordem: ";
    posOrdem(raiz);
    cout << endl;

    int valor;

    cout << "\nDigite um valor para buscarmos: ";
    cin >> valor;

    if (buscar(raiz, valor)) {
        cout << valor << " foi encontrado na árvore!" << endl;
    } else {
        cout << valor << " não foi encontrado na árvore!" << endl;
    }

    liberarArvore(raiz);
    raiz = nullptr;

    return 0;
}
