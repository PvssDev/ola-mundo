#include <stdio.h>
#include <string.h>
#include <ctype.h>

char verAlpha (char string[], int n) {

    for (int i = 0; i < n; i++) {
    }
}

int main() {

    int N, quantCasas;
    char alfabeto[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char codificado [50];
    char decodificado[50];
    
    scanf("%i", &N);
    
    while (N > 0) {
        scanf("%s", codificado);
        scanf("%i", &quantCasas);
        N--;

        for (int i = 0; i < strlen(codificado); i++) {
            for (int j = 0; j < 26; j++) {
                
                if (codificado[i] == alfabeto[j]) {

                    if (j - quantCasas < 0){
                        decodificado[i] = alfabeto[j - quantCasas + 26];

                    }else{
                        decodificado[i] = alfabeto[j - quantCasas];
                    }
                }
            }

            printf("%c", decodificado[i]);
        }
        
        printf("\n");
    }
    
    return 0;
}