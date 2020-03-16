//
// Created by Patricio Araya on 3/15/20.
//

#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H


#include <ostream>
#include <string>

class Sudoku {

public:

    int size;
    int squareSize;
    int ** grid;

    Sudoku(int size);
    virtual ~Sudoku();
    friend std::ostream &operator<<(std::ostream &os, const Sudoku &sudoku);

    bool checkCell(const int& row, const int& col, const int& val);


    void importFromFile(std::string name);


};


#endif //SUDOKU_SOLVER_SUDOKU_H
