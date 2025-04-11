#include "selectionsort.h"

// Função para gerar um array com 10 números aleatórios
void gerarArrayAleatorioSelectionSort(int arr[], int n) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Gera um número aleatório entre 0 e 99
    }
}

// Função Selection Sort para ordenar um array
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Percorre todo o array
        int minIndex = i; // Assume que o menor elemento está na posição i

        for (int j = i + 1; j < n; j++) {
            // Percorre os elementos à direita de i
            if (arr[j] < arr[minIndex]) {
                // Se encontrar um elemento menor, atualiza minIndex
                minIndex = j;
            }
        }

        // Troca arr[i] com o menor elemento encontrado
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Função para imprimir os elementos de um array
void imprimirArraySelectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        // Percorre todos os elementos do array
        printf("%d ", arr[i]); // Imprime cada elemento
    }
    printf("\n"); // Nova linha após imprimir o array
}

// Função principal
int principalSelectionSort() {
    int n = 10; // Define o tamanho do array como 10
    int arr[n]; // Declara um array de tamanho 10

    printf("Gerando lista de numeros aleatorios...\n");
    gerarArrayAleatorioSelectionSort(arr, n); // Chama a função para gerar números aleatórios

    printf("\nArray antes da ordenacao: ");
    imprimirArraySelectionSort(arr, n); // Exibe o array antes da ordenação

    selectionSort(arr, n); // Chama a função Selection Sort para ordenar o array

    printf("Array apos a ordenacao: ");
    imprimirArraySelectionSort(arr, n); // Exibe o array após a ordenação

    return 0; // Finaliza o programa
}
