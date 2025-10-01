#include <stdio.h>

struct Pessoa{

    char S[20];

}typedef Pessoa;
 
int main() {
 
    int N, K;
    char S[20];
    
    scanf("%i", &N);
    
    for (int i = 0; i < N; i++){
        
        int contador = 0;

        
        do {
            scanf("%i", &K);
            
        }while (K < 2 || K > 100);
        
        Pessoa pessoa[K];

        for (int i = 0; i < K; i++){

            scanf("%s", pessoa[i].S);
            
        }
        for (int i = 0; i < K; i++){

            if ( strcmp(pessoa[0].S, pessoa[i].S) == 0 ) {
                contador++;
            }
        }
        if (contador == K){
            printf("%s\n", pessoa[0].S);

        }else{
            printf("ingles\n");
        }
        
    }
 
    return 0;
}