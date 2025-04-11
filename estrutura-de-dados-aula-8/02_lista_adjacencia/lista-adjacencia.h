#ifndef LISTA_GRAFO_H
#define LISTA_GRAFO_H
#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na lista de adjacência
struct Node {
    int vertex;
    struct Node* next;
};

// Estrutura para representar uma lista de adjacência
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Função para criar um novo nó
struct Node* createNode(int vertex) ;

// Função para criar um grafo
struct Graph* createGraph(int vertices) ;

// Função para adicionar aresta
void addEdge(struct Graph* graph, int src, int dest) ;

// Função para imprimir o grafo
void printGraph(struct Graph* graph);

int listaAdjacencia() ;
#endif //LISTA_GRAFO_H
