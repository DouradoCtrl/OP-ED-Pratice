#include "matriz_adj_direcionado.h" // Inclui o arquivo de cabeçalho que contém as definições necessárias

// Função para inicializar a matriz de adjacência
void inicializaMatrizDir(int grafo[V][V]) {
    for (int i = 0; i < V; i++) { // Loop para percorrer todas as linhas da matriz
        for (int j = 0; j < V; j++) { // Loop para percorrer todas as colunas da matriz
            grafo[i][j] = 0; // Inicializa a matriz com zeros
        }
    }
}

// Função para adicionar uma aresta em um grafo direcionado
void adicionaArestaDir(int grafo[V][V], int origem, int destino) {
    grafo[origem][destino] = 1; // Adiciona a aresta da origem para o destino (grafo direcionado)
}

// Função para imprimir a matriz de adjacência
void imprimeMatrizDir(int grafo[V][V]) {
    for (int i = 0; i < V; i++) { // Loop para percorrer todas as linhas da matriz
        for (int j = 0; j < V; j++) { // Loop para percorrer todas as colunas da matriz
            printf("%d ", grafo[i][j]); // Imprime o valor da matriz na posição [i][j]
        }
        printf("\n"); // Nova linha após imprimir todos os elementos de uma linha
    }
}

// Função principal que demonstra o uso da matriz de adjacência para grafos direcionados
int matrizAdjDirecionado() {
    int grafo[V][V]; // Declara a matriz de adjacência

    inicializaMatrizDir(grafo); // Inicializa a matriz de adjacência com zeros

    adicionaArestaDir(grafo, 0, 1); // Adiciona aresta do vértice 0 para o vértice 1
    adicionaArestaDir(grafo, 0, 2); // Adiciona aresta do vértice 0 para o vértice 2
    adicionaArestaDir(grafo, 1, 2); // Adiciona aresta do vértice 1 para o vértice 2
    adicionaArestaDir(grafo, 2, 3); // Adiciona aresta do vértice 2 para o vértice 3

    printf("Matriz de Adjacencia:\n"); // Imprime o cabeçalho da matriz de adjacência
    imprimeMatrizDir(grafo); // Imprime a matriz de adjacência
    getchar(); // Aguarda o usuário pressionar Enter
    getchar(); // Aguarda o usuário pressionar Enter novamente
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
