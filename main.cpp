#include <iostream>
#include <cmath>
#include <ctime>
#include "Sudoku.h"


int main() {
    std::cout << "Sudoku solver" << std::endl;

    for (int i = 0; i < 4; ++i) {
        std::cout << "Nº Threads: " << i << std::endl;
        Sudoku sudoku = Sudoku(16);
        sudoku.importFromFile("1");
        std::cout << sudoku << std::endl;
        std::clock_t start;
        double duration;
        start = std::clock();

        sudoku.solve_parallel(i);
        duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

        std::cout << "Valid solution(1=true): " << sudoku.validate() << std::endl;
        std::cout << "Time in seconds: " << duration << std::endl;
    }


    return 0;
}
