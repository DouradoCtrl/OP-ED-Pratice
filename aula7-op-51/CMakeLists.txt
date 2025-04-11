cmake_minimum_required(VERSION 3.30)
project(aula7_op_51 C)

set(CMAKE_C_STANDARD 11)

add_executable(aula7_op_51 main.c
        01-busca-sequencial/busca-sequencial.c
        01-busca-sequencial/busca-sequencial.h
        02-busca-indexada/busca-indexada.c
        02-busca-indexada/busca-indexada.h
        03-busca-binaria/busca-binaria.c
        03-busca-binaria/busca-binaria.h
        04-busca-binaria-palavras-manual/busca-binaria-palavras-manual.c
        04-busca-binaria-palavras-manual/busca-binaria-palavras-manual.h
        05-busca-binaria-palavras-funcoes/busca-binaria-palavras-funcoes.c
        05-busca-binaria-palavras-funcoes/busca-binaria-palavras-funcoes.h)
