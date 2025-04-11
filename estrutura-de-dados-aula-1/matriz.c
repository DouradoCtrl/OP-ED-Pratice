#include <stdio.h>

#define NUM_ALUNOS 3 // Número de alunos
#define NUM_DISCIPLINAS 4 // Número de disciplinas

int matriz() {
    printf("Iniciando Matriz\n");
    float notas[NUM_ALUNOS][NUM_DISCIPLINAS]; // Declaração da matriz de notas
    int i, j;
    float media;

    // Preenchendo a matriz com valores fornecidos pelo usuário
    printf("Digite as notas dos alunos:\n");
    for (i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno %d:\n", i+1);
        for (j = 0; j < NUM_DISCIPLINAS; j++) {
            printf("Nota da disciplina %d: ", j+1);
            scanf("%f", &notas[i][j]);
        }
    }

    // Calculando e imprimindo a média de cada aluno
    printf("\nMedia de cada aluno:\n");
    for (i = 0; i < NUM_ALUNOS; i++) {
        media = 0;
        for (j = 0; j < NUM_DISCIPLINAS; j++) {
            media += notas[i][j]; // Somando as notas de cada disciplina
        }
        media /= NUM_DISCIPLINAS; // Calculando a média
        printf("Aluno %d: %.2f\n", i+1, media);
    }

    return 0;
}