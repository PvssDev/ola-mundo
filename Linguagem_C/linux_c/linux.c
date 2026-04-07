#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um frame de memória no estilo Linux
typedef struct {
    int id;
    int ref_bit; // Bit de referência (Clock)
    bool dirty;  // Bit de modificação (Escrita)
    int last_used; // Para o LRU teórico
} PageFrame;

// --- FUNÇÕES DE AUXÍLIO ---

void print_frames(PageFrame frames[], int capacity) {
    printf("[ ");
    for (int i = 0; i < capacity; i++) {
        if (frames[i].id == -1) printf("- ");
        else printf("%d ", frames[i].id);
    }
    printf("]");
}

// --- 1. FIFO (First-In, First-Out) ---
void runFIFO(int pages[], int n, int capacity) {
    int frames[capacity];
    for (int i = 0; i < capacity; i++) frames[i] = -1;
    int faults = 0, ptr = 0;

    printf("\n--- Execução FIFO ---\n");
    for (int i = 0; i < n; i++) {
        bool hit = false;
        for(int j=0; j<capacity; j++) if(frames[j] == pages[i]) hit = true;

        if (!hit) {
            frames[ptr] = pages[i];
            ptr = (ptr + 1) % capacity;
            faults++;
            printf("Acesso %d: ", pages[i]);
            for(int j=0; j<capacity; j++) printf("%d ", frames[j]);
            printf(" -> FAULT\n");
        } else {
            printf("Acesso %d: HIT\n", pages[i]);
        }
    }
    printf("Total Page Faults FIFO: %d (%.2f%%)\n", faults, (float)faults/n*100);
}

// --- 2. LRU (Least Recently Used - Teórico) ---
void runLRU(int pages[], int n, int capacity) {
    PageFrame frames[capacity];
    for (int i = 0; i < capacity; i++) { frames[i].id = -1; frames[i].last_used = 0; }
    int faults = 0;

    printf("\n--- Execução LRU ---\n");
    for (int i = 0; i < n; i++) {
        bool hit = false;
        for(int j=0; j<capacity; j++) {
            if(frames[j].id == pages[i]) {
                frames[j].last_used = i; // Atualiza o tempo de uso
                hit = true;
                break;
            }
        }
        if(!hit) {
            int lru_idx = 0;
            for(int j=1; j<capacity; j++) if(frames[j].last_used < frames[lru_idx].last_used) lru_idx = j;
            frames[lru_idx].id = pages[i];
            frames[lru_idx].last_used = i;
            faults++;
            printf("Acesso %d: FAULT\n", pages[i]);
        } else printf("Acesso %d: HIT\n", pages[i]);
    }
    printf("Total Page Faults LRU: %d (%.2f%%)\n", faults, (float)faults/n*100);
}

// --- 3. ALGORITMO DO RELÓGIO (Aproximação Linux) ---
void runLinuxClock(int pages[], bool writes[], int n, int capacity) {
    PageFrame frames[capacity];
    for (int i = 0; i < capacity; i++) {
        frames[i].id = -1;
        frames[i].ref_bit = 0;
        frames[i].dirty = false;
    }

    int faults = 0, clock_ptr = 0, swap_writes = 0;

    printf("\n--- Execução CLOCK (Aproximação Linux) ---\n");
    for (int i = 0; i < n; i++) {
        bool hit = false;
        for (int j = 0; j < capacity; j++) {
            if (frames[j].id == pages[i]) {
                frames[j].ref_bit = 1; 
                if (writes[i]) frames[j].dirty = true;
                hit = true;
                break;
            }
        }

        if (!hit) {
            faults++;
            while (true) {
                if (frames[clock_ptr].id == -1) break;
                if (frames[clock_ptr].ref_bit == 1) {
                    frames[clock_ptr].ref_bit = 0;
                    clock_ptr = (clock_ptr + 1) % capacity;
                } else {
                    if (frames[clock_ptr].dirty) swap_writes++; 
                    break;
                }
            }
            frames[clock_ptr].id = pages[i];
            frames[clock_ptr].ref_bit = 1;
            frames[clock_ptr].dirty = writes[i];
            
            printf("Acesso %d (%s): ", pages[i], writes[i] ? "Escrita" : "Leitura");
            print_frames(frames, capacity);
            printf(" -> FAULT\n");
            clock_ptr = (clock_ptr + 1) % capacity;
        } else {
            printf("Acesso %d (%s): HIT\n", pages[i], writes[i] ? "Escrita" : "Leitura");
        }
    }
    printf("Total Page Faults CLOCK: %d (%.2f%%) | Swaps: %d\n", faults, (float)faults/n*100, swap_writes);
}

int main() {
    int capacity, n;
    srand(time(NULL)); // Inicializa o gerador aleatório

    printf("=== Simulador de Memória Dinâmico ===\n");
    printf("Digite a quantidade de frames: ");
    scanf("%d", &capacity);
    printf("Digite a quantidade de acessos (ex: 20): ");
    scanf("%d", &n);

    int *pages = malloc(n * sizeof(int));
    bool *writes = malloc(n * sizeof(bool));

    printf("\nSequência Gerada Aleatoriamente:\n");
    for(int i = 0; i < n; i++) {
        pages[i] = rand() % 10;      // IDs de página de 0 a 9
        writes[i] = rand() % 2;     // 0 para Leitura, 1 para Escrita
        printf("%d(%s) ", pages[i], writes[i] ? "W" : "R");
    }
    printf("\n");

    // Executa os 3 algoritmos para comparação
    runFIFO(pages, n, capacity);
    runLRU(pages, n, capacity);
    runLinuxClock(pages, writes, n, capacity);

    free(pages);
    free(writes);
    return 0;
}