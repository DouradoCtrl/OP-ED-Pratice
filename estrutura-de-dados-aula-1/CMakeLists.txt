cmake_minimum_required(VERSION 3.30)
project(estrutura_de_dados_aula_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(estrutura_de_dados_aula_1 main.c
        vetor.c
        matriz.c
        registro.c)
