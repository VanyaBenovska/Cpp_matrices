// 07_JA2_04_Two-Dimen_DEPTH-FIRST-SEARCH---STACK_CHECKs.cpp : Defines the entry point for the console application.
//

//07_JA2_04_Two-Dimen_DEPTH-FIRST-SEARCH---STACK_CHECKs
// ТЪРСЕНЕ В ДЪЛБОЧИНА

#include "stdafx.h"
#include<iostream>
#include <string>
#include<iomanip>  
#include <stack>
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

void FillNextCell(int r, int c, char m[20][20], int rows, int cols, char fillChar, stack<int>& dataSt, char startChar)
{
	if (IsPossibleToFillThisCell(r, c, m, rows, cols, startChar, fillChar))
	{
		m[r][c] = fillChar;
		dataSt.push(r);
		dataSt.push(c);
	}
}

void PrintStack(stack<int>st)
{
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
		cout << ", ";
	}
	cout << endl;
}

void FillWithFillChar(char m[20][20], int rows, int cols, int startRow, int startCol, char fillChar, char startChar)
{
	m[startRow][startCol] = fillChar;
	stack<int> dataSt;
	dataSt.push(startRow);
	dataSt.push(startCol);
	//CHECK:
	PrintStack(dataSt);

	while (!dataSt.empty())
	{

		int currC = dataSt.top();
		dataSt.pop();
		int currR = dataSt.top();
		dataSt.pop();
		//CHECK:
		PrintStack(dataSt);

		FillNextCell(currR - 1, currC, m, rows, cols, fillChar, dataSt, startChar);
		//CHECK:
		cout << "AFTER cell UP: ";
		PrintStack(dataSt);
		FillNextCell(currR + 1, currC, m, rows, cols, fillChar, dataSt, startChar);
		//CHECK:
		cout << "AFTER cell DOWN: ";
		PrintStack(dataSt);
		FillNextCell(currR, currC - 1, m, rows, cols, fillChar, dataSt, startChar);
		//CHECK:
		cout << "AFTER cell RIGHT: ";
		PrintStack(dataSt);
		FillNextCell(currR, currC + 1, m, rows, cols, fillChar, dataSt, startChar);
		//CHECK:
		cout << "AFTER cell LEFT: ";
		PrintStack(dataSt);

		//dataV.clear();
		//dataV = dataNextV;
		//dataNextV.clear();		
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

