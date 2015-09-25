//
//  pa1.h
//  Matrix
//
//  Created by Maximiliano on 9/17/15.
//  Copyright (c) 2015 Maximiliano. All rights reserved.
//

#ifndef Matrix_pa1_h
#define Matrix_pa1_h

#include <vector>

using namespace std;

class Matrix
{
private: 
    
    vector<vector<int>*> col_vector_container;
    int matrix_size;
    int row_col_sum;
    void checkCols();
    void checkRows();
    void checkDiag();

public:
    
    Matrix(int);
    ~Matrix();
    
    bool generateMagic();
    void printMagic();
    void checkSum();
    
};

#endif
