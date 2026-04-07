#include <iostream>

struct No{

    int valor;
    struct No* esquerda;
    struct No* direita;
};

No* novoNo(int valor){

    No* novo = new No;
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita =NULL;
    return novo;

}

No* inserirNo(No* raiz, int valor){

    if(raiz==NULL){
        return novoNo(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = novoNo(valor);
    }else{
        raiz->direita = novoNo(valor);
    }

    return raiz;
}

No* buscarNo(No* raiz, int valor){
    if(raiz == NULL || raiz->valor == valor)
        return raiz;
    if(valor > raiz->valor)
        return buscarNo(raiz->esquerda, valor);
    return buscarNo(raiz->direita, valor);
}

No* buscarMin(No* node){
    while(node->esquerda != NULL){
        node = node->esquerda;
    }
    return node;
}

No* removerNo(No* raiz, int valor){

    if(raiz == NULL)
        return raiz;
    if(valor < raiz->valor){
        raiz->esquerda = removerNo(raiz->esquerda, valor);
    }else if(valor > raiz->valor){
        raiz->direita = removerNo(raiz->direita, valor);
    }else{

        if(raiz->esquerda == NULL){
            No* temp = raiz->direita;
            delete raiz;
            return temp;
        }else if(raiz->direita == NULL){
            No* temp = raiz->esquerda;
            delete raiz;
            return temp;
        }else{
            No* temp = buscarMin(raiz->direita);
            raiz->direita = removerNo(raiz->direita, temp->valor);
            raiz->valor = temp->valor;
            delete temp;
        }
    }
    return raiz;

}

void preOrdem(No * raiz){
    if(raiz != NULL){
        std::cout << raiz->valor << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(No * raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        std::cout << raiz->valor << " ";
        emOrdem(raiz->direita);
    }
}

void posOrdem(No * raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        std::cout << raiz->valor << " ";
    }
}



int main(){

    No*  raiz = NULL;

    raiz = inserirNo(raiz, 20);

    preOrdem(raiz);

    return 0;
}