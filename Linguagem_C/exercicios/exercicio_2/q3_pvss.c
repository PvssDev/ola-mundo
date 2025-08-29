#include <stdio.h>
 
int main() {
 
    double salario, imposto, excedente;
    imposto = 0.0;
    
    scanf("%lf", &salario);

    excedente = salario;
    
    if (salario > 4500) {
        excedente = salario - 4500.00;
        imposto += (excedente / 100) * 28;
        excedente = 4500.00;
    }
    if (salario > 3000.00) {
        excedente = excedente - 3000.00;
        imposto += (excedente / 100) * 18;
        excedente = 3000.00;
    }
    if (salario > 2000.00) {
        excedente = excedente - 2000.00;
        imposto += (excedente / 100) * 8;
    }
    if (imposto == 0.0) {
        printf("Isento\n");
    } else {
        printf("R$ %.2lf\n", imposto);
    }
 
    return 0;
}