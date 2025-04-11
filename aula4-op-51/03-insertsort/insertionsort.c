#include "insertionsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um array com 10 números aleatórios
void gerarArrayAleatorioInsertionSort(int arr[], int n) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Gera um número aleatório entre 0 e 99
    }
}

// Função Insertion Sort para ordenar um array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // Percorre o array a partir do segundo elemento
        int key = arr[i]; // Elemento a ser inserido na posição correta
        int j = i - 1;

        // Move os elementos maiores que key para a direita
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Insere key na posição correta
    }
}

// Função para imprimir os elementos de um array
void imprimirArrayInsertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Percorre todos os elementos do array
        printf("%d ", arr[i]); // Imprime cada elemento
    }
    printf("\n"); // Nova linha após imprimir o array
}

// Função principal
int principalInsertionSort() {
    int n = 10; // Define o tamanho do array como 10
    int arr[n]; // Declara um array de tamanho 10

    printf("Gerando lista de numeros aleatorios...\n");
    gerarArrayAleatorioInsertionSort(arr, n); // Chama a função para gerar números aleatórios

    printf("\nArray antes da ordenacao: ");
    imprimirArrayInsertionSort(arr, n); // Exibe o array antes da ordenação

    insertionSort(arr, n); // Chama a função Insertion Sort para ordenar o array

    printf("Array apos a ordenacao: ");
    imprimirArrayInsertionSort(arr, n); // Exibe o array após a ordenação

    return 0; // Finaliza o programa
}
