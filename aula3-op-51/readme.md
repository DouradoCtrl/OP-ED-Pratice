# 🌳 Rotações AVL em C - Demonstração Prática

Este projeto implementa e demonstra **rotações em Árvores AVL** em **C**. O programa inclui um menu interativo para testar **rotações simples e duplas** em uma árvore binária de busca desbalanceada.

---

## 📂 **Estrutura do Projeto**
O código está organizado em **pastas modulares**:

📦 arvore-avl  
├── 📂 0-definicoes  
│ ├── definicoes.h  
│ ├── definicoes.c  
├── 📂 1-rotacoes-avl  
│ ├── 1-rotacoes-avl.h  
│ ├── 1-rotacoes-avl.c    
├── main.c  
└── README.md  


📌 **Explicação das pastas**:

- **`0-definicoes/`** → Contém a estrutura base `struct NO` e funções auxiliares (`altura`, `fatorBalanceamento`, `novoNo`).
- **`1-rotacoes-avl/`** → Implementa as rotações AVL e o menu interativo.
- **`main.c`** → Função principal para chamar o programa de rotações.

---

## ⚙ **Compilação e Execução**
Para compilar e rodar o programa, use os seguintes comandos:

```sh
gcc main.c 0-definicoes/definicoes.c 1-rotacoes-avl/1-rotacoes-avl.c -o rotacoes
./rotacoes
```

📌 **Explicação das pastas**:

- **`0-definicoes/`** → Contém a estrutura base `struct NO` e funções auxiliares (`altura`, `fatorBalanceamento`, `novoNo`).  
- **`1-rotacoes-avl/`** → Implementa as rotações AVL e o menu interativo.  
- **`main.c`** → Função principal para chamar o programa de rotações.  

---

## ⚙ **Compilação e Execução**
Para compilar e rodar o programa, use os seguintes comandos:

```sh
gcc main.c 0-definicoes/definicoes.c 1-rotacoes-avl/1-rotacoes-avl.c -o rotacoes
./rotacoes
```
## 🎮 Funcionalidades
O programa possui um menu interativo para testar as rotações AVL. As opções disponíveis são:
```
=== MENU ===
1 - Inserir em Arvore Normal (Desbalanceada)
2 - Aplicar Rotacao Simples a Direita (LL)
3 - Aplicar Rotacao Simples a Esquerda (RR)
4 - Aplicar Rotacao Dupla Esquerda-Direita (LR)
5 - Aplicar Rotacao Dupla Direita-Esquerda (RL)
0 - Sair
```
📝 Exemplo de Uso  
1️⃣ O usuário insere valores na árvore.  
2️⃣ Escolhe uma rotação para aplicar.  
3️⃣ O programa exibe a árvore antes e depois da modificação.  

## 🛠 Detalhes Técnicos
Rotação Simples à Direita → Ocorre quando um nó é inserido na esquerda do filho esquerdo.
Rotação Simples à Esquerda → Ocorre quando um nó é inserido na direita do filho direito.
Rotação Dupla Esquerda-Direita → Ocorre quando um nó é inserido na direita do filho esquerdo.
Rotação Dupla Direita-Esquerda → Ocorre quando um nó é inserido na esquerda do filho direito. 
#### 📌 As rotações são aplicadas automaticamente conforme a necessidade da árvore AVL.

## 📌 Exemplo de Saída
```
=== MENU ===
1 - Inserir em Arvore Normal (Desbalanceada)
2 - Aplicar Rotacao Simples a Direita (LL)
3 - Aplicar Rotacao Simples a Esquerda (RR)
4 - Aplicar Rotacao Dupla Esquerda-Direita (LR)
5 - Aplicar Rotacao Dupla Direita-Esquerda (RL)
0 - Sair

Escolha uma opcao: 1
Digite um valor para inserir: 30
Arvore atual (Pre-Ordem): 30

Escolha uma opcao: 1
Digite um valor para inserir: 20
Arvore atual (Pre-Ordem): 30 20

Escolha uma opcao: 1
Digite um valor para inserir: 10
Arvore atual (Pre-Ordem): 30 20 10

Escolha uma opcao: 2
Rotacao Simples a Direita aplicada!
Arvore atual (Pre-Ordem): 20 10 30
```
### 🚀 Contribuições
Sinta-se à vontade para fazer um fork do repositório, sugerir melhorias ou abrir issues com dúvidas e sugestões! 🎯    

📌 Autor: Edson Orivaldo Lessa Junior  
📌 Contato: https://github.com/edson-lessa-jr/  