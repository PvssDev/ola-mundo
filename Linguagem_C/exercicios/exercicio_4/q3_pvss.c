#include <stdio.h>
 
 int contarCedulas(int v, int c) {
     
     int resultado = v/c;
     return resultado;
 }
 
 void imprimirNotas (int iNota, int iValor ) {
     
     printf("%i nota(s) de R$ %i,00\n", iNota, iValor);
 }
 
int main() {
 
    int valor = -1;
    
    while(valor < 0 || valor > 1000000) {
        
        scanf("%i", &valor);
    }
    
    printf("%i\n", valor);
    
    int notaCem = contarCedulas(valor, 100);
    valor -= notaCem*100;
    imprimirNotas(notaCem, 100);
    
    int notaCinq = contarCedulas(valor, 50);
    valor -= notaCinq*50;
    imprimirNotas(notaCinq, 50);
    
    int notaVin = contarCedulas(valor, 20);
    valor -= notaVin*20;
    imprimirNotas(notaVin, 20);
    
    int notaDez = contarCedulas(valor, 10);
    valor -= notaDez*10;
    imprimirNotas(notaDez, 10);
    
    int notaCinc = contarCedulas(valor, 5);
    valor -= notaCinc*5;
    imprimirNotas(notaCinc, 5);
    
    int notaDois = contarCedulas(valor, 2);
    valor -= notaDois*2;
    imprimirNotas(notaDois, 2);
    
    int notaUm = contarCedulas(valor, 1);
    imprimirNotas(notaUm, 1);
 
    return 0;
}