#include <stdio.h>
#include <string.h>

enum Numeros {

    ONE,
    TWO,
    THREE,

}typedef Numeros;

struct Palavras {

    char one[10];
    char two[10];
    char three[10];

}typedef Palavras;

int main () {

    Palavras comparativo;

    strcpy(comparativo.one, "one");
    strcpy(comparativo.two, "two");
    strcpy(comparativo.three, "three");

    int deOne, deTwo, deThree;
    char palavra[10];
    int N;

    do{

        scanf("%i", &N);

    }while (N > 1000);

    for (int i = 0; i < N; i++){
        
        deOne = 0;
        deTwo = 0;
        deThree = 0;

        scanf("%s", palavra);

        for (int p = 0; p < strlen(palavra); p++) {
            
            if (strlen(palavra) == 3) {

                if (palavra[p] == comparativo.one[p]){
                    
                    deOne++;
                }
                if (palavra[p] == comparativo.two[p]){
                    
                    deTwo++;
                }
                }else{

                    if (palavra[p] == comparativo.three[p]){
                        
                        deThree++;
                }
            }
        }
        if(deOne > deTwo && deOne > deThree) {
            printf("%i\n", 1);

        }else if (deTwo > deOne && deTwo > deThree) {
            printf("%i\n", 2);

        }else if (deThree > deOne && deThree > deTwo){
            printf("%i\n", 3);
        }
    }
    return 0;
}