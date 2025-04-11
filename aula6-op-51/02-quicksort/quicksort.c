#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

// Funcao auxiliar para trocar dois elementos de lugar
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcao que realiza a particao do array e retorna o indice do pivo
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolhe o ultimo elemento como pivo
    int i = (low - 1);  // Indice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;  // Incrementa o indice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Funcao principal do Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array e obtem o indice do pivo
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois da particao
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
