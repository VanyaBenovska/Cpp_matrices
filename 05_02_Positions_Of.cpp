// 05_02_Positions_Of.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<sstream>
#include<iomanip>                   
#include <vector>
using namespace std;

vector<int> FindAppearances(const vector<vector<int> >& vData, const int& numberToFind)
{
	vector<int> v;
	for (int r = 0; r < vData.size(); r++)
	{
		for (int c = 0; c < vData[r].size(); c++)
		{
			if (numberToFind == vData[r][c])
			{
				v.push_back(r);
				v.push_back(c);
			}
		}
	}
	return v;
}

void PrintDataAppearances(const vector<int>& coordinatesOfAppearances)
{
	for (size_t i = 0; i < coordinatesOfAppearances.size(); i += 2)
	{
		cout << coordinatesOfAppearances[i] << " " << coordinatesOfAppearances[i + 1] << endl;
	}
	cout << endl;
}

void PrintV(const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	string strRowsCols, line1, line2;
	getline(cin, strRowsCols);
	istringstream iss(strRowsCols);
	int rows, cols;
	iss >> rows >> cols;
	vector<vector<int> > vData;
	for (size_t r = 0; r < rows; r++)
	{
		vector<int> v;
		for (size_t c = 0; c < cols; c++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}
		//PrintV(v);
		vData.push_back(v);
	}
	int numberToFind;
	cin >> numberToFind;
	int sizeOfV = 0;
	vector<int> coordinatesOfAppearances = FindAppearances(vData, numberToFind);
	if (coordinatesOfAppearances.empty())
	{
		cout << "not found" << endl;
	}
	else
	{
		PrintDataAppearances(coordinatesOfAppearances);
	}
	return 0;
}

