#include <stdio.h>
#include "01-bubblesort/bubblesort.h"
#include "02-selectionsort/selectionsort.h"
#include "03-insertsort/insertionsort.h"
#include "04-CocktailShakerSort/shakersort.h"

void exibirMenu() {
    printf("\n=== MENU DE ORDENACAO ===\n");
    printf("1 - Executar Bubble Sort\n");
    printf("2 - Executar Selection Sort\n");
    printf("3 - Executar Insertion Sort\n");
    printf("4 - Executar Cocktail Shaker Sort\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main(void) {
    int opcao;

    do {
        exibirMenu(); // Exibe o menu para o usuário
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nExecutando Bubble Sort...\n");
            principalBubbleSort(); // Chama a função do Bubble Sort
            break;
            case 2:
                printf("\nExecutando Selection Sort...\n");
            principalSelectionSort(); // Chama a função do Selection Sort
            break;
            case 3:
                printf("\nExecutando Insertion Sort...\n");
            principalInsertionSort(); // Chama a função do Insertion Sort
            break;
            case 4:
                printf("\nExecutando Cocktail Shaker Sort...\n");
            principalShakerSort(); // Chama a função do Cocktail Shaker Sort
            break;
            case 0:
                printf("\nSaindo do programa...\n");
            break;
            default:
                printf("\nOpcao invalida! Escolha novamente.\n");
        }
    } while (opcao != 0); // Continua até que o usuário escolha sair

    return 0;
}
