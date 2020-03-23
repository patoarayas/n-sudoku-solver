//
// Created by Patricio Araya on 3/15/20.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include "Sudoku.h"
#include <omp.h>

Sudoku::Sudoku(int size) : size(size) {
    this->boxSize = (int) sqrt(size);
    this->grid = new Cell *[size];

    this->array = new Cell *[size * size];
    this->emptyCells = 0;


    for (int i = 0; i < size; ++i) {
        grid[i] = new Cell[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = Cell();
        }
    }

}

Sudoku::~Sudoku() {
    for (int i = 0; i < size; ++i)
        delete[] grid[i];
    delete[] grid;

}

std::ostream &operator<<(std::ostream &os, const Sudoku &sudoku) {
    for (int i = 0; i < sudoku.size; ++i) {

        for (int j = 0; j < sudoku.size; ++j) {
            os << sudoku.grid[i][j];
        }
        os << std::endl;
    }
    return os;
}

void Sudoku::importFromFile(const std::string &name) {

    std::string path = "../sudoku-examples/" + std::to_string(size) + "_" + name + ".csv";
    std::fstream file(path);
    std::cout << "file:" << path << std::endl;

    if (file.is_open()) {
        int row = 0;
        while (!file.eof()) {

            for (int i = 0; i < size; ++i) {
                std::string val;
                getline(file, val, ',');
                this->grid[row][i] = Cell(std::stoi(val), row, i, size);

                if (std::stoi(val) == 0) {
                    this->array[emptyCells] = &this->grid[row][i];
                    this->emptyCells += 1;
                }

            }
            row++;


        }
    } else {
        std::cout << "Error: No such file." << std::endl;
    }
    file.close();
}

bool Sudoku::checkCell(const int &row, const int &col, const int &val) {
    // Check for a repeated value at row and col.
    for (int i = 0; i < size; ++i) {
        if (grid[row][i].getValue() == val) {
            return false;
        }
        if (this->grid[i][col].getValue() == val) {
            return false;
        }
    }
    // Check for repeated values whithin the cell's square.
    int row_boxStart = (row / boxSize) * boxSize;
    int col_boxStart = (col / boxSize) * boxSize;

    for (int i = row_boxStart; i < row_boxStart + this->boxSize; ++i) {
        for (int j = col_boxStart; j < col_boxStart + this->boxSize; ++j) {
            if (this->grid[i][j].getValue() == val) {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::solve(const int &threads) {
    // Set max number of thread to use
    omp_set_num_threads(threads);

    // 1. Look for potential answers for each cell.
//#pragma omp parallel for default(none) //reduction(+: emptyCells)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j].getValue() == 0) {
                // Is an empty cell. Check possible values.
                emptyCells++;
                for (int k = 1; k <= size; ++k) {
                    if (checkCell(i, j, k)) {
                        // This k value can be placed in the grid. Add to cell possible values array.
                        grid[i][j].setPossibleValue(k);
                    }
                }
            }
        }
    }
    /* Log
    {
        // Print posible answers.
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j].getValue() == 0) {
                    std::cout << grid[i][j].cellInfo() << std::endl;
                }

            }
        }

        for (int l = 0; l < size * size; ++l) {
            std::cout << "ARRAY-> " << array[l]->cellInfo() << std::endl;
        }
    }
     */

    // 2. Search an empty and unblocked cell with less potential answers.
    return backtrack();

}

bool Sudoku::backtrack() {
    if (gridIsFull()) {
        return true;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // If cell is empty
            if (grid[i][j].getValue() == 0) {
                // For every empty value
                for (int k = 0; k < grid[i][j].getCantPossibleValues(); ++k) {
                    if (checkCell(i, j, grid[i][j].getPossibleValues().at(k))) {
                        grid[i][j].setValue(grid[i][j].getPossibleValues().at(k));
                        if (backtrack()) {
                            return true;
                        } else {
                            grid[i][j].setValue(0);
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::gridIsFull() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (this->grid[i][j].getValue() == 0) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::validate() {

    if(!gridIsFull()){
        return false;
    }

    /* For every cell in the grid applies the same procedure as checkCell()
     * with the exception of the value of the cell that is currently analyzing (Because the grid is now full).
     * */
    for (int l = 0; l < size; ++l) {
        for (int m = 0; m < size; ++m) {
            // Check for a repeated value at row and col.
            int val = grid[l][m].getValue();
            for (int i = 0; i < size; ++i) {

                if (grid[l][i].getValue() == val && i!=m) {
                    return false;
                }
                if (this->grid[i][m].getValue() == val && i!=l) {
                    return false;
                }
            }
            // Check for repeated values whithin the cell's square.
            int row_boxStart = (l / boxSize) * boxSize;
            int col_boxStart = (m / boxSize) * boxSize;

            for (int i = row_boxStart; i < row_boxStart + this->boxSize; ++i) {
                for (int j = col_boxStart; j < col_boxStart + this->boxSize; ++j) {
                    if(i!=l && j!=m) {
                        if (this->grid[i][j].getValue() == val) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}






