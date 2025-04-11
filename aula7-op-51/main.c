#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "01-busca-sequencial/busca-sequencial.h"
#include "02-busca-indexada/busca-indexada.h"
#include "03-busca-binaria/busca-binaria.h"
#include "04-busca-binaria-palavras-manual/busca-binaria-palavras-manual.h"
#include "05-busca-binaria-palavras-funcoes/busca-binaria-palavras-funcoes.h"

// Gera vetor em ordem decrescente com números aleatórios
void preencherVetorDecrescente(int vetor[], int tamanho) {
    // Gera um array no pior caso (decrescente)
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i; // Ex.: 10, 9, 8, ..., 1
    }
}

// Imprime o vetor
void imprimirVetor(int vetor[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("]\n");
}

// Ordena vetor crescente (para busca binária tradicional)
void ordenarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int main() {
    int *vetor = NULL;
    int tamanho = 0, valor, posicao, opcao;

    srand(time(NULL));

    do {
        printf("\n===== MENU DE BUSCA =====\n");
        printf("1 - Busca Sequencial\n");
        printf("2 - Busca Sequencial Indexada\n");
        printf("3 - Busca Binaria\n");
        printf("4 - Busca Binaria Palavras Manual\n");
        printf("5 - Busca Binaria Palavras Funcoes\n");
        printf("6 - Gerar novo vetor decrescente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        if (opcao == 6) {
            printf("Digite a quantidade de elementos a gerar: ");
            scanf("%d", &tamanho);

            free(vetor); // Libera vetor anterior, se existir
            vetor = malloc(tamanho * sizeof(int));

            if (!vetor) {
                printf("Erro de alocacao!\n");
                return 1;
            }

            preencherVetorDecrescente(vetor, tamanho);
            printf("Vetor gerado (decrescente): ");
           // imprimirVetor(vetor, tamanho);
            continue; // Volta ao menu principal
        }

        // Impede execução se vetor ainda não foi gerado
        if (vetor == NULL) {
            printf("Você precisa gerar um vetor primeiro! Use a opção 6.\n");
            continue;
        }

        if (opcao >= 1 && opcao <= 3) {
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
        }

        if (opcao == 3) ordenarVetor(vetor, tamanho); // Binária exige vetor ordenado

        switch (opcao) {
            case 1:
                posicao = buscaSequencial(vetor, tamanho, valor);
                break;
            case 2:
                posicao = buscaSequencialIndexada(vetor, tamanho, valor);
                break;
            case 3:
                posicao = buscaBinaria(vetor, 0, tamanho - 1, valor);
                break;
            case 4:
                posicao = busca_binaria_palavras_manual();
                break;
            case 5:
                posicao = busca_binaria_palavras_funcoes();
                break;
            default:
                printf("Opcao invalida!\n");
                continue;
        }

        if (opcao >= 1 && opcao <= 3) {
            if (posicao != -1) {
                printf("Valor encontrado na posicao %d\n", posicao);
            } else {
                printf("Valor NAO encontrado.\n");
            }
        }

    } while (opcao != 0);

    free(vetor);
    printf("Encerrando...\n");
    return 0;
}
