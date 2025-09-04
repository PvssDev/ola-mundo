#include <stdio.h>
 
int main() {
 
    double soma = 0.0;
    double M[12][12];
    char T;
    int C;
    
    scanf("%i", &C);
    scanf(" %c", &T);
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            
            scanf("%lf", &M[i][j]);
        }
    }
    
    if (T == 'S') {
        for (int i = 0; i < 12; i++) {
                
            soma += M[i][C];

        }
        printf("%.1lf\n", soma);
    }
    
    if (T == 'M') {
        for (int i = 0; i < 12; i++) {
                
            soma += M[i][C];

        }
        printf("%.1lf\n", soma/12);
    }
    
    return 0;
}