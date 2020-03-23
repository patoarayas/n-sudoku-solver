#include <iostream>
#include <cmath>
#include "Sudoku.h"


int main() {
    std::cout << "Sudoku solver" << std::endl;
    Sudoku sudoku = Sudoku(9);
    sudoku.importFromFile("1");
    std::cout << sudoku << std::endl;
    sudoku.solve(4);
    std::cout << sudoku << std::endl;
    std::cout << sudoku.validate();

    return 0;
}


