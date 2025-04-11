cmake_minimum_required(VERSION 3.30)
project(estrutura_de_dados_aula_6 C)

set(CMAKE_C_STANDARD 11)

add_executable(estrutura_de_dados_aula_6 main.c
        01_pilha_lista_dinamica/01_pilha_lista_dinamica.c
        01_pilha_lista_dinamica/01_pilha_lista_dinamica.h
        02_fila_lista_dinamica/02_fila_lista_dinamica.h
        02_fila_lista_dinamica/02_fila_lista_dinamica.c)
