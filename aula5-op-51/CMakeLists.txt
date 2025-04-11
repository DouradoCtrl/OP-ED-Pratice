cmake_minimum_required(VERSION 3.30)
project(aula5_op_51 C)

set(CMAKE_C_STANDARD 11)

add_executable(aula5_op_51 main.c
        "01-exemplo1/shellsort.c"
        "01-exemplo1/shellsort.h"
        02-exemplo2/shell-insertionsort.c
        02-exemplo2/shell-insertionsort.h
        03-barras/barras.c
        03-barras/barras.h)
