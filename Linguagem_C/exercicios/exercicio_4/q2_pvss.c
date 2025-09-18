#include <stdio.h>
#include <math.h>
 
 double calcularDistancia (double x1, double y1, double x2, double y2) {
     
     double resultado = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
     return resultado;
 }
 
 void imprimir(double parametro) {
     
     printf("%.4lf\n", parametro);
 }
 
int main() {
    
    double p1[2], p2[2];
    
    scanf("%lf", &p1[0]);
    scanf("%lf", &p1[1]);
    scanf("%lf", &p2[0]);
    scanf("%lf", &p2[1]);
    
    double resultadoDistancia = calcularDistancia (p1[0], p1[1], p2[0], p2[1]);
    
    imprimir(resultadoDistancia);
    
    return 0;
}