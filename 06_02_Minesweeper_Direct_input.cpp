// 06_02_Minesweeper_Direct_input.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

void FillVectorWithZeros(vector<vector<int> >& v, int numRows, int numCols) {
	for (int row = 0; row < numRows; row++)
	{
		vector <int> currentRow;
		for (int col = 0; col < numCols; col++)
		{
			currentRow.push_back(0);
		}
		v.push_back(currentRow);
	}
}

void ReadInputCharMatrixAndFillInVector(vector<vector<int> >& v, int numRows, int numCols)
{
	for (int r = 0; r < numRows; r++)
	{		
		for (int c = 0; c < numCols; c++)
		{
			char ch;
			cin >> ch;
			if (ch == '!')
			{
				v[r][c] ++;

				if (r - 1 >= 0)
				{
					v[r - 1][c]++;
					if (c - 1 >= 0)
					{
						v[r - 1][c - 1]++;
					}
					if (c + 1 < numCols)
					{
						v[r - 1][c + 1]++;
					}
				}
				if (c - 1 >= 0)
				{
					v[r][c - 1]++;
				}
				if (c + 1 < numCols)
				{
					v[r][c + 1]++;
				}
				if (r + 1 < numRows)
				{
					v[r + 1][c]++;
					if (c - 1 >= 0)
					{
						v[r + 1][c - 1]++;
					}
					if (c + 1 < numCols)
					{
						v[r + 1][c + 1]++;
					}
				}
			}
		}
	}
}
void PrintVector(vector<vector<int> >& v, int numRows, int numCols)
{
	for (int row = 0; row < numRows; row++)
	{		
		for (int col = 0; col < numCols; col++)
		{
			cout << v[row][col];
		}		
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int numRows, numCols;
	cin >> numRows >> numCols;
	vector<vector<int> > minefield;
	FillVectorWithZeros(minefield, numRows, numCols);

	ReadInputCharMatrixAndFillInVector(minefield, numRows, numCols);	

	PrintVector(minefield, numRows, numCols);

	return 0;
}

