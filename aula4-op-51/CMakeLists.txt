cmake_minimum_required(VERSION 3.30)
project(aula4_op_51 C)

set(CMAKE_C_STANDARD 11)

add_executable(aula4_op_51 main.c
        01-bubblesort/bubblesort.h
        01-bubblesort/bubblesort.c
        02-selectionsort/selectionsort.c
        02-selectionsort/selectionsort.h
        03-insertsort/insertionsort.c
        03-insertsort/insertionsort.h
        04-CocktailShakerSort/shakersort.c
        04-CocktailShakerSort/shakersort.h)
