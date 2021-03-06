// 05_01_Compare_Matrices.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>               
using namespace std;

bool AreTwoMatricesEqual(vector<vector<vector<int> > > v_two_nDimentionalMatices)
{
	if (v_two_nDimentionalMatices[0].size() != v_two_nDimentionalMatices[1].size()) //I have already in main() this check.
	{
		return false;
	}
	else
	{
		int numVofTwoV = v_two_nDimentionalMatices[0].size();
		for (int v2D_cols = 0; v2D_cols < numVofTwoV; v2D_cols++)
		{
			if (v_two_nDimentionalMatices[0][v2D_cols].size() != v_two_nDimentionalMatices[1][v2D_cols].size())
			{
				return false;
			}
			else
			{
				int numColsOfInternalV = v_two_nDimentionalMatices[0][v2D_cols].size();
				for (int col = 0; col < numColsOfInternalV; col++)
				{
					if (v_two_nDimentionalMatices[0][v2D_cols][col] != v_two_nDimentionalMatices[1][v2D_cols][col])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	vector<vector<vector<int> > > v_two_nDimentionalMatices;
	int tempRows = 0;
	bool isSecondTime = false;
	for (int twoMatrices = 0; twoMatrices < 2; twoMatrices++) {
		string strRows;
		getline(cin, strRows);
		istringstream iss2(strRows);
		int rows;
		iss2 >> rows;
		iss2.str().clear();
		if (isSecondTime)
		{
			if (rows != tempRows)
			{
				cout << "not equal" << endl;
				return 0;
			}
		}
		string strRow;
		vector<vector<int> > vOneMatrice;
		for (size_t i = 0; i < rows; i++)
		{
			getline(cin, strRow);
			istringstream iss(strRow);
			int num;
			vector<int> v;
			while (iss >> num)
			{
				v.push_back(num);
			}
			vOneMatrice.push_back(v);
		}
		v_two_nDimentionalMatices.push_back(vOneMatrice);
		tempRows = rows;
		isSecondTime = true;
	}
	//bool AreEqual = AreTwoMatricesEqual(v_two_nDimentionalMatices);

	if (AreTwoMatricesEqual(v_two_nDimentionalMatices))
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}

	return 0;
}

