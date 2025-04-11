#include "busca-binaria-palavras-funcoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10     // Tamanho do vetor de palavras
#define MAX_LEN 50 // Tamanho máximo de cada palavra

// Função para ordenar o vetor de palavras (Bubble Sort)
void ordenarPalavrasFuncao(char vetor[][MAX_LEN], int tamanho) {
    char temp[MAX_LEN];
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (strcmp(vetor[j], vetor[j + 1]) > 0) {
                // Troca as palavras de posição
                strcpy(temp, vetor[j]);
                strcpy(vetor[j], vetor[j + 1]);
                strcpy(vetor[j + 1], temp);
            }
        }
    }
}

// Função de busca binária em vetor de strings ordenado
int buscaBinariaPalavrasFuncao(char vetor[][MAX_LEN], int tamanho, char palavraBuscada[]) {
    int inicio = 0, fim = tamanho - 1;
    clock_t tempoInicio = clock();

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(palavraBuscada, vetor[meio]);

        if (cmp == 0) {
            clock_t tempoFim = clock();
            double tempoGasto = (double)(tempoFim - tempoInicio) / CLOCKS_PER_SEC;
            printf("Tempo gasto: %.6f segundos\n", tempoGasto);
            return meio; // Palavra encontrada
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    clock_t tempoFim = clock();
    double tempoGasto = (double)(tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %.6f segundos\n", tempoGasto);
    return -1; // Palavra não encontrada
}

int busca_binaria_palavras_funcoes() {
    // Vetor com palavras não ordenadas
    char palavras[TAM][MAX_LEN] = {
        "banana", "uva", "abacate", "laranja", "goiaba",
        "melancia", "abacaxi", "figo", "caju", "morango"
    };

    char palavraBuscada[MAX_LEN];

    printf("Palavras antes da ordenacao:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%s\n", palavras[i]);
    }

    // Ordena o vetor de palavras
    ordenarPalavrasFuncao(palavras, TAM);

    printf("\nPalavras apos a ordenacao:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%s\n", palavras[i]);
    }

    // Solicita a palavra ao usuário
    printf("\nDigite a palavra a ser buscada: ");
    scanf("%s", palavraBuscada);

    // Chama a busca binária
    int posicao = buscaBinariaPalavrasFuncao(palavras, TAM, palavraBuscada);

    if (posicao != -1) {
        printf("Palavra encontrada na posicao %d\n", posicao);
    } else {
        printf("Palavra NAO encontrada no vetor.\n");
    }

    return 0;
}
