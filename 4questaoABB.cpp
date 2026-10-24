#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* 4 Questão lista árvores binárias*/
struct No {
    int valor;
    No* esquerda;
    No* direita;
};

No* inserir(No* raiz, int valor, bool& inserido) {
    if (raiz == nullptr) {
        No* novo = new No;
        novo->valor = valor;
        novo->esquerda = nullptr;
        novo->direita = nullptr;

        inserido = true;
        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor, inserido);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor, inserido);
    } else {
        inserido = false;
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

// Visita a raiz, a esquerda e depois a direita.
void preOrdem(No* raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Visita a esquerda, a direita e depois a raiz.
void posOrdem(No* raiz) {
    if (raiz != nullptr) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->valor << " ";
    }
}

int contarNos(No* raiz) {
    if (raiz == nullptr) {
        return 0;
    }

    return 1 + contarNos(raiz->esquerda)
             + contarNos(raiz->direita);
}

int contarFolhas(No* raiz) {
    if (raiz == nullptr) {
        return 0;
    }

    if (raiz->esquerda == nullptr &&
        raiz->direita == nullptr) {
        return 1;
    }

    return contarFolhas(raiz->esquerda)
         + contarFolhas(raiz->direita);
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
    int opcao, valor;
    bool inserido;

    do {
        cout << "\n============= TESTE DE ÁRVORE BINÁRIA - WILLIAM VANGEANCE============\n"; //botei o william no título da atividade como referência ao personagem, professor
        cout << "[1] - Inserir valor\n";
        cout << "[2] - Buscar valor\n";
        cout << "[3] - Mostrar em pré-ordem\n";
        cout << "[4] - Mostrar em pós-ordem\n";
        cout << "[5] - Contar nós\n";
        cout << "[6] - Contar folhas\n";
        cout << "[0] - Sair/encerrar programa\n";
        cout << "\n===========================================================\n";
        cout << "Opção desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Valor para inserir: ";
                cin >> valor;

                inserido = false;
                raiz = inserir(raiz, valor, inserido);

                if (inserido) {
                    cout << "Valor inserido." << endl;
                } else {
                    cout << "Valor duplicado detectado. Inserção não realizada!"
                         << endl;
                }
                break;

            case 2:
                if (raiz == nullptr) {
                    cout << "Árvore atualmente vazia." << endl;
                } else {
                    cout << "Valor para buscar: ";
                    cin >> valor;

                    if (buscar(raiz, valor)) {
                        cout << "Valor encontrado com sucesso!" << endl;
                    } else {
                        cout << "Valor não encontrado!" << endl;
                    }
                }
                break;

            case 3:
                if (raiz == nullptr) {
                    cout << "Árvore atualmente vazia." << endl;
                } else {
                    cout << "Percurso Pré-ordem no momento: ";
                    preOrdem(raiz);
                    cout << endl;
                }
                break;

            case 4:
                if (raiz == nullptr) {
                    cout << "Árvore atualmente vazia." << endl;
                } else {
                    cout << "Percurso Pós-ordem no momento: ";
                    posOrdem(raiz);
                    cout << endl;
                }
                break;

            case 5:
                cout << "Quantidade de nós no momento: "
                     << contarNos(raiz) << endl;
                break;

            case 6:
                cout << "Quantidade de folhas: "
                     << contarFolhas(raiz) << endl;
                break;

            case 0:
                break;

            default:
                cout << "Opção inválida!" << endl;
        }

    } while (opcao != 0);

    liberarArvore(raiz);
    raiz = nullptr;

    cout << "Memória da árvore liberada!" << endl;

    return 0;
}
