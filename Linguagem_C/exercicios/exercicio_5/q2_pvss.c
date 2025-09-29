#include <stdio.h>
#include <string.h>

int main() {
    char dna[102];
    char resistencia[102];

    while (scanf("%s", dna) != EOF) {
        scanf("%s", resistencia);

        int tam_dna = strlen(dna);
        int tam_resistencia = strlen(resistencia);
        int achou = 0;

        for (int i = 0; i <= tam_dna - tam_resistencia; i++) {
            int combinacao_perfeita = 1;

            for (int j = 0; j < tam_resistencia; j++) {
                if (dna[i + j] != resistencia[j]) {
                    combinacao_perfeita = 0;
                    break;
                }
            }

            if (combinacao_perfeita == 1) {
                achou = 1;
                break;
            }
        }

        if (achou == 1) {
            printf("Resistente\n");
        } else {
            printf("Nao resistente\n");
        }
    }

    return 0;
}