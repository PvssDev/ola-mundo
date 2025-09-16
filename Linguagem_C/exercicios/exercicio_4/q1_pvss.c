#include <stdio.h>
 
 double areaTrianguloRetangulo (double a, double c) {
     
     double resultado = (a * c)/2;
     return resultado;
 }
 
 double areaCirculo (double c) {
     
     double resultado = (c * c) * 3.14159;
     return resultado;
 } 
 
 double areaTrapezio (double a, double b, double c) {
     
     double resultado = ((a + b) * c)/2;
     return resultado;
 }
 
 double areaQuadrado (double b) {
     
     double resultado = b * b;
     return resultado;
 }
 
 double areaRetangulo (double a, double b) {
     
     double resultado = a * b;
     return resultado;
 }
 
 void imprimir (double tri, double ci, double tra, double qua, double ret) {
  
     printf("TRIANGULO: %.3lf\n", tri);
     printf("CIRCULO: %.3lf\n", ci);
     printf("TRAPEZIO: %.3lf\n", tra);
     printf("QUADRADO: %.3lf\n", qua);
     printf("RETANGULO: %.3lf\n", ret);
 }
 
int main() {
 
    double A, B, C;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);
    
    double triangulo = areaTrianguloRetangulo(A, C);
    double circulo = areaCirculo(C);
    double trapezio = areaTrapezio(A, B, C);
    double quadrado = areaQuadrado(B);
    double retangulo = areaRetangulo(A,B);
    
    imprimir(triangulo, circulo, trapezio, quadrado, retangulo);
    
    return 0;
}