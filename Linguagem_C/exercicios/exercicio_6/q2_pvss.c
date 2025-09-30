#include <stdio.h>

int calcularQuadrados(int n) {

    int resultado = 0;
    for (int i = 1; i <= n; i++) {
        resultado += i * i;
    }
    return resultado;
}

struct Figura {

    int lado;
    int numeroQuadrados;

} typedef Figura;

int main () {

    Figura N;

    do {

        do{
            
            scanf("%i", &N.lado);

        } while (N.lado < 0 || N.lado > 100);

        if (N.lado == 0) {
            break;
        }
        N.numeroQuadrados = calcularQuadrados(N.lado);

        printf("%i\n", N.numeroQuadrados);

    } while (1);

    return 0;
}