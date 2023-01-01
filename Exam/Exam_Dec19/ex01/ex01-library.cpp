#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	//put your code here
	cell **checkersBoard = new cell*[n];
	for (int i = 0; i < n; i++){
		checkersBoard[i] = new cell[n];
		for (int j = 0; j < n; j++){
			checkersBoard[i][j].color = computeColor(i,j);
			checkersBoard[i][j].status = emptyC;
				if ((i < 3) && (checkersBoard[i][j].color == dark))
					checkersBoard[i][j].status = blackPiece;
				if ((i >= n - 3) && (checkersBoard[i][j].color == dark))
					checkersBoard[i][j].status = whitePiece;
		}
	}
	return checkersBoard;
}

//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n){
	//put your code here
	cell **B = new cell*[n];
	for (int i = 0; i < n; i++){
		B[i] = new cell[n];
		for (int j = 0; j < n; j++){
			B[i][j] = A[i][j];
		}
	}

	return B;
}

//Exercise 1 (c) Implement this function
bool moveRight(cell ** A,int n,int r, int c){
	//put your code here
	//outside the board
	if (0 > r || r >= n || 0 > c || c >= n)
		return false;
	//source cell empty
	if (A[r][c].status == emptyC)
		return false;
	int toR = -1;
	int toC = -1;
	if (A[r][c].status == blackPiece){
		toR = r+1;
		toC = c-1;
	}else{
		toR = r-1;
		toC = c+1;
	}
	if (0 > toR || toR >= n || 0 > toC || toC >= n)
		return false;
	//source cell empty
	if (A[toR][toC].status != emptyC)
		return false;
	cellStatus status = A[r][c].status;
	A[r][c].status = emptyC;
	A[toR][toC].status = status;
	return true;
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c){
	//put your code here
	//outside the board
	if (0 > r || r >= n || 0 > c || c >= n)
		return false;
	//source cell empty
	if (A[r][c].status == emptyC)
		return false;
	int toR = -1;
	int toC = -1;
	if (A[r][c].status == blackPiece){
		toR = r+1;
		toC = c+1;
	}else{
		toR = r-1;
		toC = c-1;
	}
	if (0 > toR || toR >= n || 0 > toC || toC >= n)
		return false;
	//source cell empty
	if (A[toR][toC].status != emptyC)
		return false;
	cellStatus status = A[r][c].status;
	A[r][c].status = emptyC;
	A[toR][toC].status = status;
	return true; 
}

//Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	cout << ' ';
	for(int c=0;c<n;c++){
		cout << c;
	}
	cout << endl;
	for(int r=0;r<n;r++){
		cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status) {
			case emptyC:
				cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
