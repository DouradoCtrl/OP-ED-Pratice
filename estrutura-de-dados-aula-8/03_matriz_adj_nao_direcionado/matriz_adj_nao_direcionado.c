#include "matriz_adj_nao_direcionado.h" // Inclui o arquivo de cabeçalho que contém as definições necessárias

// Função para inicializar a matriz de adjacência
void inicializaMatrizNDri(int grafo[V][V]) {
    for (int i = 0; i < V; i++) { // Loop para percorrer todas as linhas da matriz
        for (int j = 0; j < V; j++) { // Loop para percorrer todas as colunas da matriz
            grafo[i][j] = 0; // Inicializa a matriz com zeros
        }
    }
}

// Função para adicionar uma aresta em um grafo não direcionado
void adicionaArestaNDri(int grafo[V][V], int origem, int destino) {
    grafo[origem][destino] = 1; // Define a aresta de origem para destino como 1
    grafo[destino][origem] = 1; // Define a aresta de destino para origem como 1, para grafo não direcionado
}

// Função para imprimir a matriz de adjacência
void imprimeMatrizNDri(int grafo[V][V]) {
    for (int i = 0; i < V; i++) { // Loop para percorrer todas as linhas da matriz
        for (int j = 0; j < V; j++) { // Loop para percorrer todas as colunas da matriz
            printf("%d ", grafo[i][j]); // Imprime o valor da matriz na posição [i][j]
        }
        printf("\n"); // Nova linha após imprimir todos os elementos de uma linha
    }
}

// Função principal que demonstra o uso da matriz de adjacência para grafos não direcionados
int matrizAdjNaoDirecionado() {
    int grafo[V][V]; // Declara a matriz de adjacência

    inicializaMatrizNDri(grafo); // Inicializa a matriz de adjacência com zeros

    adicionaArestaNDri(grafo, 0, 1); // Adiciona aresta entre os vértices 0 e 1
    adicionaArestaNDri(grafo, 0, 2); // Adiciona aresta entre os vértices 0 e 2
    adicionaArestaNDri(grafo, 1, 2); // Adiciona aresta entre os vértices 1 e 2
    adicionaArestaNDri(grafo, 2, 3); // Adiciona aresta entre os vértices 2 e 3

    printf("Matriz de Adjacencia:\n"); // Imprime o cabeçalho da matriz de adjacência
    imprimeMatrizNDri(grafo); // Imprime a matriz de adjacência
    getchar(); // Aguarda o usuário pressionar Enter
    getchar(); // Aguarda o usuário pressionar Enter novamente
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
