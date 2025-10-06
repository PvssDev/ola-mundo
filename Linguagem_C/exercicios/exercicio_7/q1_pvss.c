#include <stdio.h>
#include <string.h>

struct Tempo{
    
    int h1;
    int m1; 
    int h2;
    int m2;
    
}typedef Tempo;

void calcularTempo (int *h1, int *m1, int *h2, int *m2) {
    
    int resultado;

    int minutos1 = *h1 * 60 + *m1;
    int minutos2 = *h2 * 60 + *m2;

        if (minutos1 == minutos2) {
            resultado = 24 * 60;

        } else if (minutos2 > minutos1) {
            resultado = minutos2 - minutos1;

        } else {
            resultado = (24 * 60 - minutos1) + minutos2;
        }

    printf("%i\n", resultado);
}

int main()
{
    Tempo tempo;
    
    while (1) {
        do {

            scanf("%i", &tempo.h1);
            scanf("%i", &tempo.m1);
            scanf("%i", &tempo.h2);
            scanf("%i", &tempo.m2);

        }while(tempo.h1 < 0 || tempo.h1 > 23 || tempo.h2 < 0 || tempo.h2 > 23 || tempo.m1 < 0 || tempo.m1 > 59 || tempo.m2 < 0 || tempo.m2 > 59);
        
        if (tempo.h1 == 0 && tempo.h2 == 0 && tempo.m1 == 0 && tempo.m2 == 0){
            break;
        }
        
        calcularTempo(&tempo.h1, &tempo.m1, &tempo.h2, &tempo.m2);
    }
    
    return 0;
}