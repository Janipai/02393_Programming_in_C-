#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n)
{
    // Replace the following with your code
    if (n < 2)
    {
        return nullptr;
    }

    Square **chessboard = new Square *[n];

    for (int i = 0; i < n; i++)
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
void displayChessboard(Square **c, unsigned int n)
{
    // Write your code here
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((c[i][j].piece == rook) && (c[i][j].team == black))
            {
                cout << "R ";
            }
            else if ((c[i][j].piece == rook) && (c[i][j].team == white))
            {
                cout << "r ";
            }
            else if ((c[i][j].piece == bishop) && (c[i][j].team == black))
            {
                cout << "B ";
            }
            else if ((c[i][j].piece == bishop) && (c[i][j].team == white))
            {
                cout << "b ";
            }
            else if ((c[i][j].piece == none) && (c[i][j].team == nobody))
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n,
          int r1, int c1, int r2, int c2)
{
    // Replace the following with your code
    // if there is a piece and its not the same team
    if ((c[r1][c1].piece != none) && (c[r1][c1].team != c[r2][c2].team))
    {
        // if it is a rook
        if (c[r1][c1].piece == rook)
        {
            // horizontal and vertical
            if (r1 == r2 || c1 == c2)
            {
                c[r2][c2] = c[r1][c1];
                c[r1][c1].team = nobody;
                c[r1][c1].piece = none;
                return true;
            }
        }
        // if it is a bishop
        else if (c[r1][c1].piece == bishop)
        {
            // diagonally
            if (abs(r1 - r2) == abs(c1 - c2))
            {
                c[r2][c2] = c[r1][c1];
                c[r1][c1].team = nobody;
                c[r1][c1].piece = none;
                return true;
            }
        }
    }
    return false;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n,
                int row, int col)
{
    // Replace the following with your code
    // check for rook horizontally
    for (int i = 0; i < n; i++)
    {
        if ((c[i][col].team != c[row][col].team) && (c[i][col].piece == rook))
        {
            return true;
        }
    }
    // check for rook vertical
    for (int i = 0; i < n; i++)
    {
        if ((c[row][i].team != c[row][col].team) && (c[row][i].piece == rook))
        {
            return true;
        }
    }
    // check for bishop diagonally
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if ((abs(x - row) == abs(y - col)))
            {
                if ((c[x][y].team != c[row][col].team) && (c[x][y].piece == bishop))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        delete[] c[i];
    }
    delete[] c;
}
