// 06_02_Minesweeper_Georgi Georgiev.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

void countIfMined(int row, int col, vector<vector<char> > minesField, int& minesCount )
{
	bool validPosition = row >= 0 && col >= 0 && 
		row < minesField.size() && col < minesField[row].size();

	if (validPosition && minesField[row][col] == '!')
	{
		minesCount++;
	}
}


int countAdjMines(int row, int col, vector<vector<char> > mineField)
{
	//за всяка една съседна клетка викаме разрешаващата функция за добавяне на 1
	//вкл. и за самата клетка

	int minesCount = 0;
	//искаме MinesCount да ни се увеличава на този ред и на тази колона:
	countIfMined(row - 1, col - 1, mineField, minesCount);
	countIfMined(row - 1, col, mineField, minesCount);
	countIfMined(row - 1, col + 1, mineField, minesCount);

	countIfMined(row, col - 1, mineField, minesCount);
	countIfMined(row, col, mineField, minesCount);
	countIfMined(row, col + 1, mineField, minesCount);

	countIfMined(row + 1, col - 1, mineField, minesCount);
	countIfMined(row + 1, col, mineField, minesCount);
	countIfMined(row + 1, col + 1, mineField, minesCount);

	//3 групи с по 3 реда: ПО Excel, там сме си го разписали

	return minesCount;
}

int main()
{
	int numRows, numCols;
	cin >> numRows >> numCols;

	vector<vector<char> > minefield;
	//ИЛИ
	//vector<vector<string> > v;  // И ВСЕКИ РЕД ДА СИ ГО getline() , но няма да е консистентно с матрицата на бройките
	
	for (int row = 0; row < numRows; row++)
	{
		vector <char> currentRow;
		for (int col = 0; col < numCols; col++)
		{
			char cell;
			cin >> cell;
			currentRow.push_back(cell);
		}
		minefield.push_back(currentRow);
	}
	vector<vector<int> > adjacentMines;
	for (int row = 0; row < numRows; row++)
	{		
		vector<int> currentRowCount;
		for (int col = 0; col < numCols; col++)
		{
			int minesCount = countAdjMines(row, col, minefield);

			currentRowCount.push_back(minesCount);
		}	
		adjacentMines.push_back(currentRowCount);
	}

	for (vector<int> row : adjacentMines)
	{
		for (int mineCount : row)
		{
			cout << mineCount;
		}
		cout << endl;
	}

    return 0;
}

