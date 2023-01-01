#include <iostream>
#include <vector>
#include "ex01-library.h"

using namespace std;

// Exercise 1 (a)
// Check and correct if necessary
void display(double *A, unsigned int n){
    for(unsigned int i = 1; i <= n; i++){
        for(unsigned int j = 1; j <= n; j++){
            cout << A[i*n+j] << " ";
        }
        cout << endl;
    }
}

// Exercise 1 (b)
// Implement this function
void reset(double *A, unsigned int n, double x){
    // Put your code here
}

// Exercise 1 (c)
// Implement this function
void reduce(double * A, unsigned int n){
    
    // Put your code here
    
}

// Exercise 1 (d)
// Implement this function
vector<double> sumRows(double * A, unsigned int n){
    
    // Put your code here
    
}

// Exercise 1 (e)
// Implement this function
vector<double> sumCols(double * A, unsigned int n){
    
    // Put your code here
    
}

// Do not modify
void print(vector<double> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}