# Estrutura, Pesquisa e Ordenação

## Programas de Ordenação
Este repositório contém implementações dos algoritmos de ordenação:
- **Mergesort** (Pasta `01-mergesort`)
- **Quicksort** (Pasta `02-quicksort`)
- **Heapsort** (Pasta `03-heapsort`)

Estes algoritmos foram desenvolvidos como parte da disciplina **Estrutura, Pesquisa e Ordenação** na **Universidade Unicesumar**.

### Autor
- **Edson Orivaldo Lessa Junior**

### Descrição dos Programas
O projeto inclui um arquivo principal `main.c` que permite ao usuário:
1. Gerar um novo array aleatório.
2. Gerar um array no pior caso (ordenado de forma decrescente).
3. Ordenar o array usando Mergesort, Quicksort ou Heapsort.
4. Comparar o desempenho dos algoritmos medindo o tempo de execução.

### Estrutura de Pastas
```
/
├── 01-mergesort
│   ├── mergesort.h
│   ├── mergesort.c
├── 02-quicksort
│   ├── quicksort.h
│   ├── quicksort.c
├── 03-heapsort
│   ├── heapsort.h
│   ├── heapsort.c
├── main.c
├── README.md
```

### Compilação
Para compilar o programa principal, execute o seguinte comando:
```
gcc main.c 01-mergesort/mergesort.c 02-quicksort/quicksort.c 03-heapsort/heapsort.c -o ordenacao
```

### Execução
Após compilar, execute o programa com:
```
./ordenacao
```

### Observações
- Os algoritmos foram implementados para permitir testes com arrays aleatórios e arrays no pior caso possível.
- Os resultados exibem o tempo de execução de cada algoritmo, permitindo comparações diretas.

### Licença
Este projeto é de uso acadêmico e faz parte da disciplina de Estrutura, Pesquisa e Ordenação ministrada na Universidade Unicesumar.

