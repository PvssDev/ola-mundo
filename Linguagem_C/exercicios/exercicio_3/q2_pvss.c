#include <stdio.h>
 
int main() {
 
    int L;
    char T;
    double M[12][12];
    double soma = 0.0;
    double media = 0.0;
    
    scanf("%i", &L);
    scanf(" %c", &T);
        
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }
    
    if (T == 'S') {
        for (int j = 0; j < 12; j++) {
            soma += M[L][j];
        }
        printf("%.1lf\n", soma);
    }
    
    if (T == 'M') {
        for (int j = 0; j < 12; j++) {
            
            soma += M[L][j];
        }
        media = soma/12.0;
        printf("%.1lf\n", media);
    }
 
    return 0;
}