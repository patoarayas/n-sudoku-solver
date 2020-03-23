//
// Created by Patricio Araya on 3/17/20.
//

#include <iostream>
#include <string>
#include "Cell.h"


Cell::Cell(const int &val,const int &row,const int &col, const int& sudokuSize) {
    this->value = val;
    this->row = row;
    this->col = col;
    this->possibleValues = std::vector<int>(sudokuSize);
    this->cantPossibleValues = 0;
    /*
    for (int i = 0; i < sudokuSize; ++i) {
        possibleValues[i] = i+1;
    }
     */

}

Cell::Cell() {
    this->value = 0;
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    os << "|" << cell.value << "|";
    return os;
}

Cell::~Cell() = default;

int Cell::getValue() const {
    return value;
}

void Cell::setValue(int value) {
    Cell::value = value;
}

const std::vector<int> &Cell::getPossibleValues() const {
    return possibleValues;
}

int Cell::getCantPossibleValues() const {
    return cantPossibleValues;
}

void Cell::setPossibleValue(const int &val) {

    this->possibleValues[cantPossibleValues] = val;
    this->cantPossibleValues++;
}

std::string Cell::cellInfo() {
    std::string str = "ROW: "+std::to_string(this->row)+" COL: "+std::to_string(this->col)+" VALUE: "+std::to_string(this->value)+" POSSIBLE VALUES["+std::to_string(this->cantPossibleValues)+"]: ";

    for (int i = 0; i < this->cantPossibleValues; ++i) {
        str += std::to_string(possibleValues[i])+", ";
    }
    return str;
}


