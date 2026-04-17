#include <iostream>


struct Pessoa{
    char nome[50];
    int idade;
    float altura;
};


int main(){

    Pessoa pessoa1;

    std::cout << "Digite o seu nome:";
    std::cin >> pessoa1.nome;

    std::cout << "\nDigite a sua idade:";
    std::cin >> pessoa1.idade;

    std::cout << "\nDigite a sua altura:";
    std::cin >> pessoa1.altura;
}