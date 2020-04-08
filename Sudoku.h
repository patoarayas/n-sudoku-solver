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
    Cell **array;
    int emptyCells;

    /**
     * Single argument constructor
     */
    explicit Sudoku(int size);

    Sudoku(const Sudoku &sudoku);

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

    /**
     * Import a sudoku board from a file.
     * @param name : the sufix of the file.
     * All files are named like this -> {size}_{name}.csv. where size is the size of the sudoku grid.
     */
    void importFromFile(const std::string &name);

    /**
     * Solve the sudoku.
     * @return whether the sudoku could be solved.
     */
    bool solve();

    /**
     * Implement recursive function to solve the sudoku.
     * Fill an empty cell with a valid value and call itself until grid is complete.
     * @return  bool. If there are no valid options to fill the cell returns false.
     */
    bool backtrack();

    /**
     * Check if every cell in the grid has a value (distinct to 0)
     * @return bool
     */
    bool gridIsFull();

    /**
     * Validate if a sudoku solution is valid.
     * @return bool
     */
    bool validate();

    bool solve_parallel(const int &threads);

    bool sp(const int &threads);

    void pBacktrack(Sudoku &sudoku);


};


#endif //SUDOKU_SOLVER_SUDOKU_H
