#include <iostream>

struct No {

    int valor;
    No* esquerda;
    No* direita;
};

No* novoNo(int valor){

    No* novo = new No;
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserirNo(No* raiz, int valor){

    if(raiz == NULL)
        return novoNo(valor);
    if(valor < raiz->valor)
        raiz->esquerda = novoNo(valor);
    if(valor > raiz->valor)
        raiz->direita = novoNo(valor);
    return raiz;
}

int contarIntervalo(No* raiz, int a, int b){
    if(raiz == NULL)
        return 0;
        
        
    int cont = contarIntervalo(raiz->esquerda, a, b) + contarIntervalo(raiz->direita, a, b);
    
    if(a < raiz->valor && raiz->valor > b)
        return cont + 1;
        
    return cont;





}

int main(){

    No* raiz = NULL;

    raiz = inserirNo(raiz, 50);
    raiz = inserirNo(raiz, 30);
    raiz = inserirNo(raiz, 70);
    raiz = inserirNo(raiz, 20);
    raiz = inserirNo(raiz, 40);
    raiz = inserirNo(raiz, 60);
    raiz = inserirNo(raiz, 80);

    std::cout << contarIntervalo(raiz, 10, 50);

}