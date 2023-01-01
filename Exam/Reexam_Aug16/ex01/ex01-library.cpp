#include <iostream>
#include <vector>
#include "ex01-library.h"

using namespace std;

// Exercise 1 (a)
// Check and correct if necessary
void display(double * * A, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// Exercise 1 (b)
// Implement this function
void reset(double * * A, unsigned int n, double x){
    // Put your code here
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            A[i][j] = x;
        }
    }
}

// Exercise 1 (c)
// Implement this function
vector<double> sumRows(double * * A, unsigned int n){
    // Put your code here    
    vector<double> sum;
    for(unsigned int i = 0; i < n; i++){
        sum.push_back(0);
        for(unsigned int j = 0; j < n; j++){
            sum.at(i) += A[i][j];
        }
    }
    return sum;
}

// Exercise 1 (d)
// Implement this function
vector<double> sumCols(double * * A, unsigned int n){
    // Put your code here
    vector<double> sum;
    for(unsigned int i = 0; i < n; i++){
        sum.push_back(0);
        for(unsigned int j = 0; j < n; j++){
            sum.at(j) += A[i][j];
        }
    }
    return sum;
}

// Exercise 1 (e)
// Implement this function
void reduce(double * * A, unsigned int n){
    // Put your code here
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            if(A[i][j] == 0){
                if (i == 0){
                    if (j == 0)
                        A[i][j] = A[i+1][j] + A[i][j+1];
                    else if (j == n-1)
                        A[i][j] = A[i+1][j] + A[i][j-1];
                    else
                        A[i][j] = A[i+1][j] + A[i][j-1] + A[i][j+1];
                }else if (i == n-1){
                    if (j == 0)
                        A[i][j] = A[i-1][j] + A[i][j+1];
                    else if (j == n-1)
                        A[i][j] = A[i-1][j] + A[i][j-1];
                    else
                        A[i][j] = A[i-1][j] + A[i][j-1] + A[i][j+1];
                }else if (j == 0){
                    A[i][j] = A[i-1][j] + A[i+1][j] + A[i][j+1];
                }else if(j == n-1){
                    A[i][j] = A[i-1][j] + A[i+1][j] + A[i][j-1];
                }
            }else
                A[i][j] = 0;
        }
    }
}

// Do not modify
void print(vector<double> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}