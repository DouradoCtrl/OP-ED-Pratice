cmake_minimum_required(VERSION 3.30)
project(estrutura_de_dados_aula_10 C)

set(CMAKE_C_STANDARD 11)

add_executable(estrutura_de_dados_aula_10 main.c
        01_busca_largura/bfs.c
        01_busca_largura/bfs.h
        01_busca_largura/bfs.h
        02_dijkstra/dijkstra.c
        02_dijkstra/dijkstra.h
        02_dijkstra/dijkstra.h)
