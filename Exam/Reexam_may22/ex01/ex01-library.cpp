#include <iostream>
#include "ex01-library.h"
#include <stdlib.h>

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int m, unsigned int n){
    // Replace the following with your code

    if (m < 2 | n < 2){return nullptr;}

    Square** chessboard = new Square*[m];

    for (int i = 0; i < m; i++)
    {
        chessboard[i] = new Square[n];
        for (int j = 0; j < n; j++)
        {
            chessboard[i][j].team = nobody;
            chessboard[i][j].piece = none;
        }
        
    }


    return chessboard;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c,unsigned int m, unsigned int n){
    // Write your code here

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((c[i][j].piece == king) && (c[i][j].team == black)){cout << "K ";}
            else if ((c[i][j].piece == king) && (c[i][j].team == white)){cout << "k ";}
            else if ((c[i][j].piece == queen) && (c[i][j].team == black)){cout << "Q ";}
            else if ((c[i][j].piece == queen) && (c[i][j].team == white)){cout << "q ";}
            else if ((c[i][j].piece == none) && (c[i][j].team == nobody)){cout << "_ ";}
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int m, unsigned int n,
          int r1, int c1, int r2, int c2)
{
    // Replace the following with your code

    // if there is a piece and its not the same team
    if ((c[r1][c1].piece != none) && (c[r1][c1].team != c[r2][c2].team)){
        // if it is a queen
        if (c[r1][c1].piece == queen){
            //horizontal and vertical
            if(r1 == r2 || c1 == c2){
                c[r2][c2] = c[r1][c1];
                c[r1][c1].team = nobody;
                c[r1][c1].piece= none;
                return true;
            } 
            // diagonally 
            else if (abs(r1 - r2) == abs(c1 - c2)){
                c[r2][c2] = c[r1][c1];
                c[r1][c1].team = nobody;
                c[r1][c1].piece= none;
                return true;
            }
        }
        // if it is a king
        else if (c[r1][c1].piece == king){
            // horizontally or vertical and diagonally
            if ((abs(r2 - r1) <= 1) && (abs(c2 - c1) <= 1)){
                c[r2][c2] = c[r1][c1];
                c[r1][c1].team = nobody;
                c[r1][c1].piece= none;
                return true;
            }
        }
    }
    return false;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int m, unsigned int n, int row, int col){
    // Replace the following with your code
    
        //check for queens horizontally
        for (int i = 0; i < m; i++){
            if((c[i][col].team != c[row][col].team) && (c[i][col].piece == queen)){ 
                return true;}
        }
        //vertical
        for (int i = 0; i < n; i++)
        {
            if((c[row][i].team != c[row][col].team) && (c[row][i].piece == queen)){ 
                return true;}
        }
        // diagonally
        for (int x = 0; x < m; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if ((abs(x - row) == abs(y - col))){
                    if((c[x][y].team != c[row][col].team) && (c[x][y].piece == queen)){
                        return true;
                    }
                }   
            }   
        }   
        
        // if it is a king
        int min_row = row-1;
        int max_row = row+1;
        int min_col = col-1;
        int max_col = col+1;

        if (row == 0){
            min_row = 0;
        }else if(row == m-1){
            max_row = m-1;
        }
        if (col == 0){
            min_col = 0;
        } else if(col == n-1){
            max_col = n-1;
        }

        for (int i = min_row; i <= max_row; i++){
            for (int j = min_col; j <= max_col; j++){
                if ((i != row) && (j != col)){
                    continue;
                }
                else if((c[i][j].piece == king) && (c[i][j].team != c[row][col].team)){
                    return true;
                }
            }
        }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int m)
{
    for (unsigned int i = 0; i < m; i++)
    {
        delete[] c[i];
    }
    delete[] c;
}
