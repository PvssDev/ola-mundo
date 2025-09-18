#include <stdio.h>

double calcularReajuste (double s) {
    
    double resultado;
    
    if (s >= 0 && s <= 400){
        resultado = s * 1.15;
        
    }else if (s > 400 && s <= 800) {
        resultado = s * 1.12;
        
    }else if (s > 800 && s <= 1200) {
        resultado = s * 1.10;
        
    }else if (s > 1200 && s <= 2000) {
        resultado = s * 1.07;
        
    }else{
        resultado = s * 1.04;
    }
    return resultado;
}
 
 void imprimir (double nSalario, double rGanho, double pCentual) {
     
     printf("Novo salario: %.2lf\n", nSalario);
     printf("Reajuste ganho: %.2lf\n", rGanho);
     printf("Em percentual: %.lf %\n", pCentual);
 }
int main() {
 
    double salario;
    
        scanf("%lf", &salario);
    
    double novoSalario = calcularReajuste(salario);
    double reajusteGanho = calcularReajuste(salario) - salario;
    double percentual = ((calcularReajuste(salario) / salario) - 1) * 100;
    
    imprimir(novoSalario, reajusteGanho, percentual);
    
    return 0;
}