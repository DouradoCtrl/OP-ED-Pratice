#include "shell-insertionsort.h"


#define TAMANHO 10000  // Define o tamanho do vetor para os testes

// Função auxiliar para copiar os elementos de um vetor para outro
void copiarVetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Implementação do algoritmo ShellSort
int shellSortC(int vetor[], int tamanho) {
    int i, j, valor;
    int gap = 1;         // Distância entre os elementos comparados
    int iteracoes = 0;   // Contador de comparações/movimentações

    // Define o maior valor inicial de gap com base na fórmula 3*gap + 1
    do {
        gap = 3 * gap + 1;
    } while (gap < tamanho);

    // Ordenação com gaps decrescentes até gap = 1
    do {
        gap /= 3;
        for (i = gap; i < tamanho; i++) {
            valor = vetor[i];     // Armazena o valor atual
            j = i - gap;

            // Desloca os elementos maiores para frente
            while (j >= 0 && valor < vetor[j]) {
                vetor[j + gap] = vetor[j];
                j -= gap;
                iteracoes++;      // Contabiliza a movimentação
            }

            vetor[j + gap] = valor;  // Insere o valor na posição correta
        }
    } while (gap > 1);

    return iteracoes;  // Retorna o total de movimentações/comparações
}

// Implementação do algoritmo InsertionSort
int insertionSort(int vetor[], int tamanho) {
    int i, j, temp;
    int iteracoes = 0;  // Contador de movimentações

    for (i = 1; i < tamanho; i++) {
        temp = vetor[i];  // Valor atual
        j = i;

        // Move os valores maiores para frente
        while ((j > 0) && (temp < vetor[j - 1])) {
            vetor[j] = vetor[j - 1];
            j--;
            iteracoes++;  // Conta a movimentação
        }

        vetor[j] = temp;  // Insere o valor na posição correta
    }

    return iteracoes;  // Retorna o total de movimentações/comparações
}

int shellInsertionSortPrincipal() {
    int original[TAMANHO];         // Vetor original (aleatório)
    int vetorShell[TAMANHO];       // Vetor para ShellSort
    int vetorInsertion[TAMANHO];   // Vetor para InsertionSort
    int i;

    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    // Preenche o vetor com valores aleatórios entre 0 e 9999
    for (i = 0; i < TAMANHO; i++) {
        original[i] = rand() % 10000;
    }

    // Copia o vetor original para cada algoritmo
    copiarVetor(original, vetorShell, TAMANHO);
    copiarVetor(original, vetorInsertion, TAMANHO);

    clock_t start, end;  // Variáveis para medição de tempo

    // Medição de tempo e execução do ShellSort
    start = clock();
    int iterShell = shellSortC(vetorShell, TAMANHO);
    end = clock();
    double tempoShell = (double)(end - start) / CLOCKS_PER_SEC;

    // Medição de tempo e execução do InsertionSort
    start = clock();
    int iterInsertion = insertionSort(vetorInsertion, TAMANHO);
    end = clock();
    double tempoInsertion = (double)(end - start) / CLOCKS_PER_SEC;

    // Impressão dos resultados
    printf("ShellSort:\n");
    printf("Tempo de execucao: %.4f segundos\n", tempoShell);
    printf("Iteracoes: %d\n\n", iterShell);

    printf("InsertionSort:\n");
    printf("Tempo de execucao: %.4f segundos\n", tempoInsertion);
    printf("Iteracoes: %d\n", iterInsertion);

    return 0;  // Fim do programa
}
