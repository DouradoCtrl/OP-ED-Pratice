#include <stdio.h>          // Para entrada e saída
#include <time.h>           // Para medir tempo
#include <stdlib.h>         // Para malloc e free
#include "busca-binaria.h"  // Header com a assinatura da função

/**
 * Função auxiliar para manter a propriedade de heap máximo.
 */
void heapify(int vetor[], int tamanho, int i) {
    int maior = i;                // Assume que o maior elemento está na raiz
    int esquerda = 2 * i + 1;     // Índice do filho à esquerda
    int direita = 2 * i + 2;      // Índice do filho à direita

    // Verifica se o filho à esquerda é maior que o pai
    if (esquerda < tamanho && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    // Verifica se o filho à direita é maior que o maior até agora
    if (direita < tamanho && vetor[direita] > vetor[maior])
        maior = direita;

    // Se o maior não for o pai, faz a troca e chama heapify recursivamente
    if (maior != i) {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;
        heapify(vetor, tamanho, maior);
    }
}

/**
 * Função de ordenação HeapSort.
 * Ordena o vetor em ordem crescente.
 */
void heapSort(int vetor[], int tamanho) {
    // Constrói o heap máximo
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(vetor, tamanho, i);

    // Extrai os elementos do heap um por um e reconstrói o heap
    for (int i = tamanho - 1; i >= 0; i--) {
        // Move o maior elemento para o final
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        // Reaplica o heapify no heap reduzido
        heapify(vetor, i, 0);
    }
}

/**
 * Função de busca binária com cópia do vetor original.
 * O vetor é copiado, ordenado com HeapSort e a busca é feita na cópia.
 * Retorna o índice na cópia ordenada (não no vetor original).
 * Exibe o tempo de execução da busca em milissegundos.
 */
int buscaBinaria(int vetor[], int inicio, int fim, int valorBuscado) {
    clock_t tempoInicio, tempoFim;     // Variáveis para marcar o tempo
    double tempoMs;                    // Variável para armazenar o tempo em milissegundos

    int tamanho = fim - inicio + 1;    // Calcula o tamanho real do vetor

    // Aloca memória para a cópia do vetor original
    int *copia = malloc(tamanho * sizeof(int));
    if (!copia) {
        printf("Erro de alocação de memória.\n");
        return -1;
    }

    // Copia os valores do vetor original para a cópia
    for (int i = 0; i < tamanho; i++) {
        copia[i] = vetor[i];
    }

    // Ordena a cópia usando HeapSort
    heapSort(copia, tamanho);

    tempoInicio = clock();  // Marca o início da busca binária

    int ini = 0;
    int fim_copia = tamanho - 1;

    // Realiza a busca binária
    while (ini <= fim_copia) {
        int meio = (ini + fim_copia) / 2;

        if (copia[meio] == valorBuscado) {
            tempoFim = clock(); // Marca o fim da busca
            tempoMs = (double)(tempoFim - tempoInicio) / CLOCKS_PER_SEC * 1000.0;
            printf("Tempo gasto: %.3f ms\n", tempoMs);
            free(copia); // Libera a memória
            return meio; // Retorna o índice encontrado
        }

        if (valorBuscado < copia[meio]) {
            fim_copia = meio - 1; // Busca na metade inferior
        } else {
            ini = meio + 1;       // Busca na metade superior
        }
    }

    tempoFim = clock(); // Marca o fim mesmo se não encontrar
    tempoMs = (double)(tempoFim - tempoInicio) / CLOCKS_PER_SEC * 1000.0;
    printf("Tempo gasto: %.3f ms\n", tempoMs);

    free(copia); // Libera a memória
    return -1;   // Valor não encontrado
}
