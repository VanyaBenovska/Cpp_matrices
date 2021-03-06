// 05_03_Merge_Trains.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void FillAll_A_elementsInResultAB(stack<int> stA, stack<int>& resultAB, vector<char>& vCharAB)
{
	while (!stA.empty())
	{
		resultAB.push(stA.top());
		stA.pop();
		vCharAB.push_back('A');
	}
}

void FillAll_B_elementsInResultAB(stack<int> stB, stack<int>& resultAB, vector<char>& vCharAB)
{
	while (!stB.empty())
	{
		resultAB.push(stB.top());
		stB.pop();
		vCharAB.push_back('B');
	}
}

void ComposeAB(stack<int> stA, stack<int> stB, vector<char>& vCharAB, stack<int>& resultAB)
{
	bool isFinished = false;
	while (!stA.empty() || !stB.empty())
	{
		if (stA.empty())
		{
			FillAll_B_elementsInResultAB(stB, resultAB, vCharAB);
		}
		else if (stB.empty())
		{
			FillAll_A_elementsInResultAB(stA, resultAB, vCharAB);
		}
		else
		{
			int numA = stA.top();
			int numB = stB.top();
			//bool numIsNotEntered = true;
			while (!stA.empty() || !stB.empty()) {
				if (numA > numB)
				{
					resultAB.push(numB);
					stB.pop();
					vCharAB.push_back('B');
					if (!stB.empty()) {
						numB = stB.top();
					}
					else
					{
						FillAll_A_elementsInResultAB(stA, resultAB, vCharAB);
						isFinished = true;
						break;
					}
				}
				else if (numB > numA)
				{
					resultAB.push(numA);
					stA.pop();
					vCharAB.push_back('A');
					if (!stA.empty()) {
						numA = stA.top();
					}
					else
					{
						FillAll_B_elementsInResultAB(stB, resultAB, vCharAB);
						isFinished = true;
						break;
					}
				}
				else //numA == numB
				{
					resultAB.push(numA);
					resultAB.push(numB);

					stA.pop();
					vCharAB.push_back('A');
					stB.pop();
					vCharAB.push_back('B');
					if (!stA.empty()) {
						numA = stA.top();
					}
					else
					{
						FillAll_B_elementsInResultAB(stB, resultAB, vCharAB);
						isFinished = true;
						break;
					}
					if (!stB.empty()) {
						numB = stB.top();
					}
					else
					{
						FillAll_A_elementsInResultAB(stA, resultAB, vCharAB);
						isFinished = true;
						break;
					}
					if (isFinished)
					{
						break;
					}
				}
				if (isFinished)
				{
					break;
				}
			}
			if (isFinished)
			{
				break;
			}
		}
		/*if (isFinished)
		{
			break;
		}*/
	}
}

void PrintStackResultIntAB(stack<int> st)
{
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void PrintCharResultAB(const vector<char>& v)
{
	for (char charSign : v)
	{
		cout << charSign;
	}
	cout << endl;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	stack<int> stA, stB;
	string strA, strB;

	getline(cin, strA);
	int num;
	istringstream issA(strA);
	while (issA >> num)
	{
		stA.push(num);
	}
	getline(cin, strB);
	istringstream issB(strB);
	while (issB >> num)
	{
		stB.push(num);
	}
	vector<char> vCharAB;
	stack<int> resultIntAB;

	ComposeAB(stA, stB, vCharAB, resultIntAB);
	PrintCharResultAB(vCharAB);
	PrintStackResultIntAB(resultIntAB);

	return 0;
}

