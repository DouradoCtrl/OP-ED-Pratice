#include "shellsort.h"  // Inclusão do cabeçalho (certifique-se de que o arquivo esteja corretamente nomeado e no diretório)


#define TAMANHO 10  // Define o tamanho do vetor a ser ordenado

// Função para imprimir o vetor na tela
void imprimirVetor(int vetor[], int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);  // Imprime cada elemento
    }
    printf("]\n");
}

// Função que implementa o algoritmo ShellSort
int shellSort(int vetor[], int tamanho) {
    int i, j, valor;
    int gap = 1;      // Distância entre os elementos comparados
    int qtd = 0;      // Contador de iterações (movimentações dentro do while)

    // Define o maior valor inicial de gap baseado na sequência de Hibbard (3x + 1)
    do {
        gap = 3 * gap + 1;
    } while (gap < tamanho);

    // Aplica o algoritmo ShellSort reduzindo o gap progressivamente
    do {
        gap /= 3;  // Reduz o gap em cada iteração

        for (i = gap; i < tamanho; i++) {
            valor = vetor[i];     // Guarda o valor atual
            j = i - gap;          // Posição anterior para comparar

            // Realiza trocas enquanto os elementos anteriores forem maiores
            while (j >= 0 && valor < vetor[j]) {
                vetor[j + gap] = vetor[j];  // Desloca o maior valor para frente
                j -= gap;                   // Volta 'gap' posições para continuar comparando
                qtd++;                      // Conta uma iteração
            }

            vetor[j + gap] = valor;  // Insere o valor na posição correta
        }

    } while (gap > 1);  // Repete enquanto gap for maior que 1

    return qtd;  // Retorna o número de iterações realizadas
}

// Função principal do programa
int shellsortPrincipal() {
    int vetor[TAMANHO];
    int i;

    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    // Preenche o vetor com números aleatórios de 0 a 99
    for (i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor original:\n");
    imprimirVetor(vetor, TAMANHO);  // Mostra o vetor antes da ordenação

    int iteracoes = shellSort(vetor, TAMANHO);  // Ordena o vetor e armazena o número de iterações

    printf("\nVetor ordenado com ShellSort:\n");
    imprimirVetor(vetor, TAMANHO);  // Mostra o vetor após a ordenação

    printf("\nTotal de iteracoes: %d\n", iteracoes);  // Exibe o número total de comparações/movimentações

    return 0;  // Encerra o programa
}
