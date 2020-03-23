cmake_minimum_required(VERSION 3.15)
project(sudoku_solver)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILER /usr/local/bin/g++-9)
set(CMAKE_C_COMPILER /usr/local/bin/gcc-9)
# enable openmp using -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fopenmp")

add_executable(sudoku_solver main.cpp Sudoku.cpp Sudoku.h Cell.cpp Cell.h)