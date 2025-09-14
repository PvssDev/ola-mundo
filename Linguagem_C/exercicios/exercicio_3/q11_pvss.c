#include <stdio.h>

double calcularMedia(double n[], int s) {
    
    double resultado = 0;
    
    for (int i = 0; i < s; i++) {
        
        resultado += n[i]; 
    }
    
    return resultado;
}

void imprimir (double r) {
    
    printf("%2.lf", r);
}

int main()
{
    double media;
    
    int size;
    scanf("Digite quantas notas você fara media: %i\n", &size);
    double notas[size];
    
    for (int i = 0; i < size; i++) {
        
        scanf("Digite sua nota: %lf", &notas[i]);
    }
    
    media = calcularMedia(notas, size);
    
    imprimir(media);
    

    return 0;
}