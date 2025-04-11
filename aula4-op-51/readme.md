# 🔢 Algoritmos de Ordenação em C - Bubble Sort, Selection Sort, Insertion Sort e Cocktail Shaker Sort

Este projeto implementa e demonstra quatro algoritmos básicos de ordenação em **C**:
- 🟢 **Bubble Sort**
- 🔵 **Selection Sort**
- 🔴 **Insertion Sort**
- 🟣 **Cocktail Shaker Sort** (Shake Sort)

O código possui um **menu interativo**, permitindo ao usuário escolher qual algoritmo executar.

---

## 📂 **Estrutura do Projeto**
O código está organizado em **pastas modulares**, separando cada algoritmo:  
📦 ordenacao-em-c  
├── 📂 01-bubblesort  
│ ├── bubblesort.c  
│ ├── bubblesort.h  
├── 📂 02-selectionsort  
│ ├── selectionsort.c  
│ ├── selectionsort.h  
├── 📂 03-insertsort  
│ ├── insertionsort.c  
│ ├── insertionsort.h  
├── 📂 04-CocktailShakerSort  
│ ├── shakersort.c  
│ ├── shakersort.h  
├── .gitignore  
├── main.c  
└── README.md

📌 **Explicação dos arquivos**:
- 📁 **`01-bubblesort/`** → Implementação do Bubble Sort.
- 📁 **`02-selectionsort/`** → Implementação do Selection Sort.
- 📁 **`03-insertsort/`** → Implementação do Insertion Sort.
- 📁 **`04-shakersort/`** → Implementação do Cocktail Shaker Sort.
- 📝 **`main.c`** → Menu interativo para chamar cada algoritmo.

---

## 🚀 **Compilação e Execução**
Para compilar e rodar o programa, use os seguintes comandos:

```sh
gcc main.c 01-bubblesort/bubblesort.c 02-selectionsort/selectionsort.c 03-insertsort/insertionsort.c 04-shakersort/shakersort.c -o ordenacao
./ordenacao
```

🎮 Funcionalidades
O programa apresenta um menu interativo, onde o usuário pode escolher qual algoritmo executar:
```
=== MENU DE ORDENACAO ===
1 - Executar Bubble Sort
2 - Executar Selection Sort
3 - Executar Insertion Sort
4 - Executar Cocktail Shaker Sort
0 - Sair

```

📌 Cada algoritmo gera um array aleatório de 10 números e o ordena.

🛠 Implementação dos Algoritmos  
1️⃣ Bubble Sort  
📌 Descrição: Compara elementos adjacentes e troca se estiverem fora de ordem.  
📌 Complexidade: O(n²)  
```
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

```

2️⃣ Selection Sort  
📌 Descrição: Seleciona o menor elemento e o coloca na posição correta.  
📌 Complexidade: O(n²)

```
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

```
3️⃣ Insertion Sort  
📌 Descrição: Insere cada elemento na posição correta, como cartas de baralho.  
📌 Complexidade: O(n²), mas eficiente para listas pequenas.  

```
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

```
4️⃣ Cocktail Shaker Sort  
📌 Descrição: Uma variação do Bubble Sort que percorre o array em duas direções, ordenando tanto da esquerda para a direita quanto da direita para a esquerda. Isso melhora a eficiência, movendo rapidamente os menores valores para o início e os maiores para o final.  
📌 Complexidade: O(n²), mas com otimizações em listas parcialmente ordenadas.  

```
void cocktailShakerSort(int arr[], int n) {
    int trocado = 1;
    int inicio = 0, fim = n - 1;

    while (trocado) {
        trocado = 0;

        // Percorre da esquerda para a direita (igual ao Bubble Sort)
        for (int i = inicio; i < fim; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocado = 1;
            }
        }

        if (!trocado) break; // Se nenhuma troca ocorreu, o array já está ordenado

        fim--; // Reduz o limite superior
        trocado = 0;

        // Percorre da direita para a esquerda (diferencial em relação ao Bubble Sort)
        for (int i = fim - 1; i >= inicio; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocado = 1;
            }
        }

        inicio++; // Aumenta o limite inferior
    }
}

```


📌 Exemplo de Saída  
```
=== MENU DE ORDENACAO ===
1 - Executar Bubble Sort
2 - Executar Selection Sort
3 - Executar Insertion Sort
4 - Executar Cocktail Shaker Sort
0 - Sair
Escolha uma opcao: 4

Gerando lista de numeros aleatorios...
Array antes da ordenacao: 83 12 57 41 99 3 28 75 90 10
Array apos a ordenacao: 3 10 12 28 41 57 75 83 90 99

```
📚 Sobre o Autor  
👨‍🏫 Professor: Edson Orivaldo Lessa Junior  
📌 Disciplina: Pesquisa e Ordenação de Dados  
📌 Ciclo: 51  

Este projeto foi criado como material didático para ilustrar algoritmos básicos de ordenação em C.  

📌 Autor: [Edson Orivaldo Lessa Junior]  
📌 Contato: [https://github.com/edson-lessa-jr/]  

📝 Licença  
Este projeto está sob a licença MIT. Use e modifique livremente!  

---

### **📌 O que este README cobre?**
✔ **Explica a estrutura do projeto**  
✔ **Fornece instruções de compilação e execução**  
✔ **Lista as funcionalidades do menu interativo**  
✔ **Explica cada algoritmo de ordenação com código**  
✔ **Mostra um exemplo real de saída**  
✔ **Inclui informações sobre o autor e a disciplina**

🚀 **Agora seu repositório no GitHub está bem documentado!** 🚀  
Se precisar de ajustes ou quiser incluir mais informações, me avise! 😊







