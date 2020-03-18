//
// Created by Patricio Araya on 3/17/20.
//

#ifndef SUDOKU_SOLVER_CELL_H
#define SUDOKU_SOLVER_CELL_H


#include <ostream>
#include <vector>

class Cell {

private:
    int value;
    std::vector<int> possibleValues;
    int cantPossibleValues;

public:
    Cell();
    Cell(const int &val, const int &sudokuSize);
    virtual ~Cell();
    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);

    // Get & Set Value
    int getValue() const;
    void setValue(int value);

    // Get & Set possibleValues
    void setPossibleValue(const int &val);
    const std::vector<int> &getPossibleValues() const;

    int getCantPossibleValues() const;

};


#endif //SUDOKU_SOLVER_CELL_H
