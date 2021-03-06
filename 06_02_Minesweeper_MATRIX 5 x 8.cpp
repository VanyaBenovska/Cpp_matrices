// 06_02_Minesweeper_MATRIX 5 x 8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

//!!!   INPUT  5x8   ONLY

/*  5 8
........
...!....
....!...
........
...!....*/

bool validPosition(int r, int c) {

	return r >= 0 && c >= 0 &&
		r < 5 && c < 8;
}

int countAdjMinesInMatrix(int r, int c, char minesField[5][8], int adjacentMines)
{
	if (minesField[r - 1][c - 1] == '!' && validPosition(r - 1, c - 1)) {
		adjacentMines++;
	}
	if (minesField[r - 1][c] == '!' && validPosition(r - 1, c)) {
		adjacentMines++;
	}
	if (minesField[r - 1][c + 1] == '!' && validPosition(r - 1, c + 1)) {
		adjacentMines++;
	}


	if (minesField[r][c - 1] == '!' && validPosition(r, c - 1)) {
		adjacentMines++;
	}
	if (minesField[r][c] == '!' && validPosition(r, c)) {
		adjacentMines++;
	}
	if (minesField[r][c + 1] == '!' && validPosition(r, c + 1)) {
		adjacentMines++;
	}


	if (minesField[r + 1][c - 1] == '!' && validPosition(r + 1, c - 1)) {
		adjacentMines++;
	}
	if (minesField[r + 1][c] == '!' && validPosition(r + 1, c)) {
		adjacentMines++;
	}
	if (minesField[r + 1][c + 1] == '!' && validPosition(r + 1, c + 1)) {
		adjacentMines++;
	}
	return adjacentMines;
}

void PrintMatrix(int m[5][8], int r, int c)
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			cout << m[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	char minesField[5][8];

	//5 x 8

	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			cin >> minesField[row][col];
		}
	}
	int adjacentMines[5][8];
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			int count = 0;
			adjacentMines[r][c] = countAdjMinesInMatrix(r, c, minesField, count);
		}
	}
	PrintMatrix(adjacentMines, 5, 8);

	return 0;

	//!!!   INPUT  5x8   ONLY

	/*5 8
	........
	...!....
	....!...
	........
	...!....*/
}

