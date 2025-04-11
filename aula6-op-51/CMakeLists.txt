cmake_minimum_required(VERSION 3.30)
project(aula6_op_51 C)

set(CMAKE_C_STANDARD 11)

add_executable(aula6_op_51 main.c
        01-mergesort/mergesort.c
        01-mergesort/mergesort.h
        02-quicksort/quicksort.c
        02-quicksort/quicksort.h
        03-heapsort/heapsort.c
        03-heapsort/heapsort.h)
