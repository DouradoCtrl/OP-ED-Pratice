#include "barras.h"


#define TAMANHO 10

// Função para imprimir o vetor como barras
void imprimirBarras(int vetor[], int tamanho, const char *titulo) {
    printf("\n%s\n", titulo);
    for (int i = 0; i < tamanho; i++) {
        printf("%2d: ", vetor[i]);
        for (int j = 0; j < vetor[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}

// Função ShellSort com exibição passo a passo
void shellSortComBarras(int vetor[], int tamanho) {
    int i, j, valor, gap = 1;

    // Define o maior gap inicial (Knuth: 3 * gap + 1)
    do {
        gap = 3 * gap + 1;
    } while (gap < tamanho);

    // Aplica o ShellSort
    do {
        gap /= 3;
        printf("\n>>> GAP = %d\n", gap);

        for (i = gap; i < tamanho; i++) {
            valor = vetor[i];
            j = i;

            while (j >= gap && vetor[j - gap] > valor) {
                vetor[j] = vetor[j - gap];
                j -= gap;
            }

            vetor[j] = valor;

            // Mostra o vetor após cada inserção
            char titulo[50];
            sprintf(titulo, "Passo (gap=%d, i=%d):", gap, i);
            imprimirBarras(vetor, tamanho, titulo);
        }
    } while (gap > 1);
}

int barrasPrincipal() {
    int vetor[TAMANHO];

    srand(time(NULL));

    // Preenche vetor com valores aleatórios entre 1 e 20
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = (rand() % 20) + 1;
    }

    imprimirBarras(vetor, TAMANHO, "Vetor Original:");

    shellSortComBarras(vetor, TAMANHO);

    imprimirBarras(vetor, TAMANHO, "Vetor Ordenado:");
    return 0;
}
