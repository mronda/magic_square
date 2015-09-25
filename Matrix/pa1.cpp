//
//  pa1.cpp
//  Matrix
//
//  Created by Maximiliano on 9/17/15.
//  Copyright (c) 2015 Maximiliano. All rights reserved.
//

#include <stdio.h>
#include "pa1.h"
#include <stdexcept>
#include <exception>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <numeric>
#include <cstdlib>

using namespace std;

Matrix::Matrix(int a)
{
    if(a % 2 == 0){
        
        throw invalid_argument("Matrix size needs to be an odd number.");
    }
    
    if(a < 3 || a > 15)
    {
        throw invalid_argument("Magic matrix has to be between 3 and 15.");
    }
    
    this->matrix_size = a;
    this->row_col_sum = ((pow(a,2) + 1) / 2) *  a; // this is the sum of the matrix 
    
}

Matrix::~Matrix()
{
    for(int i = 0; i<this->col_vector_container.size(); i++)
    {
        delete this->col_vector_container.at(i);
    }
  
}

bool Matrix::generateMagic()
{
    
    for (int i = 0; i < this->matrix_size; ++i) // pushing vectors to the back. This is the big block
    {
        this->col_vector_container.push_back(new vector<int>);
    }
    
    int i, j;
    
    int num_location;
    
    for(j=0; j<this->matrix_size; j++) //this loop read the values for ith or col
    {
        
        try {
        for(i=0; i<this->matrix_size; i++) //this read the jth or rows
        {
            
            num_location = this->matrix_size*(((i+1)+(j+1) - 1 + (this->matrix_size/2)) % this->matrix_size) + (((i+1) + 2*(j+1) - 2) % this->matrix_size) + 1;
            
            this->col_vector_container[i]->push_back(num_location);
            
        }
            
        }
        catch(exception& e) // catching something of type exception
        {
            return false;
        }
    }
    
    return true;
}

void Matrix::printMagic()
{

    
    cout << endl;
    
    for(int inner_count = 0; inner_count < this->matrix_size; inner_count++)
    {
        for(int outer_count = 0; outer_count < this->col_vector_container.size(); ++outer_count)
        {
            
            cout << this->col_vector_container.at(outer_count)->at(inner_count) << " ";
        
        }
        
        cout << endl;

    }
    
    cout << endl;
}

void Matrix::checkCols()
{
    bool printed_sum = false;
    bool print_coma = true;
    int sum_elems;
    for(int i = 0; i < this->col_vector_container.size(); i++)
    {
        sum_elems = std::accumulate(this->col_vector_container.at(i)->begin(),
                                        this->col_vector_container.at(i)->end(),0);
        assert(sum_elems == this->row_col_sum);
        
        if(!printed_sum)
        {
            cout << "Checking sum of every col: ";
        printed_sum = true;
        }
        
        if (i == this->col_vector_container.size() - 1) {
            print_coma = false;
        }
        cout << sum_elems;
        if(print_coma)
        {
            cout << ", ";
        }
    }
    cout << endl;
    
}

void Matrix::checkRows()
{
    vector<int> temp;
    bool printed_sum = false;
    bool print_coma = true;
    int sum_elems;
    
    for(int i = 0; i < this->col_vector_container.size(); ++i)
    {
        
        for(int j = 0; j < this->col_vector_container.size(); ++j)
        {
            temp.push_back(this->col_vector_container.at(j)->at(i));
        }
        
        sum_elems = std::accumulate(temp.begin(), temp.end(),0);
        
        assert(sum_elems == this->row_col_sum);
        
        if(!printed_sum)
        {
            cout << "Checking sum of every row: ";
            printed_sum = true;
        }
        
        if (i == this->col_vector_container.size() - 1) {
            print_coma = false;
        }
        cout << sum_elems;
        if(print_coma)
        {
            cout << ", ";
        }
        
        temp.clear();

    }
    
    cout << endl;
}

void Matrix::checkDiag()
{
    int sum_elems;
    int sum_elems2;
    vector<int> temp;
    vector<int> temp2;
    int index = (int)this->col_vector_container.size() - 1;
    // first diag:
    for(int i = 0; i < this->col_vector_container.size(); i++)
    {
        temp.push_back(this->col_vector_container.at(i)->at(i));
    }
    
    
    for(int i = 0; i < this->col_vector_container.size(); i++)
    {
        temp2.push_back(this->col_vector_container.at(i)->at(index));
        index--;
    }
    
    sum_elems2 = std::accumulate(temp2.begin(), temp2.end(),0);

    sum_elems = std::accumulate(temp.begin(), temp.end(),0);
    cout << "Checking sum of every diag: " << sum_elems << ", " << sum_elems2 << endl;
    
}

void Matrix::checkSum()
{
    Matrix::checkCols();
    
    Matrix::checkRows();
    
    Matrix::checkDiag();
}

// Main file

int main()
{
    
    int a;
    
    cout<<"What is the matrix size: ";
    
    cin>> a;
    
    Matrix* mat;
    
    try
    {
        
        mat = new Matrix(a);
        
    }
    catch(const invalid_argument& ia)
    {
        cerr << ia.what() << endl;
        
        return -1;
    }
    
    if(mat->generateMagic())
    {
        cout <<"One magic square is: " << endl;
        mat->printMagic();
        
        mat->checkSum();
    }
    
    else return -1;
    
    delete mat;
    
    return 0;
    
    
}

