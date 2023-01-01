#include <iostream>
#include <random>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createCavern(unsigned int m, unsigned int n) {
    // Replace the following with your code
    Tile **cavern = new Tile*[m];
    for (unsigned int i = 0; i < m; i++)
    {
        cavern[i] = new Tile[n];
        for (unsigned int j = 0; j < n; j++)
        {
            cavern[i][j].content = nothing;
            cavern[i][j].explored = false;
            
        }   
    }
    return cavern;
}

// Task 1(b).  Implement this function
void revealCavern(Tile **cav, unsigned int m, unsigned int n) {
    // Write your code here
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
            if (cav[i][j].content == player) 
                cout << "X";
            else if (cav[i][j].content == nothing) 
                cout << " "; 
            else if (cav[i][j].content == rock) 
                cout << "#";  
            else if (cav[i][j].content == wumpus) 
                cout << "W";             
        }   
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool movePlayer(Tile **cav, int m, int n, int r, int c) {
    // Replace the following with your code
    unsigned int rplayer = 0;
    unsigned int cplayer = 0;
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
           if (cav[i][j].content == player){
            rplayer = i;
            cplayer = j;   
            break;      
           }      
        }   
    }

    int arplayer = rplayer - r;
    int acplayer = cplayer - c;

    arplayer = abs(arplayer);
    acplayer = abs(acplayer);
    if ((0 > r) || (r > m) || (0 > c) || (c > n))
        return false;        
    else if ((arplayer < 5) || (acplayer < 5))
        return false;
    else if (cav[r][c].content != nothing)
        return false;
    else if ((rplayer == r) && (cplayer == c))
        return false;

    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
                cav[i][j].content = nothing;
                cav[r][c].content = player;
                return true;
        }   
        cout << endl;
    }
}

// Task 1(d).  Implement this function
void drawCavern(Tile **cav, unsigned int m, unsigned int n) {
    // Write your code here
    unsigned int rplayer = 0;
    unsigned int cplayer = 0;
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < n; j++)
        {
           if (cav[i][j].content == player){
            rplayer = i;
            cplayer = j;         
           }      
        }   
    }

    int rrplayer = 0;
    int ccplayer = 0;
    for (unsigned int i = 0; i < m; i++){
        for (unsigned int j = 0; j < n; j++){
            rrplayer = rplayer - i;
            ccplayer = cplayer - j;
           if (sqrt(pow(rrplayer,2) + pow(ccplayer,2)) < 4){
                if (cav[i][j].content == player) {
                    cout << "X"; 
                    cav[i][j].explored = true;
                }
                else if (cav[i][j].content == nothing){
                    cout << " ";
                    cav[i][j].explored = true;
                }
                else if (cav[i][j].content == rock){ 
                    cout << "#";  
                    cav[i][j].explored = true;

                }
                else if (cav[i][j].content == wumpus) {
                    cout << "W"; 
                    cav[i][j].explored = true;
                }
           }else{
            if (cav[i][j].explored == true)
            {
                if (cav[i][j].content == rock)
                    cout << "#";  
                else if (cav[i][j].content == nothing)
                    cout << "-"; 
            }else
                cout << "?";
            
           }      
        } 
        cout << endl;  
    }
}

// Do not modify the following function.
// This code (that you don't need to read) places the player
// at location (0,0) and pseudo-randomly places some rocks
// and a Wumpus. The pseudo-random placement depends on the
// value of 'seed'.
void setupCavern(Tile **cav, unsigned int m, unsigned int n,
                 unsigned int seed) {
    mt19937 e; // Pseudo-random number generator
    e.seed(seed);

    // 1/3rd of the tiles are rocks
    unsigned int rocks = (m * n) / 3;
    for (unsigned int i = 0; i < rocks; i++) {
        cav[e()%m][e()%n].content = rock;
    }

    // We never place the Wumpus on row 0 or column 0
    unsigned int row = (e() % (m-1)) + 1;
    unsigned int col = (e() % (n-1)) + 1;
    cav[row][col].content = wumpus;

    cav[0][0].content = player;
}

// Do not modify the following function.
void deleteCavern(Tile **c, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] c[i];
    }
    delete[] c;
}
