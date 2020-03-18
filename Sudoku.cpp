//
// Created by Patricio Araya on 3/15/20.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include "Sudoku.h"

Sudoku::Sudoku(int size) : size(size) {
    this->boxSize = sqrt(size);
    this->grid = new Cell*[size];

    for(int i = 0; i<size;++i){
        grid[i] = new Cell[size];
    }

    for(int i= 0;i<size;++i){
        for (int j = 0; j < size; ++j) {
            grid[i][j] = Cell();
        }
    }
}

Sudoku::~Sudoku() {
    for (int i = 0; i < size; ++i)
        delete [] grid[i];
    delete [] grid;
}

std::ostream &operator<<(std::ostream &os, const Sudoku &sudoku) {
    for (int i = 0; i < sudoku.size ; ++i) {

        for (int j = 0; j < sudoku.size ; ++j) {
            os << sudoku.grid[i][j];
        }
        os << std::endl;
    }
    return os;
}

void Sudoku::importFromFile(std::string name) {

    std::string path = "../sudoku-examples/"+std::to_string(size)+"_"+name+".csv";
    std::fstream file (path);
    std::cout << "file:"<< path << std::endl;

    if(file.is_open()){
        int row =0;
        while(!file.eof()){

            for (int i = 0; i < size ; ++i) {
                std::string val;
                getline(file,val,',');
                this->grid[row][i] = Cell(std::stoi(val),size);
            }
            row++;



        }
    } else{
        std::cout << "Error: No such file." << std::endl;
    }
    file.close();
}

bool Sudoku::checkCell(const int &row, const int &col, const int &val) {
    // Check for a repeated value at row and col.
    for(int i = 0; i< this->size;++i) {
        if (this->grid[row][i].getValue() == val) {
            return false;
        }
        if (this->grid[i][col].getValue() == val) {
            return false;
        }
    }
    // Check for repeated values whithin the cell's square.
    int row_boxStart = row / this->boxSize;
    int col_boxStart = col / this->boxSize;

    for (int i = row_boxStart; i < row_boxStart + this->boxSize ; ++i) {
        for (int j = col_boxStart; j < col_boxStart + this->boxSize ; ++j) {
            if(this->grid[i][j].getValue() == val){
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::solve(const int& workers) {

    // 1. Look for potential answers for each cell.

    // 2. Search an empty and unblocked cell with less potential answers.


    // No solution
    return false;
}




