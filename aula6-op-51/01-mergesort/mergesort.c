#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que realiza a mesclagem (merge) de dois subarrays ordenados
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // Tamanho do primeiro subarray
    int n2 = right - mid;    // Tamanho do segundo subarray

    // Aloca memoria para os arrays temporarios L e R
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copia os dados para os arrays temporarios L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Reorganiza os arrays mesclando-os de forma ordenada
    i = 0; // Indice inicial do primeiro subarray (L)
    j = 0; // Indice inicial do segundo subarray (R)
    k = left; // Indice inicial do array mesclado

    // Junta os arrays L e R ordenadamente no array original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {  // Se o elemento de L for menor ou igual, adiciona-o ao array principal
            arr[k] = L[i];
            i++;
        } else {  // Caso contrario, adiciona o elemento de R
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Libera a memoria alocada para L e R
    free(L);
    free(R);
}

// Funcao principal do algoritmo Mergesort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {  // Condicao de parada da recursao
        int mid = left + (right - left) / 2;  // Calcula o ponto medio do array

        // Ordena recursivamente as duas metades do array
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla os arrays ordenados
        merge(arr, left, mid, right);
    }
}

// Funcao para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
