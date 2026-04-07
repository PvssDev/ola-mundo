#include <iostream>
//#include <stdlib.h>

using namespace std;

// Estrutura do nó
struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

// Criação de um novo nó
No* novoNo(int valor) {
    No* novo = new No; // No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL; 
    novo->direita = NULL;
    return novo;
}

// Inserção em árvore binária de busca
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) 
        return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

// Busca em árvore binária
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    return buscar(raiz->direita, valor);
}

// Encontrar o menor valor da subárvore
No* encontrarMinimo(No* node) {
    while (node->esquerda != NULL)
        node = node->esquerda;
    return node;
}

// Remoção em árvore binária
No* remover(No* raiz, int valor) {                      40
    if (raiz == NULL)                       20                     60
        return raiz;                 10           30        50            70
    if (valor < raiz->valor)       5   15      25    35  45    55      65    75
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            delete raiz; // free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            delete raiz; // free(raiz);
            return temp;
        }
        No* temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

// Travessia em ordem
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        cout << raiz->valor << " ";
        emOrdem(raiz->direita);
    }
}

// Função principal
int main() {
    No* raiz = NULL;

    // Inserções
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    cout << "\nArvore em ordem: ";
    emOrdem(raiz);

    // Remoção
    raiz = remover(raiz, 20); // Nó sem filhos
    raiz = remover(raiz, 30); // Nó com um filho
    raiz = remover(raiz, 50); // Nó com dois filhos

    cout << "\nArvore apos remocoes: ";
    emOrdem(raiz);

    system("PAUSE");
    //return 0;
}