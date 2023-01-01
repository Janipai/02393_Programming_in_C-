#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c)
{
    // Write your code here
    Complex **createdMatrix = new Complex*[m];

    for (unsigned int i = 0; i < m; i++)
    {
        createdMatrix[i] = new Complex[n];
        for (unsigned int j = 0; j < n; j++)
            createdMatrix[i][j] = c;
    }

    return createdMatrix;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n)
{
    // Write your code here
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            char oper = A[i][j].im > 0 ? '+' : '-';
            cout << A[i][j].re << oper << A[i][j].im << "i";

            if (j == n - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n)
{
    // Write your code here
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         i == j ? cout << "1+0i" : cout << "0+0i" ;

    //         if (j == n - 1)
    //             cout << endl;
    //         else
    //             cout << " ";
    //     }   
    // }

    Complex zero = {0, 0};
    Complex one = {1, 0};
    Complex **A = createMatrix(n, n, zero);

    for (unsigned int i = 0; i < n; i++) {
        A[i][i] = one;
    }

    return A;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p)
{
    // Write your code here
    for (unsigned int i = 0; i < m; i++){
        for (unsigned int j = 0; j < n; j++){
            C[i][j] = {0, 0};
            for (unsigned int k = 0; k < n; k++) {
                Complex mlt = mult(A[i][k], B[k][j]);
                C[i][j] = add(C[i][j], mlt);
            }
        }
    }
}

// Do not modify
Complex add(Complex c, Complex d)
{
    Complex result = {c.re + d.re, c.im + d.im};
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d)
{
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows)
{
    for (unsigned int i = 0; i < nRows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}
