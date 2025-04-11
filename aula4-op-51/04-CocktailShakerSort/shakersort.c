#include "shakersort.h"

// Função para gerar um array com 10 números aleatórios
void gerarArrayAleatorioShakerSort(int arr[], int n) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Gera um número aleatório entre 0 e 99
    }
}

// Função Cocktail Shaker Sort para ordenar um array
void cocktailShakerSort(int arr[], int n) {
    int trocado = 1; // Variável para verificar se houve trocas
    int inicio = 0, fim = n - 1; // Define os limites do array

    while (trocado) {
        trocado = 0;

        // Percorre da esquerda para a direita (igual ao Bubble Sort)
        for (int i = inicio; i < fim; i++) {
            if (arr[i] > arr[i + 1]) { // Se o elemento atual for maior que o próximo, troca
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocado = 1;
            }
        }

        // Se não houve trocas, a lista já está ordenada
        if (!trocado) break;

        fim--; // Reduz o limite superior, pois o maior já está na posição correta
        trocado = 0;

        // Percorre da direita para a esquerda (diferença em relação ao Bubble Sort)
        for (int i = fim - 1; i >= inicio; i--) {
            if (arr[i] > arr[i + 1]) { // Se um elemento for maior que o próximo, troca
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocado = 1;
            }
        }

        inicio++; // Aumenta o limite inferior, pois o menor já está na posição correta
    }
}

// Função para imprimir os elementos de um array
void imprimirArrayShakerSort(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Percorre todos os elementos do array
        printf("%d ", arr[i]); // Imprime cada elemento
    }
    printf("\n"); // Nova linha após imprimir o array
}

// Função principal
int principalShakerSort() {
    int n = 10; // Define o tamanho do array como 10
    int arr[n]; // Declara um array de tamanho 10

    printf("Gerando lista de numeros aleatorios...\n");
    gerarArrayAleatorioShakerSort(arr, n); // Gera números aleatórios

    printf("\nArray antes da ordenacao: ");
    imprimirArrayShakerSort(arr, n); // Exibe o array antes da ordenação

    cocktailShakerSort(arr, n); // Chama a função Cocktail Shaker Sort para ordenar

    printf("Array apos a ordenacao: ");
    imprimirArrayShakerSort(arr, n); // Exibe o array após a ordenação

    return 0; // Finaliza o programa
}
