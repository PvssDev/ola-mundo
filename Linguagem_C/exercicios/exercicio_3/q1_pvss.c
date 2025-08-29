#include <stdio.h>
 
int main() {
 
    int T, N;
    unsigned long long fib[61];
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < 61; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    scanf("%i", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%i", &N);
        printf("Fib(%i) = %llu\n", N, fib[N]);
    }
 
    return 0;
}