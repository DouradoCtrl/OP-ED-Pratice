#ifndef DEFINICOES_H
#define DEFINICOES_H
#include <stdio.h>
#include <stdlib.h>
// Estrutura do nó AVL
struct NO {
    int dado;
    struct NO *esq;
    struct NO *dir;
    int altura;
};
int altura(struct NO *n);
// Funcao para calcular o fator de balanceamento
int fatorBalanceamento(struct NO *n);
// Cria um novo nó
struct NO* novoNo(int valor);
#endif //DEFINICOES_H
