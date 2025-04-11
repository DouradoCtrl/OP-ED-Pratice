#include <stdio.h>

// Definindo a estrutura de registro Estudante
struct Estudante {
    char nome[50];
    int idade;
    int numero_identificacao;
    float notas[5]; // Suponha que há 5 disciplinas
};

int registro() {
    printf("Iniciando Registro\n");
    // Declaração de uma variável do tipo Estudante
    struct Estudante estudante1;

    // Preenchendo os dados do estudante
    printf("Digite o nome do estudante: ");
    scanf("%s", estudante1.nome);

    printf("Digite a idade do estudante: ");
    scanf("%d", &estudante1.idade);

    printf("Digite o numero de identificacao do estudante: ");
    scanf("%d", &estudante1.numero_identificacao);

    printf("Digite as notas do estudante em 5 disciplinas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nota da disciplina %d: ", i+1);
        scanf("%f", &estudante1.notas[i]);
    }

    // Exibindo os dados do estudante
    printf("\nDados do Estudante:\n");
    printf("Nome: %s\n", estudante1.nome);
    printf("Idade: %d\n", estudante1.idade);
    printf("Numero de Identificacao: %d\n", estudante1.numero_identificacao);
    printf("Notas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Disciplina %d: %.2f\n", i+1, estudante1.notas[i]);
    }

    return 0;
}
