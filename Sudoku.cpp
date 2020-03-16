//
// Created by Patricio Araya on 3/15/20.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include "Sudoku.h"

Sudoku::Sudoku(int size) : size(size) {
    this->squareSize = sqrt(size);
    this->grid = new int*[size];

    for(int i = 0; i<size;++i){
        grid[i] = new int[size];
    }

    for(int i= 0;i<size;++i){
        for (int j = 0; j < size; ++j) {
            grid[i][j] = i;
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
        os <<"|";
        for (int j = 0; j < sudoku.size ; ++j) {
            os << sudoku.grid[i][j]<<"|";
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
                this->grid[row][i] = std::stoi(val);
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
        if (this->grid[row][i] == val) {
            return false;
        }
        if (this->grid[i][col] == val) {
            return false;
        }
    }
    // Check for repeated values whithin the cell's square.
    int row_squareStart = row/this->squareSize;
    int col_squareStart = col/this->squareSize;

    for (int i = row_squareStart; i <row_squareStart+this->squareSize ; ++i) {
        for (int j = col_squareStart; j <col_squareStart+this->squareSize ; ++j) {
            if(this->grid[i][j] == val){
                return false;
            }
        }
    }

    return true;
}




