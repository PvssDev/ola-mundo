#include <iostream>

struct Aluno{
    char nome[50];
    int matricula;
    float nota;
};

float mediaNotas(Aluno alunos[]){
    return (alunos[0].nota + alunos[1].nota + alunos[2].nota + alunos[3].nota + alunos[4].nota)/5;
}

int main(){
    Aluno alunos[5];

    for(int i = 0; i<5; i++){
        std::cout << "escreva o nome do " << i << "° aluno: " << std::endl;
        std::cin >> alunos[i].nome;

        std::cout << "escreva a matricula do " << i << "° aluno: " << std::endl;
        std::cin >> alunos[i].matricula;

        std::cout << "escreva a nota do " << i << "° aluno: " << std::endl;
        std::cin >> alunos[i].nota;
    }

    std::cout << "a media de notas entre os alunos é de: "<< mediaNotas(alunos) << std::endl;
}