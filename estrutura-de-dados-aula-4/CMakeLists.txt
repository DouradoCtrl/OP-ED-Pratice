cmake_minimum_required(VERSION 3.30)
project(estrutura_de_dados_aula_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(estrutura_de_dados_aula_4 main.c
        ex1_pilhas/ex1_pilhas.c
        ex2_filas/ex2_filas.c
        ex1_pilhas/ex1_pilhas.h
        navegacao.h
        ex2_filas/ex2_filas.h)
