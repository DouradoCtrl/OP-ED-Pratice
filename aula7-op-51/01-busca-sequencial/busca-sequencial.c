#include <stdio.h>      // Biblioteca padrão para entrada e saída
#include <time.h>       // Biblioteca usada para medir o tempo de execução
#include "busca-sequencial.h"  // Inclusão do cabeçalho da função

/**
 * Função auxiliar para mesclar dois subvetores ordenados em um único vetor.
 */
void merge(int vetor[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;  // Tamanho do subvetor esquerdo
    int n2 = direita - meio;       // Tamanho do subvetor direito

    int L[n1], R[n2];              // Subvetores temporários

    // Copia os dados para os subvetores
    for (int i = 0; i < n1; i++)
        L[i] = vetor[esquerda + i];
    for (int j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;

    // Intercala os elementos dos dois subvetores
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[]
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[]
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Função de ordenação usando MergeSort.
 * Ordena o vetor em ordem crescente.
 */
void mergeSort(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena recursivamente as duas metades
        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);

        // Mescla as duas metades ordenadas
        merge(vetor, esquerda, meio, direita);
    }
}

/**
 * Função que realiza a busca sequencial em um vetor de inteiros.
 * Retorna o índice do valor encontrado, ou -1 se o valor não estiver presente.
 * Também imprime o tempo gasto na operação em milissegundos.
 */
int buscaSequencial(int vetor[], int tamanho, int valorBuscado) {
    clock_t inicio, fim;
    double tempoMs;

    inicio = clock(); // Marca o tempo inicial

    mergeSort(vetor, 0, tamanho - 1); // Ordena o vetor (opcional na busca sequencial)

    // Percorre o vetor do início ao fim
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valorBuscado) {
            fim = clock(); // Marca o tempo final
            tempoMs = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;
            printf("Tempo gasto: %.3f ms\n", tempoMs);
            return i; // Retorna o índice onde o valor foi encontrado
        }
    }

    fim = clock(); // Marca o tempo final mesmo se não encontrar
    tempoMs = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;
    printf("Tempo gasto: %.3f ms\n", tempoMs);

    return -1; // Valor não encontrado
}
