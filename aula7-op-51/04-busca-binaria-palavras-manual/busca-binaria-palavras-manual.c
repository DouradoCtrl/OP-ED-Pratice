#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TAM 10     // Número de palavras
#define MAX_LEN 50 // Tamanho máximo de cada palavra

// Função para obter a posição de uma letra no alfabeto (a=0, b=1, ..., z=25)
int posicaoLetra(char letra) {
    letra = tolower(letra); // converte para minúscula
    return letra - 'a';
}

// Função de comparação manual entre duas palavras
int compararPalavras(char palavra1[], char palavra2[]) {
    int i = 0;

    while (palavra1[i] != '\0' && palavra2[i] != '\0') {
        int pos1 = posicaoLetra(palavra1[i]);
        int pos2 = posicaoLetra(palavra2[i]);

        if (pos1 < pos2) return -1; // palavra1 vem antes
        if (pos1 > pos2) return 1;  // palavra2 vem antes

        i++;
    }

    // Se chegamos ao fim de uma das palavras
    if (palavra1[i] == '\0' && palavra2[i] == '\0') return 0;  // Iguais
    if (palavra1[i] == '\0') return -1; // palavra1 é menor (ex: "casa" vs "casal")
    return 1;                           // palavra2 é menor
}

// Função para ordenar as palavras manualmente com Bubble Sort
void ordenarPalavrasManual(char vetor[][MAX_LEN], int tamanho) {
    char temp[MAX_LEN];

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (compararPalavras(vetor[j], vetor[j + 1]) > 0) {
                // Troca as palavras
                strcpy(temp, vetor[j]);
                strcpy(vetor[j], vetor[j + 1]);
                strcpy(vetor[j + 1], temp);
            }
        }
    }
}

// Função de busca binária (usa comparação manual)
int buscaBinariaPalavras(char vetor[][MAX_LEN], int tamanho, char palavraBuscada[]) {
    int inicio = 0, fim = tamanho - 1;
    clock_t tempoInicio = clock();

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = compararPalavras(palavraBuscada, vetor[meio]);

        if (cmp == 0) {
            clock_t tempoFim = clock();
            double tempoGasto = (double)(tempoFim - tempoInicio) / CLOCKS_PER_SEC;
            printf("Tempo gasto: %.6f segundos\n", tempoGasto);
            return meio;
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    clock_t tempoFim = clock();
    double tempoGasto = (double)(tempoFim - tempoInicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %.6f segundos\n", tempoGasto);
    return -1;
}

int busca_binaria_palavras_manual() {
    char palavras[TAM][MAX_LEN] = {
        "banana", "uva", "abacate", "laranja", "goiaba",
        "melancia", "abacaxi", "figo", "caju", "morango"
    };

    char palavraBuscada[MAX_LEN];

    printf("Palavras antes da ordenacao:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%s\n", palavras[i]);
    }

    ordenarPalavrasManual(palavras, TAM); // Ordenação manual

    printf("\nPalavras apos a ordenacao manual:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%s\n", palavras[i]);
    }

    printf("\nDigite a palavra a ser buscada: ");
    scanf("%s", palavraBuscada);

    int posicao = buscaBinariaPalavras(palavras, TAM, palavraBuscada);

    if (posicao != -1) {
        printf("Palavra encontrada na posicao %d\n", posicao);
    } else {
        printf("Palavra NAO encontrada.\n");
    }

    return 0;
}
