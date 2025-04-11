cmake_minimum_required(VERSION 3.30)
project(estrutura_de_dados_aula_9 C)

set(CMAKE_C_STANDARD 11)

add_executable(estrutura_de_dados_aula_9 main.c
        02_busca_dfs/busca-profundidade.c
        02_busca_dfs/busca-profundidade.h
        02_busca_dfs/busca-profundidade.h
        01_grafo/grafo.c
        01_grafo/grafo.h
        01_grafo/grafo.h)
