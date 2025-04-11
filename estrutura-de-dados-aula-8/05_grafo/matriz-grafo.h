#ifndef MATRIZ_GRAFO_H
#define MATRIZ_GRAFO_H
#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#define NUM_VERTICES 5 // Define o número de vértices no grafo

// Função para inicializar a matriz de adjacência
void inicializarMatrizG(int matriz[NUM_VERTICES][NUM_VERTICES]);
// Função para adicionar uma aresta ao grafo
void adicionarArestaG(int matriz[NUM_VERTICES][NUM_VERTICES], int origem, int destino) ;
// Função para exibir a matriz de adjacência
void exibirMatrizG(int matriz[NUM_VERTICES][NUM_VERTICES]);

int matrizGrafo();
#endif //MATRIZ_GRAFO_H
