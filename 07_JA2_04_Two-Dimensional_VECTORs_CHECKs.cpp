// 07_JA2_04_Two-Dimensional_VECTORs_CHECKs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<iomanip> 
#include <vector>
#include<algorithm>
using namespace std;

const int maxRow = 20;
const int maxCol = 20;

void InputMatrixElements(char m[20][20], int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cin >> m[r][c];
		}
	}
}

bool IsPossibleToFillThisCell(int r, int c, char m[20][20], int rows, int cols, char startChar, char fillChar)
{
	return r >= 0 && c >= 0 &&
		r < rows && c < cols &&
		m[r][c] != fillChar &&
		m[r][c] == startChar;
}

void FillNextCell(int r, int c, char m[20][20], int rows, int cols, char fillChar, vector<int>& dataNextV, char startChar)
{
	if (IsPossibleToFillThisCell(r, c, m, rows, cols, startChar, fillChar))
	{
		m[r][c] = fillChar;
		dataNextV.push_back(r);
		dataNextV.push_back(c);
	}
}

void PrintV(vector<int>&v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl;
}

void FillWithFillChar(char m[20][20], int rows, int cols, int startRow, int startCol, char fillChar, char startChar)
{
	m[startRow][startCol] = fillChar;
	vector<int> dataV;
	dataV.push_back(startRow);
	dataV.push_back(startCol);
	vector<int> dataNextV;
	int sz = max(rows, cols);

	while (!dataV.empty()) {
		for (int i = 0; i < dataV.size(); i += 2)
		{
			int currR = dataV[i];
			int currC = dataV[i + 1];
			FillNextCell(currR - 1, currC, m, rows, cols, fillChar, dataNextV, startChar);
			FillNextCell(currR + 1, currC, m, rows, cols, fillChar, dataNextV, startChar);
			FillNextCell(currR, currC - 1, m, rows, cols, fillChar, dataNextV, startChar);
			FillNextCell(currR, currC + 1, m, rows, cols, fillChar, dataNextV, startChar);
		}
		//CHECK:
		cout << "VECTOR before to be cleared: ";
		PrintV(dataV);
		dataV.clear();

		cout << "VECTOR AFTER CLEAR() ******: ";
		PrintV(dataV);

		dataV = dataNextV;
		dataNextV.clear();
		if (dataV.empty())
		{
			break;
		}
		//CHECK:
		cout << "VECTOR NEXT: ";
		PrintV(dataV);
	}
}

void PrintMatrix(char m[20][20], int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << m[r][c];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	char m[maxRow][maxCol]{ {} };
	int rows, cols;
	cin >> rows >> cols;
	InputMatrixElements(m, rows, cols);
	char fillChar;
	cin >> fillChar;
	int startRow, startCol;
	cin >> startRow >> startCol;
	char startChar = m[startRow][startCol];
	FillWithFillChar(m, rows, cols, startRow, startCol, fillChar, startChar);
	PrintMatrix(m, rows, cols);
	return 0;
}

