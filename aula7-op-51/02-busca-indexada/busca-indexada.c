#include "busca-indexada.h"  // Header da função
#include <stdio.h>           // Biblioteca padrão para entrada e saída
#include <time.h>            // Biblioteca usada para medir o tempo de execução

/**
 * Função auxiliar para mesclar dois subvetores ordenados em um único vetor.
 */
void mergeIndexada(int vetor[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;     // Tamanho do subvetor esquerdo
    int n2 = direita - meio;          // Tamanho do subvetor direito

    int L[n1], R[n2];                 // Subvetores temporários

    // Copia os dados para o subvetor esquerdo
    for (int i = 0; i < n1; i++)
        L[i] = vetor[esquerda + i];

    // Copia os dados para o subvetor direito
    for (int j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;   // Índices para percorrer L, R e o vetor original

    // Mescla os elementos de L e R em ordem crescente
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

    // Copia os elementos restantes de L (se houver)
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R (se houver)
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
void mergeSortIndexada(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;  // Calcula o ponto do meio

        // Ordena recursivamente a metade esquerda
        mergeSortIndexada(vetor, esquerda, meio);

        // Ordena recursivamente a metade direita
        mergeSortIndexada(vetor, meio + 1, direita);

        // Mescla as duas metades ordenadas
        mergeIndexada(vetor, esquerda, meio, direita);
    }
}

/**
 * Função de busca sequencial indexada com medição de tempo em milissegundos.
 * Retorna o índice do valor encontrado ou -1 se não encontrado.
 */
int buscaSequencialIndexada(int vetor[], int tamanho, int valorBuscado) {
    clock_t inicio, fim;            // Variáveis para medir o tempo
    double tempoMs;                 // Tempo total em milissegundos

    inicio = clock();               // Inicia a contagem do tempo

    // Etapa 0: ordena o vetor antes de iniciar a busca
    mergeSortIndexada(vetor, 0, tamanho - 1);

    int bloco = 4;                  // Define o tamanho dos blocos
    int index[100];                // Vetor auxiliar para armazenar os índices dos blocos
    int pos = 0;                    // Quantidade de blocos (posição atual no índice)

    // Etapa 1: cria os índices que apontam para o início de cada bloco
    for (int i = 0; i < tamanho; i += bloco) {
        index[pos++] = i;
    }

    int blocoSelecionado = -1;     // Armazena o bloco onde possivelmente está o valor

    // Etapa 2: identifica qual bloco pode conter o valor buscado
    for (int i = 0; i < pos; i++) {
        int inicioBloco = index[i];
        int fimBloco = (i + 1 < pos) ? index[i + 1] : tamanho;

        // Verifica se o valor buscado está dentro do intervalo do bloco
        if (valorBuscado >= vetor[inicioBloco] && valorBuscado <= vetor[fimBloco - 1]) {
            blocoSelecionado = i; // Armazena o índice do bloco
            break;                // Sai do laço pois encontrou o bloco
        }
    }

    // Etapa 3: realiza busca sequencial dentro do bloco selecionado
    if (blocoSelecionado != -1) {
        int inicioBloco = index[blocoSelecionado];
        int fimBloco = (blocoSelecionado + 1 < pos) ? index[blocoSelecionado + 1] : tamanho;

        for (int i = inicioBloco; i < fimBloco; i++) {
            if (vetor[i] == valorBuscado) {
                fim = clock(); // Marca o tempo de fim se encontrou
                tempoMs = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;
                printf("Tempo gasto: %.3f ms\n", tempoMs);
                return i;       // Retorna o índice do valor encontrado
            }
        }
    }

    fim = clock(); // Marca o tempo de fim mesmo se não encontrou
    tempoMs = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;
    printf("Tempo gasto: %.3f ms\n", tempoMs);

    return -1; // Valor não encontrado no vetor
}
