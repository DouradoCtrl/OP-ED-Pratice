#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "01-mergesort/mergesort.h"
#include "02-quicksort/quicksort.h"
#include "03-heapsort/heapsort.h"

// Define o tamanho maximo do array para 100.000 elementos
#define MAX 100000

int main() {
    int opcao, imp, n, arr[MAX], original[MAX];
    clock_t start, end; // Variaveis para medir o tempo de execucao
    double time_taken;
    imp = 0;

    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios usando o tempo atual

    while (1) {

        // Exibe o menu de escolha do algoritmo de ordenacao
        printf("\nEscolha o algoritmo de ordenacao:\n");
        printf("1. Criar novo array aleatorio\n");
        printf("2. Criar array no pior caso (decrescente)\n");
        printf("3. Mergesort\n");
        printf("4. Quicksort\n");
        printf("5. Heapsort\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 0) break; // Sai do programa se o usuario escolher 0

        if (opcao == 1 || opcao == 2) {
            // Solicita o numero de elementos ao usuario
            printf("\nDigite o numero de elementos (max %d): ", MAX);
            scanf("%d", &n);

            // Valida se o numero de elementos e valido
            if (n > MAX || n <= 0) {
                printf("Numero invalido! Tente novamente.\n");
                continue;
            }

            if (opcao == 1) {
                // Gera um array aleatorio de 'n' elementos
                for (int i = 0; i < n; i++) {
                    original[i] = rand() % 1000; // Numeros aleatorios entre 0 e 999
                }
                imp = 0;
                printf("\nNovo array gerado com sucesso!\n");
                printArray(original, n); // Exibe o array gerado
            } else if (opcao == 2) {
                // Gera um array no pior caso (decrescente)
                for (int i = 0; i < n; i++) {
                    original[i] = n - i; // Ex.: 10, 9, 8, ..., 1
                }
                printf("\nArray no pior caso (decrescente) gerado com sucesso!\n");
                imp = 1;
                // Nenhum elemento e impresso na tela neste caso.
            }
        } else if (opcao >= 3 && opcao <= 5) {
            // Copia o array original para o array atual para nao perder os dados iniciais
            for (int i = 0; i < n; i++) {
                arr[i] = original[i];
            }

            // Medir o tempo de execucao do algoritmo escolhido
            start = clock(); // Inicia a contagem do tempo

            if (opcao == 3) {
                printf("\nOrdenando com Mergesort...\n");
                mergeSort(arr, 0, n - 1); // Chama a funcao de ordenacao Mergesort
            } else if (opcao == 4) {
                printf("\nOrdenando com Quicksort...\n");
                quickSort(arr, 0, n - 1); // Chama a funcao de ordenacao Quicksort
            } else if (opcao == 5) {
                printf("\nOrdenando com Heapsort...\n");
                heapSort(arr, n); // Chama a funcao de ordenacao Heapsort
            }

            end = clock(); // Termina a contagem do tempo
            if (imp == 0) {
                printf("\nArray ordenado: ");
                printArray(arr, n); // Exibe o array apos a ordenacao
            }

            // Calcula o tempo de execucao em segundos
            time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Tempo de execucao: %.6f segundos\n", time_taken);
        } else {
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    }

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
