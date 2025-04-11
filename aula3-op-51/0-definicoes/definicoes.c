#include "definicoes.h"

// Cria um novo nó
struct NO* novoNo(int valor) {
    struct NO* no = (struct NO*) malloc(sizeof(struct NO));
    no->dado = valor;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1;
    return no;
}
// Função para calcular a altura de um nó
int altura(struct NO *n) {
    if (n == NULL) return 0;
    return n->altura;
}
// Funcao para calcular o fator de balanceamento
int fatorBalanceamento(struct NO *n) {
    if (n == NULL) return 0;
    return altura(n->esq) - altura(n->dir);
}