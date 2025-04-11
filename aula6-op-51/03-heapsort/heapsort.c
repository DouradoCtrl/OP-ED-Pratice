#include <stdio.h>
#include "heapsort.h"

// Funcao para reorganizar o heap (Heapify)
void heapify(int arr[], int n, int i) {
    int largest = i;     // Inicializa o maior como raiz
    int left = 2 * i + 1; // Filho esquerdo
    int right = 2 * i + 2; // Filho direito

    // Se o filho esquerdo for maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho direito for maior que o maior elemento atual
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior nao for a raiz
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursivamente reorganiza o sub-arvore afetado
        heapify(arr, n, largest);
    }
}

// Funcao principal do Heapsort
void heapSort(int arr[], int n) {
    // Construcao do heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai um a um os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama heapify no heap reduzido
        heapify(arr, i, 0);
    }
}
