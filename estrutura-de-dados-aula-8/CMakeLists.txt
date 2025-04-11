cmake_minimum_required(VERSION 3.30)
project(estrutura_de_dados_aula_8 C)

set(CMAKE_C_STANDARD 11)

add_executable(estrutura_de_dados_aula_8 main.c
        "01_matriz_adjacencia/matriz-adjacencia.h"
        01_matriz_adjacencia/matriz-adjacencia.c
        03_matriz_adj_nao_direcionado/matriz_adj_nao_direcionado.h
        03_matriz_adj_nao_direcionado/matriz_adj_nao_direcionado.c
        04_matriz_adj_direcionado/matriz_adj_direcionado.c
        04_matriz_adj_direcionado/matriz_adj_direcionado.h
        05_grafo/matriz-grafo.c
        05_grafo/matriz-grafo.h
        02_lista_adjacencia/lista-adjacencia.c
        02_lista_adjacencia/lista-adjacencia.h)
