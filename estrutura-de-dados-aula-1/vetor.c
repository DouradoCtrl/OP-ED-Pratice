#include <stdio.h>

#define TAMANHO_VETOR 5 // Tamanho do vetor

int vetor() {
    printf("Iniciando Vetor\n");
    int vetor[TAMANHO_VETOR]; // Declaração do vetor
    int i;
    float soma = 0;

    // Preenchendo o vetor com valores fornecidos pelo usuário
    printf("Digite %d numeros:\n", TAMANHO_VETOR);
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    // Imprimindo os valores do vetor
    printf("\nValores do vetor:\n");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", vetor[i]);
        soma += vetor[i]; // Calculando a soma dos valores
    }

    // Calculando a média dos valores
    float media = soma / TAMANHO_VETOR;

    // Imprimindo a média
    printf("\n\nMedia dos valores: %.2f\n", media);

    return 0;
}