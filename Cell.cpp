//
// Created by Patricio Araya on 3/17/20.
//

#include <iostream>
#include "Cell.h"


Cell::Cell(const int &val, const int& sudokuSize) {
    this->value = val;
    this->possibleValues = std::vector<int>(sudokuSize);
    this->cantPossibleValues = sudokuSize;
    for (int i = 0; i < sudokuSize; ++i) {
        possibleValues[i] = i+1;
    }

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

    this->possibleValues.push_back(val);
    this->cantPossibleValues++;
}


