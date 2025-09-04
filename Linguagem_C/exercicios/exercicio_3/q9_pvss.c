#include <stdio.h>
 
int main() {
 
    double A[100];
    
    for (int i = 0; i < 100; i++) {
        
        scanf("%lf\n", &A[i]);
    }
    
    for (int i = 0; i < 100; i++) {
        if (A[i] <= 10) {
            
            printf("A[%i] = %.1lf\n", i, A[i]);
        }
    }
    return 0;
}