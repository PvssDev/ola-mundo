#include <stdio.h>
 
int main() {
 
    double soma = 0.0;
    double M[12][12];
    char O;
    
    scanf("%c", &O);
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            
            scanf("%lf", &M[i][j]);
        }
    }
    
    if (O == 'S') {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < i; j++) {
                
                soma += M[i][j];
            }
        }
        printf("%.1lf\n", soma);
    }
    
    if (O == 'M') {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < i; j++) {
                
                soma += M[i][j];
            }
        }
        printf("%.1lf\n", soma/66);
    }
    
    return 0;
}