#include <stdio.h>
 
int main() {
 
    int N[10];
    
    do {
        
        scanf("%i", &N[0]);
        
    } while (N[0] > 50);
    
    for (int i = 1; i < 10; i++) {
        
        N[i] = N[i - 1] * 2;
    }
    
    for(int i = 0; i < 10; i++) {
        
        printf("N[%i] = %i\n", i, N[i]);
    }
 
    return 0;
}