// 06_03_Rust_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<vector>   
#include<iomanip> 
using namespace std;

//KЛАСИЧЕСКИ, СТАНДАРТЕН АЛГОРИТЪМ В ПРОГРАМИРАНЕТО:
//„ТЪРСЕНЕ В ШИРИНА” 
//Google Ползва нещо подобно, когато питаме за най-краткия път от София до Пловдив примерно

void ReadInput(char ** ppMatrix, int rows, int cols, int& influence)
{
	for (size_t r = 0; r < rows; r++)
	{
		for (size_t c = 0; c < cols; c++)
		{
			char ch;
			cin >> ch;
			ppMatrix[r][c] = ch;
		}
	}
	cin >> influence;

	//CHECK:
	/*PrintppMatrix(ppMatrix, 10, 10);
	cout << endl;
	cout << "INFLUENCE: " << influence << endl;
	cout << "************************************" << endl;*/
}

char ** CreateppMatrix()
{
	char ** ppMatrix = new char *[10]();
	for (int i = 0; i < 10; i++)
	{
		ppMatrix[i] = new char[10]();
	}
	return ppMatrix;
}

vector<int> FindTheStartPoint(char ** ppMatrix, int r, int c)
{
	vector<int> vCore;
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 10; col++)
		{
			if (ppMatrix[row][col] == '!')
			{
				vCore.push_back(row);
				vCore.push_back(col);
				return vCore;
			}
		}
	}
	return vCore;
}
bool IsValidCell(int r, int c)
{
	return (r >= 0 && c >= 0 &&
		r < 10 && c < 10);
}

void Spread(int r, int c, char ** ppMatrix, vector<int>& dataNextStepSpreading)
{
	if (IsValidCell(r, c) && ppMatrix[r][c] != '#')
	{
		ppMatrix[r][c] = '!';
		dataNextStepSpreading.push_back(r);
		dataNextStepSpreading.push_back(c);
	}
}

void SpreadingTheInfluence(char ** ppMatrix, int r, int c, int influence, vector<int>& dataSpreading)
{
	vector<int> dataNextStepSpreading;
	for (int i = 0; i < influence; i++)
	{
		for (int t = 0; t < dataSpreading.size(); t += 2)
		{
			int rr = dataSpreading[t];
			int cc = dataSpreading[t + 1];
			Spread(rr - 1, cc, ppMatrix, dataNextStepSpreading);
			Spread(rr + 1, cc, ppMatrix, dataNextStepSpreading);
			Spread(rr, cc - 1, ppMatrix, dataNextStepSpreading);
			Spread(rr, cc + 1, ppMatrix, dataNextStepSpreading);
		}
		dataSpreading.empty();
		dataSpreading = dataNextStepSpreading;
	}
}

void PrintTheResultMatrix(char ** ppMatrix, int r, int c)
{
	for (int row = 0; row < 10; row++)
	{
		for (int col = 0; col < 10; col++)
		{
			cout << ppMatrix[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	char ** ppMatrix = CreateppMatrix();

	int influence = 0;
	ReadInput(ppMatrix, 10, 10, influence);
	//coordinates of The Core:
	vector<int> dataSpreading = FindTheStartPoint(ppMatrix, 10, 10);
	SpreadingTheInfluence(ppMatrix, 10, 10, influence, dataSpreading);
	PrintTheResultMatrix(ppMatrix, 10, 10);
	delete[] ppMatrix;
	return 0;
}

