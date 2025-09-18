#include <stdio.h>
#include <math.h>

 double calcularRaizes (double a, double b, double c) {
     
    double delta = (b*b) - (4 * a * c);
    
    if (delta < 0) {
    
        return 1;
    }else{
        
        double resultado = sqrt(delta);
        return resultado;
    }
 }
 
 void imprimir (double r1, double r2) {
     
     printf("R1 = %.5lf\n", r1);
     printf("R2 = %.5lf\n", r2);
 }
 
int main() {
 
    double A, B, C;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);
    
    if (A == 0 || calcularRaizes(A, B, C) == 1) {
     
        printf("Impossivel calcular\n"); 
        
    }else{
        
        double raiz = calcularRaizes(A, B, C);
    
        double R1 = (-B + raiz)/(A * 2);
        double R2 = (-B - raiz)/(A * 2);
        
        imprimir(R1, R2);
    }
    
    return 0;
}