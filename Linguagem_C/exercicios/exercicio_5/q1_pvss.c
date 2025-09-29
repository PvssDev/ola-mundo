#include <stdio.h>
#include <string.h>

int main() {
    int N, quantCasas;
    char codificado[60];
    char decodificado[60];
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    
    while (N > 0) {
        if (scanf("%s", codificado) != 1) break;
        if (scanf("%d", &quantCasas) != 1) break;
        
        N--;

        int tam = strlen(codificado);
        for (int i = 0; i < tam; i++) {
            int letraEncontrada = 0;
            
            for (int j = 0; j < 26; j++) {
                if (codificado[i] == alfabeto[j]) {
                    int novaPosicao = j - quantCasas;
                    if (novaPosicao < 0) {
                        decodificado[i] = alfabeto[novaPosicao + 26];
                    } else {
                        decodificado[i] = alfabeto[novaPosicao % 26];
                    }
                    letraEncontrada = 1;
                    break;
                }
            }
            
            if (!letraEncontrada) {
                decodificado[i] = codificado[i];
            }
        }
        
        decodificado[tam] = '\0';
        
        printf("%s\n", decodificado);
    }
    
    return 0;
}