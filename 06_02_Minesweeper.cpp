// 06_02_Minesweeper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<sstream>
#include<vector>   
#include<iomanip>     
#include<cctype>      //char toupper, tolower                  
using namespace std;

void PrintData(const vector<vector<int> >& dataMinesweeper)
{
	for (size_t r = 0; r < dataMinesweeper.size(); r++)
	{		
		for (size_t c = 0; c < dataMinesweeper[r].size(); c++)
		{
			cout << dataMinesweeper[r][c];
		}
		cout << endl;
	}
	cout << endl;
}

void FillVectorWithZeros(vector<vector<int> >& dataMinesweeper, int rows, int cols)
{
	for (size_t r = 0; r < rows; r++)
	{
		vector<int>v;
		for (size_t c = 0; c < cols; c++)
		{
			v.push_back(0);
		}
		dataMinesweeper.push_back(v);
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	vector<vector<char> > dataVecCh;
	string rowsCols;
	getline(cin, rowsCols);
	string strRows, strCols;
	istringstream iss(rowsCols);
	iss >> strRows >> strCols;
	std::string::size_type sz;   // alias of size_t	
	int rows = stoi(strRows, &sz);
	int cols = stoi(strCols, &sz);
	for (size_t r = 0; r < rows; r++)
	{
		vector<char> v;
		for (size_t c = 0; c < cols; c++)
		{
			char ch;
			cin >> ch;
			v.push_back(ch);
		}
		dataVecCh.push_back(v);
	}

	//int** matrixDataMinesweeper = new int*[rows]();
	//for (int i = 0; i < rows; ++i) 
	//{
	//	matrixDataMinesweeper[i] = new int[cols]();
	//}

	vector<vector<int> > dataMinesweeper;
	FillVectorWithZeros(dataMinesweeper, rows, cols);
	
	for (size_t r = 0; r < rows; r++)
	{
		for (size_t c = 0; c < cols; c++)
		{
			if (dataVecCh[r][c] == '!')
			{
				dataMinesweeper[r][c]++;

				//TOP
				int ro = r - 1;
				if ((ro) >= 0)
				{
					dataMinesweeper[r - 1][c] ++;
					int co5 = c - 1;
					if (co5 >= 0)
					{
						dataMinesweeper[r - 1][c - 1] ++;
					}
					int co6 = c + 1;
					if (co6 < cols)
					{
						dataMinesweeper[r - 1][c + 1] ++;
					}
				}

				//MIDDLE LEFT
				int co = c - 1;
				if (co >= 0)
				{
					dataMinesweeper[r][c - 1] ++;
				}
				//MIDDLE RIGHT
				int co2 = c + 1;
				if (co2 < cols)
				{
					dataMinesweeper[r][c + 1] ++;
				}

				//DOWN
				int ro2 = r + 1;
				if (ro2 < rows)
				{
					dataMinesweeper[r + 1][c] ++;
					int co3 = c - 1;
					if (co3 >= 0)
					{
						dataMinesweeper[r + 1][c - 1] ++;
					}
					int co4 = c + 1;
					if (co4 < cols)
					{
						dataMinesweeper[r + 1][c + 1] ++;
					}
				}
			}
		}
	}	
	PrintData(dataMinesweeper);
	return 0;
}

