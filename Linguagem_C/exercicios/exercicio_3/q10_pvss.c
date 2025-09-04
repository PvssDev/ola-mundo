#include <stdio.h>
 
int main() {
 
    int N[20];
    int dados;
    
    for (int i = 0; i < 20; i++) {
        scanf("%i", &N[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        dados = N[i];
        N[i] = N[-i -1];
    }
 
    for (int i = 0; i < 20; i++) {
        printf("N[%i] = %i\n", i, N[i]);
    }
    return 0;
}