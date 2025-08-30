#include <stdio.h>
 
int main() {
 
    int L;
    char T;
    double M[12][12];
    double soma = 0.0;
    double media = 0.0;
    
    scanf("%i", &L);
    getchar();
    scanf("%c", &T);
        
    for(int j = 0; j < 12; j++) {
        
        scanf("%lf", &M[L - 1][j]);
    }
    
    if (T == 'S') {
        for (int j = 0; j < 12; j++) {
            
            soma += M[L - 1][j];
        }
        printf("%.1lf", soma);
        
    }
    
    if (T == 'M') {
        for (int j = 0; j < 12; j++) {
            
            soma += M[L - 1][j];
        }
        media = soma/12;
        printf("%.1lf", media);
    }
 
    return 0;
}