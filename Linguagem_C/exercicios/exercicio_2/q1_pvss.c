#include <stdio.h>
 
int main() {
 
    double n;
    int notas, moedas, valor;
    
    scanf("%lf", &n);
    
    valor = n*100;
    
    printf("NOTAS:\n");
    
    notas = valor / 10000;
    printf("%i nota(s) de R$ 100.00\n", notas);
    valor = valor % 10000;
    
    notas = valor / 5000;
    printf("%i nota(s) de R$ 50.00\n", notas);
    valor = valor % 5000;
    
    notas = valor / 2000;
    printf("%i nota(s) de R$ 20.00\n", notas);
    valor = valor % 2000;
    
    notas = valor / 1000;
    printf("%i nota(s) de R$ 10.00\n", notas);
    valor = valor % 1000;
    
    notas = valor / 500;
    printf("%i nota(s) de R$ 5.00\n", notas);
    valor = valor % 500;
    
    notas = valor / 200;
    printf("%i nota(s) de R$ 2.00\n", notas);
    valor = valor % 200;
    
    printf("MOEDAS:\n");
    
    moedas = valor / 100;
    printf("%i moeda(s) de R$ 1.00\n", moedas);
    valor = valor % 100;
    
    moedas = valor / 50;
    printf("%i moeda(s) de R$ 0.50\n", moedas);
    valor = valor% 50;
    
    moedas = valor / 25;
    printf("%i moeda(s) de R$ 0.25\n", moedas);
    valor = valor % 25;
    
    moedas = valor / 10;
    printf("%i moeda(s) de R$ 0.10\n", moedas);
    valor = valor % 10;
    
    moedas = valor / 5;
    printf("%i moeda(s) de R$ 0.05\n", moedas);
    valor = valor % 5;
    
    moedas = valor / 1;
    printf("%i moeda(s) de R$ 0.01\n", moedas);
    
 
    return 0;
}