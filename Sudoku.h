//
// Created by Patricio Araya on 3/15/20.
//

#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H


#include <ostream>
#include <string>
#include "Cell.h"

class Sudoku {

public:


    int size;
    int boxSize;
    Cell **grid;

    /**
     * Single argument constructor
     */
    explicit Sudoku(int size);

    /**
     * Destructor
     */
    virtual ~Sudoku();

    /**
     * << operator
     * @param os std::ostream
     * @param sudoku : this
     * @return std::ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Sudoku &sudoku);

    /**
     * Check if a value can be placed in a given cell [row][col]
     * @param row The row of the cell.
     * @param col The column of the cell.
     * @param val The value to be inserted.
     * @return whether the value can be placed.
     */
    bool checkCell(const int &row, const int &col, const int &val);

    bool solve(const int& workers);
    /**
     * Import a sudoku board from a file.
     * @param name : the sufix of the file.
     * All files are named like this -> {size}_{name}.csv. where size is the size of the sudoku grid.
     */
    void importFromFile(std::string name);


};


#endif //SUDOKU_SOLVER_SUDOKU_H
