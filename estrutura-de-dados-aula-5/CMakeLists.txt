cmake_minimum_required(VERSION 3.30)
project(estrutura_de_dados_aula_5 C)

set(CMAKE_C_STANDARD 11)

add_executable(estrutura_de_dados_aula_5 main.c
        01_lista_dinamica/01_lista_dinamica.h
        01_lista_dinamica/01_lista_dinamica.c
        02_lista_duplamente_encadeada/02_lista_duplamente_encadeada.h
        02_lista_duplamente_encadeada/02_lista_duplamente_encadeada.c
        03_lista_tarefas/03_lista_tarefas.c)
