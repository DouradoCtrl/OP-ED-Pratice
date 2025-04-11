#include "matriz-adjacencia.h" // Inclui o arquivo de cabeçalho que contém as definições necessárias

// Função para inicializar a matriz de adjacência
void inicializaMatrizAdj(int grafo[V][V]) {
    for (int i = 0; i < V; i++) { // Loop externo para percorrer as linhas
        for (int j = 0; j < V; j++) { // Loop interno para percorrer as colunas
            grafo[i][j] = 0; // Inicializa a matriz com zeros, indicando ausência de arestas
        }
    }
}

// Função para adicionar uma aresta em um grafo não direcionado
void adicionaArestaAdj(int grafo[V][V], int origem, int destino) {
    grafo[origem][destino] = 1; // Marca a presença de uma aresta da origem ao destino
    grafo[destino][origem] = 1; // Marca a presença de uma aresta do destino à origem (grafo não direcionado)
}

// Função para imprimir a matriz de adjacência
void imprimeMatrizAdj(int grafo[V][V]) {
    for (int i = 0; i < V; i++) { // Loop externo para percorrer as linhas
        for (int j = 0; j < V; j++) { // Loop interno para percorrer as colunas
            printf("%d ", grafo[i][j]); // Imprime o valor na posição (i, j)
        }
        printf("\n"); // Nova linha após imprimir uma linha inteira da matriz
    }
}

int matrizAdjacente() {
    int grafo[V][V]; // Declara uma matriz de adjacência para o grafo

    inicializaMatrizAdj(grafo); // Inicializa a matriz de adjacência

    // Adiciona arestas ao grafo
    adicionaArestaAdj(grafo, 0, 1); // Adiciona aresta entre os vértices 0 e 1
    adicionaArestaAdj(grafo, 0, 2); // Adiciona aresta entre os vértices 0 e 2
    adicionaArestaAdj(grafo, 1, 2); // Adiciona aresta entre os vértices 1 e 2
    adicionaArestaAdj(grafo, 2, 3); // Adiciona aresta entre os vértices 2 e 3

    printf("Matriz de Adjacência:\n"); // Imprime uma mensagem antes de exibir a matriz
    imprimeMatrizAdj(grafo); // Chama a função para imprimir a matriz de adjacência

    getchar(); // Aguarda o usuário pressionar Enter
    getchar(); // Aguarda o usuário pressionar Enter novamente

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

