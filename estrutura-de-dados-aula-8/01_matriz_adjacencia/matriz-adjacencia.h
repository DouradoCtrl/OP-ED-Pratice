#ifndef MATRIZ_ADJACENCIA_H
#define MATRIZ_ADJACENCIA_H
#include <stdio.h>
#include <stdlib.h>
#define V 4 // Número de vértices

void inicializaMatrizAdj(int grafo[V][V]);
void adicionaArestaAdj(int grafo[V][V], int origem, int destino);
void imprimeMatrizAdj(int grafo[V][V]);
int matrizAdjacente();

#endif //MATRIZ_ADJACENCIA_H
