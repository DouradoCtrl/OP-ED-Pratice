#include "1-rotacoies-avl.h"

// Rotacao Simples a Direita
struct NO *rotacaoDireita(struct NO *y) {
    if (y == NULL || y->esq == NULL) return y; // Evita erro de acesso a NULL

    struct NO *x = y->esq;
    struct NO *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    return x;
}

// Rotacao Simples a Esquerda 
struct NO *rotacaoEsquerda(struct NO *x) {
    if (x == NULL || x->dir == NULL) return x; // Evita erro de acesso a NULL

    struct NO *y = x->dir;
    struct NO *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    return y;
}

// Rotacao Dupla Esquerda-Direita 
struct NO *rotacaoEsquerdaDireita(struct NO *z) {
    if (z == NULL || z->esq == NULL) return z; // Evita erro de acesso a NULL

    z->esq = rotacaoEsquerda(z->esq);
    return rotacaoDireita(z);
}

// Rotacao Dupla Direita-Esquerda 
struct NO *rotacaoDireitaEsquerda(struct NO *z) {
    if (z == NULL || z->dir == NULL) return z; // Evita erro de acesso a NULL

    z->dir = rotacaoDireita(z->dir);
    return rotacaoEsquerda(z);
}

// Funcao para inserir um no na BST (desbalanceada)
struct NO *inserirBST(struct NO *raiz, int valor) {
    if (raiz == NULL)
        return novoNo(valor);

    // if (valor < raiz->dado)
    raiz->esq = inserirBST(raiz->esq, valor);
    // else if (valor > raiz->dado)
    // raiz->dir = inserirBST(raiz->dir, valor);

    return raiz;
}

// Funcao para exibir a arvore em ordem
void emOrdem(struct NO *raiz) {
    if (raiz) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->dado);
        emOrdem(raiz->dir);
    }
}

// Funcao para exibir a arvore pre-ordem
void preOrdem(struct NO *raiz) {
    if (raiz) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Funcao principal com menu
int rotacoes() {
    struct NO *raiz = NULL;
    int opcao, valor;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Inserir em Arvore Normal (Desbalanceada)\n");
        printf("2 - Aplicar Rotacao Simples a Direita \n");
        printf("3 - Aplicar Rotacao Simples a Esquerda \n");
        printf("4 - Aplicar Rotacao Dupla Esquerda-Direita \n");
        printf("5 - Aplicar Rotacao Dupla Direita-Esquerda \n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                raiz = inserirBST(raiz, valor);
                printf("\nArvore atual (Pre-Ordem): ");
                preOrdem(raiz);
                printf("\n");
                break;
            case 2:
                if (raiz != NULL && raiz->esq != NULL) {
                    raiz = rotacaoDireita(raiz);
                    printf("\nRotacao Simples a Direita aplicada!\n");
                } else {
                    printf("\nNao e possivel aplicar rotacao, arvore invalida!\n");
                }
                preOrdem(raiz);
                break;
            case 3:
                if (raiz != NULL && raiz->dir != NULL) {
                    raiz = rotacaoEsquerda(raiz);
                    printf("\nRotacao Simples a Esquerda aplicada!\n");
                } else {
                    printf("\nNao e possivel aplicar rotacao, arvore invalida!\n");
                }
                preOrdem(raiz);
                break;
            case 4:
                if (raiz != NULL && raiz->esq != NULL) {
                    raiz = rotacaoEsquerdaDireita(raiz);
                    printf("\nRotacao Dupla Esquerda-Direita aplicada!\n");
                } else {
                    printf("\nNao e possivel aplicar rotacao, arvore invalida!\n");
                }
                preOrdem(raiz);
                break;
            case 5:
                if (raiz != NULL && raiz->dir != NULL) {
                    raiz = rotacaoDireitaEsquerda(raiz);
                    printf("\nRotacao Dupla Direita-Esquerda aplicada!\n");
                } else {
                    printf("\nNao e possivel aplicar rotacao, arvore invalida!\n");
                }
                preOrdem(raiz);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
