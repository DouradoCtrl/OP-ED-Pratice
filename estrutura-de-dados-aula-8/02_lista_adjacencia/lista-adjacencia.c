#include "lista-adjacencia.h" // Inclui o arquivo de cabeçalho que contém as definições necessárias

// Função para criar um novo nó
struct Node* createNode(int vertex) {
    struct Node* newNode = malloc(sizeof(struct Node)); // Aloca memória para um novo nó
    newNode->vertex = vertex; // Define o vértice do nó
    newNode->next = NULL; // Define o próximo nó como NULL
    return newNode; // Retorna o novo nó criado
}

// Função para criar um grafo
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph)); // Aloca memória para o grafo
    graph->numVertices = vertices; // Define o número de vértices do grafo
    graph->adjLists = malloc(vertices * sizeof(struct Node*)); // Aloca memória para as listas de adjacência

    for (int i = 0; i < vertices; i++) { // Loop para inicializar as listas de adjacência
        graph->adjLists[i] = NULL; // Inicializa cada lista de adjacência como NULL
    }

    return graph; // Retorna o grafo criado
}

// Função para adicionar aresta
void addEdge(struct Graph* graph, int src, int dest) {
    // Adicionar aresta da origem para o destino
    struct Node* newNode = createNode(dest); // Cria um novo nó para o destino
    newNode->next = graph->adjLists[src]; // Define o próximo nó como o primeiro nó da lista de adjacência de origem
    graph->adjLists[src] = newNode; // Adiciona o novo nó no início da lista de adjacência de origem

    // Adicionar aresta do destino para a origem (para grafos não direcionados)
    newNode = createNode(src); // Cria um novo nó para a origem
    newNode->next = graph->adjLists[dest]; // Define o próximo nó como o primeiro nó da lista de adjacência de destino
    graph->adjLists[dest] = newNode; // Adiciona o novo nó no início da lista de adjacência de destino
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) { // Loop para percorrer todos os vértices do grafo
        struct Node* temp = graph->adjLists[v]; // Obtém a lista de adjacência do vértice atual
        printf("\n Lista de adjacencia do vertice %d\n", v); // Imprime o número do vértice atual
        while (temp) { // Loop para percorrer a lista de adjacência
            printf("-> %d", temp->vertex); // Imprime o vértice adjacente
            temp = temp->next; // Vai para o próximo nó na lista de adjacência
        }
        printf("\n"); // Nova linha após imprimir todos os vértices adjacentes
    }
}

int listaAdjacencia() {
    struct Graph* graph = createGraph(5); // Cria um grafo com 5 vértices
    addEdge(graph, 0, 1); // Adiciona aresta entre os vértices 0 e 1
    addEdge(graph, 0, 4); // Adiciona aresta entre os vértices 0 e 4
    addEdge(graph, 1, 2); // Adiciona aresta entre os vértices 1 e 2
    addEdge(graph, 1, 3); // Adiciona aresta entre os vértices 1 e 3
    addEdge(graph, 1, 4); // Adiciona aresta entre os vértices 1 e 4
    addEdge(graph, 2, 3); // Adiciona aresta entre os vértices 2 e 3
    addEdge(graph, 3, 4); // Adiciona aresta entre os vértices 3 e 4

    printGraph(graph); // Imprime o grafo
    getchar(); // Aguarda o usuário pressionar Enter
    getchar(); // Aguarda o usuário pressionar Enter novamente
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
