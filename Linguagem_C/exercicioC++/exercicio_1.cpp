//conta bancaria, saque e deposito

#include <iostream>

struct ContaBancaria {

    char nome[50];
    int numero;
    float saldo;

}typedef ContaBancaria;

void depositarValor (ContaBancaria *contaBan, float valor){

    if (valor > 0){

        contaBan->saldo = contaBan->saldo + valor;
    }
    std::cout << "Deposito concluido\n";
}

void sacarValor (ContaBancaria *contaBan, float valor){

    if (contaBan->saldo >= valor){

        contaBan->saldo = contaBan->saldo - valor;
    }
    std::cout << "Saque concluido!\n";
}

int main () {

    ContaBancaria conta1;
    conta1.saldo = 0;
    int escolha;
    int valor;

    std::cout << "Digite o nome da sua conta:";
    std::cin >> conta1.nome;

    std::cout << "Digite o numero da sua conta:";
    std::cin >> conta1.numero;

    std::cout << "Bem vindo " << conta1.nome << "!\n";

    while (true) {

        std::cout << "\nEscolha uma das opções abaixo\n";
        std::cout << "\n1-Depositar";
        std::cout << "\n2-Sacar";
        std::cout << "\n3-Ver Saldo";
        std::cout << "\n4-Finalizar\n";
        std::cin >> escolha;

        if (escolha == 4){
            break;
        }

        switch (escolha){

            case 1:
                std::cout << "O valor da sua conta é " << conta1.saldo;
                std::cout << "\nDigite qual o valor do deposito:";
                std::cin >> valor;
                depositarValor(&conta1, valor);
                break;
            
                
            case 2:
                std::cout << "O valor da sua conta é " << conta1.saldo;
                std::cout << "Digite qual o valor do seu saque:";
                std::cin >> valor;
                sacarValor(&conta1, valor);
                break;
            
            case 3:
            std::cout << "O saldo da sua conta é: " << conta1.saldo;
            break;
        }
    }
    std::cout << "Programa finalizado";
}