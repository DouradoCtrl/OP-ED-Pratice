#ifndef ADJ_DIRECIONADO_H
#define ADJ_DIRECIONADO_H
#include <stdio.h>
#include <stdlib.h>
#define V 4 // Número de vértices

// Função para inicializar a matriz de adjacência
void inicializaMatrizDir(int grafo[V][V]);

// Função para adicionar uma aresta em um grafo direcionado
void adicionaArestaDir(int grafo[V][V], int origem, int destino);

// Função para imprimir a matriz de adjacência
void imprimeMatrizDir(int grafo[V][V]);
int matrizAdjDirecionado();

#endif //ADJ_DIRECIONADO_H
