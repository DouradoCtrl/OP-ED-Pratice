#ifndef ADJ_NAO_DIRECIONADO_H
#define ADJ_NAO_DIRECIONADO_H
#include <stdio.h>
#include <stdlib.h>
#define V 4 // Número de vértices

// Função para inicializar a matriz de adjacência
void inicializaMatrizNDri(int grafo[V][V]);

// Função para adicionar uma aresta em um grafo não direcionado
void adicionaArestaNDri(int grafo[V][V], int origem, int destino);

// Função para imprimir a matriz de adjacência
void imprimeMatrizNDri(int grafo[V][V]);

int matrizAdjNaoDirecionado();

#endif //ADJ_NAO_DIRECIONADO_H
