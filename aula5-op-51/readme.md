# 📘 Projeto: Algoritmos de Ordenação - ShellSort

Este projeto contém exemplos educacionais para a disciplina **Estrutura de Dados II**, com foco no estudo e comparação do algoritmo **ShellSort**. Cada exemplo está separado por pastas, com arquivos organizados e comentados para fins didáticos.

---

## 📂 Estrutura de Pastas

```bash
.
├── 01-exemplo1
│   ├── shellsort.c              # Implementação básica do ShellSort
│   └── shellsort.h              # Header com protótipo da função principal
│
├── 02-exemplo2
│   ├── shell-insertionsort.c    # Comparação entre ShellSort e InsertionSort
│   └── shell-insertionsort.h    # Header com protótipo da função de comparação
│
├── 03-barras
│   ├── barras.c                 # ShellSort com simulação visual em texto
│   └── barras.h                 # Header para função animada
│
├── main.c                       # Menu interativo para executar os exemplos
└── readme.md                    # Este arquivo de explicação
```

📌 Descrição dos Exemplos
🧪 01-exemplo1: Execução simples do ShellSort
Gera um vetor aleatório e o ordena usando o algoritmo ShellSort.

Mostra o vetor antes e depois da ordenação.

Conta o número de iterações internas feitas durante a ordenação.

⚖️ 02-exemplo2: Comparativo ShellSort x InsertionSort
Executa os dois algoritmos sobre o mesmo vetor.

Mede e imprime:

⏱️ Tempo de execução (clock())

🔁 Número de iterações (comparações/movimentações)

Ideal para análises de desempenho.

🎞️ 03-barras: Visualização passo a passo do ShellSort
Representa os valores do vetor com barras (#) no terminal.

Exibe o vetor após cada passo do algoritmo.

Didático para entender o conceito de gap e a evolução da ordenação.

🧠 main.c: Menu Interativo  
O arquivo main.c oferece um menu simples no terminal:  
```
=== COMPARAÇÃO DE ALGORITMOS DE ORDENAÇÃO ===
1 - Executar apenas o ShellSort
2 - Comparar ShellSort com InsertionSort
0 - Sair do programa
```
Cada opção chama uma das funções principais implementadas nas pastas anteriores.

🛠️ Compilação e Execução
Para compilar o projeto completo com o menu:
```
gcc main.c 01-exemplo1/shellsort.c 02-exemplo2/shell-insertionsort.c 03-barras/barras.c -o ordenacao
```
Para executar:
```
./ordenacao
```

👨‍🏫 Público-alvo
Este projeto é voltado para:

Alunos e professores de algoritmos e estrutura de dados

Estudo e demonstração didática de algoritmos de ordenação

Aulas online e presenciais com foco em visualização e comparação prática