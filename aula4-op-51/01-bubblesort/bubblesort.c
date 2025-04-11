#include "bubblesort.h"

// Função para gerar um array com 10 números aleatórios
void gerarArrayAleatorioBubbleSort(int arr[], int n) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Gera um número aleatório entre 0 e 99
    }
}

// Função Bubble Sort para ordenar um array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Percorre todo o array
        for (int j = 0; j < n - i - 1; j++) { // Percorre os elementos não ordenados
            if (arr[j] > arr[j + 1]) { // Se o elemento atual for maior que o próximo, troca
                int temp = arr[j]; // Armazena temporariamente o valor de arr[j]
                arr[j] = arr[j + 1]; // Move arr[j+1] para arr[j]
                arr[j + 1] = temp; // Coloca o valor temporário na posição arr[j+1]
            }
        }
    }
}

// Função para imprimir os elementos de um array
void imprimirArrayBubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Percorre todos os elementos do array
        printf("%d ", arr[i]); // Imprime cada elemento
    }
    printf("\n"); // Nova linha após imprimir o array
}

// Função principal
int principalBubbleSort() {
    int n = 10; // Define o tamanho do array como 10
    int arr[n]; // Declara um array de tamanho 10

    printf("Gerando lista de numeros aleatorios...\n");
    gerarArrayAleatorioBubbleSort(arr, n); // Chama a função para gerar números aleatórios

    printf("\nArray antes da ordenacao: ");
    imprimirArrayBubbleSort(arr, n); // Exibe o array antes da ordenação

    bubbleSort(arr, n); // Chama a função Bubble Sort para ordenar o array

    printf("Array apos a ordenacao: ");
    imprimirArrayBubbleSort(arr, n); // Exibe o array após a ordenação

    return 0; // Finaliza o programa
}
