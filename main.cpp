#include <iostream>
#include <cmath>
#include "Sudoku.h"


int main() {
    std::cout << "Sudoku solver" << std::endl;
    Sudoku sudoku = Sudoku(9);
    sudoku.importFromFile("2");
    std::cout << sudoku << std::endl;
    std::cout << sudoku.checkCell(0,1,1);
    return 0;
}


