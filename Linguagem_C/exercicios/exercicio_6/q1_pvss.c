#include <stdio.h>
#include <string.h>
 
enum TipoAnim {

    VERTEBRADO,
    INVERTEBRADO,  

    AVE,  
    MAMIFERO,  
    INSETO,  
    ANELIDEO,  

    CARNIVORO,  
    ONIVORO,  
    HERBIVORO,  
    HEMATOFAGO,

} typedef TipoAnim;

struct Animal {

    char TipoAnim;
    char tipoAnim;
    char tipoAlim;

} typedef Animal;

enum TipoAnim GetTipoAnim (char* str) {

    if (strcmp(str, "vertebrado") == 0) {
        return 0;
    }
    if (strcmp(str, "invertebrado") == 0) {
        return 1;
    }
    if (strcmp(str, "ave") == 0) {
        return 2;
    }
    if (strcmp(str, "mamifero") == 0) {        
        return 3;
    }
    if (strcmp(str, "inseto") == 0) {
        return 4;
    }
    if (strcmp(str, "anelideo") == 0) {
        return 5;
    }
    if (strcmp(str, "carnivoro") == 0) {
        return 6;
    }
    if (strcmp(str, "onivoro") == 0) {
        return 7;
    }
    if (strcmp(str, "herbivoro") == 0) {
        return 8;
    }
    if (strcmp(str, "hematofago") == 0) {
        return 9;
    }
}
 
int main() {
 
    char palavra[20], palavra2[20], palavra3[20];
    TipoAnim opcao, opcao2, opcao3;

    scanf("%s", palavra);
    scanf("%s", palavra2);
    scanf("%s", palavra3);
 
    opcao = GetTipoAnim(palavra);
    opcao2 = GetTipoAnim(palavra2);
    opcao3 = GetTipoAnim(palavra3);

    if (opcao == VERTEBRADO) {
        if (opcao2 == AVE) {
            if (opcao3 == CARNIVORO) {
                printf("aguia\n");

            }else if (opcao3 == ONIVORO){
                printf("pomba\n");
            }
        }else if (opcao2 == MAMIFERO) {
            if (opcao3 == ONIVORO){
                printf("homem\n");

            }else if (opcao3 == HERBIVORO){
                printf("vaca\n");
            }
        }

    }else if (opcao == INVERTEBRADO){
        if (opcao2 == INSETO) {
            if(opcao3 == HEMATOFAGO) {
                printf("pulga\n");

            }else if (opcao3 == HERBIVORO) {
                printf("lagarta\n");
            }
        }else if (opcao2 == ANELIDEO) {
            if (opcao3 == HEMATOFAGO) {
                printf("sanguessuga\n");

            }else if (opcao3 == ONIVORO) {
                printf("minhoca\n");
            }
        }
    }

    return 0;
}