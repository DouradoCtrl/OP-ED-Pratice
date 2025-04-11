#include <stdio.h>
#include <stdlib.h>

// Inclui os cabeçalhos das funções principais dos algoritmos
#include "01-exemplo1/shellsort.h"
#include "02-exemplo2/shell-insertionsort.h"
#include "03-barras/barras.h"

int main() {
    int opcao;

    // Laço principal do menu, só termina quando o usuário digita 0
    do {
        // Exibe as opções disponíveis para o usuário
        printf("\n=== COMPARACAO DE ALGORITMOS DE ORDENACAO ===\n");
        printf("1 - Executar apenas o ShellSort\n");
        printf("2 - Comparar ShellSort com InsertionSort\n");
        printf("3 - Exemplo com barras\n");
        printf("0 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);  // Lê a opção do usuário

        // Verifica qual opção foi escolhida e chama a função correspondente
        switch (opcao) {
            case 1:
                // Executa somente o ShellSort
                    shellsortPrincipal();  // Essa função deve estar definida em shellsort.c
            break;
            case 2:
                // Executa o comparativo entre ShellSort e InsertionSort
                    shellInsertionSortPrincipal();  // Essa função deve estar definida em shell_insertionsort.c
            break;
            case 3:

                    barrasPrincipal();
            break;
            case 0:
                // Sai do programa
                    printf("Encerrando o programa...\n");
            break;
            default:
                // Caso o usuário digite uma opção inválida
                    printf("Opcao invalida. Por favor, tente novamente.\n");
        }

    } while (opcao != 0);  // Repete o menu até o usuário optar por sair

    return 0;
}
