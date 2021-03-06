// 06_03_Rust.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<sstream>
#include<vector>   
#include<iomanip> 
using namespace std;

int wallCenterRow = -1, wallCenterCol = -1, wallLength = 0;
bool wallCenterIsNotFound = true;

void PrintppMatrix(char ** ppMatrix, int rows, int cols)
{
	for (size_t r = 0; r < rows; r++)
	{
		for (size_t c = 0; c < cols; c++)
		{
			cout << ppMatrix[r][c];
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
	for (int i = 0; i < 10; ++i)
	{
		ppMatrix[i] = new char[10]();
	}
	return ppMatrix;
}

void FindTheCore(char ** ppMatrix, int rows, int cols, int& coreR, int& coreC)
{
	bool isFound = false;
	for (size_t r = 0; r < 10; r++)
	{
		for (size_t c = 0; c < 10; c++)
		{
			//char chValue = (ppMatrix[r][c]);
			if (ppMatrix[r][c] == '!')
			{
				coreR = r;
				coreC = c;
				isFound = true;
				break;
			}
		}
		if (isFound)
		{
			break;
		}
	}
}

void FindTheWAllCenter(char ** ppMatrix, int rows, int cols, int coreR, int coreC)
{
	int coreR_origin = coreR;
	int coreC_origin = coreC;
	//goup
	while (coreR - 1 >= 0)
	{
		coreR--;
		if (ppMatrix[coreR][coreC] == '#')
		{
			wallCenterRow = coreR;
			wallCenterCol = coreC;
			wallCenterIsNotFound = false;
			break;
		}
	}
	//godown
	if (wallCenterIsNotFound)
	{
		coreR = coreR_origin;
		coreC = coreC_origin;
		while (coreR + 1 < 10)
		{
			coreR++;
			if (ppMatrix[coreR][coreC] == '#')
			{
				wallCenterRow = coreR;
				wallCenterCol = coreC;
				wallCenterIsNotFound = false;
				break;
			}
		}
	}
	//goright
	if (wallCenterIsNotFound)
	{
		coreR = coreR_origin;
		coreC = coreC_origin;
		while (coreC + 1 < 10)
		{
			coreC++;
			if (ppMatrix[coreR][coreC] == '#')
			{
				wallCenterRow = coreR;
				wallCenterCol = coreC;
				wallCenterIsNotFound = false;
				break;
			}
		}
	}
	//goleft
	if (wallCenterIsNotFound)
	{
		coreR = coreR_origin;
		coreC = coreC_origin;
		while (coreC - 1 >= 0)
		{
			coreC--;
			if (ppMatrix[coreR][coreC] == '#')
			{
				wallCenterRow = coreR;
				wallCenterCol = coreC;
				//wallLength;
				wallCenterIsNotFound = false;
				break;
			}
		}
	}
}

void CountWallLengthHorizontally(char ** ppMatrix, int rows, int cols)
{
	int halfCount = 0;
	int tempWallCenterCol = wallCenterCol;
	while (tempWallCenterCol - 1 >= 0)
	{
		tempWallCenterCol--;
		if (ppMatrix[wallCenterRow][tempWallCenterCol] == '#')
		{
			halfCount++;
		}
		else
		{
			break;
		}
	}
	wallLength = halfCount * 2 + 1;
}

void CountWallLengthVertically(char ** ppMatrix, int rows, int cols)
{
	int halfCount = 0;
	int tempWallCenterRow = wallCenterRow;
	while (tempWallCenterRow - 1 >= 0)
	{
		tempWallCenterRow--;
		if (ppMatrix[tempWallCenterRow][wallCenterCol] == '#')
		{
			halfCount++;
		}
		else
		{
			break;
		}
	}
	wallLength = halfCount * 2 + 1;
}

void PaintLeft()
{

}
void PaintRight()
{

}
void PaintUp()
{

}
void PaintDown()
{

}
void PaintFreely_Left_Right_and_Down(char ** ppMatrix, int rows, int cols, int coreR, int coreC, int influence)
{
	int coreR_origin = coreR;
	int coreC_origin = coreC;
	int influence_current_Down = influence;
	int influence_origin = influence;		

	int nextRow = coreR + 1;
	while (nextRow < 10 && influence_current_Down >= 0) {
		nextRow = coreR;
		coreC = coreC_origin;
		ppMatrix[coreR][coreC] = '!';
		int influenceCurren_LeftRight = influence_current_Down;

		//left
		while (coreC - 1 >= 0 && influenceCurren_LeftRight > 0)
		{
			coreC--;
			influenceCurren_LeftRight--;
			ppMatrix[coreR][coreC] = '!';
		}
		//right
		coreC = coreC_origin;
		influenceCurren_LeftRight = influence_current_Down;
		while (coreC + 1 < 10 && influenceCurren_LeftRight > 0)
		{
			coreC++;
			influenceCurren_LeftRight--;
			ppMatrix[coreR][coreC] = '!';
		}
		nextRow++;
		coreR = nextRow;
		influence_current_Down--;
	}
}

void PaintFreely_Left_Right_and_Up(char ** ppMatrix, int rows, int cols, int coreR, int coreC, int influence)
{
	int coreR_origin = coreR;
	int coreC_origin = coreC;
	int influence_current_Up = influence;
	int influence_origin = influence;		

	int nextRow = coreR - 1;
	while (nextRow >= 0 && influence_current_Up >= 0) {
		nextRow = coreR;
		coreC = coreC_origin;
		ppMatrix[coreR][coreC] = '!';
		int influenceCurren_LeftRight = influence_current_Up;

		//left
		while (coreC - 1 >= 0 && influenceCurren_LeftRight > 0)
		{
			coreC--;
			influenceCurren_LeftRight--;
			ppMatrix[coreR][coreC] = '!';
		}
		//right
		coreC = coreC_origin;
		influenceCurren_LeftRight = influence_current_Up;
		while (coreC + 1 < 10 && influenceCurren_LeftRight > 0)
		{
			coreC++;
			influenceCurren_LeftRight--;
			ppMatrix[coreR][coreC] = '!';
		}
		nextRow--;
		coreR = nextRow;
		influence_current_Up--;
	}
}

void PaintFreely_Up_Down_and_Right(char ** ppMatrix, int rows, int cols, int coreR, int coreC, int influence)
{
	int coreR_origin = coreR;
	int influence_current_Right = influence;
	int influence_origin = influence;

	int nextCol = coreC + 1;
	while (nextCol < 10 && influence_current_Right >= 0) {
		nextCol = coreC;
		coreR = coreR_origin;
		ppMatrix[coreR][coreC] = '!';

		//up
		coreR = coreR_origin;
		int influenceCurren_UpDown = influence_current_Right;
		int nextRow = coreR - 1;
		while (nextRow >= 0 && influenceCurren_UpDown > 0)
		{
			coreR = nextRow;
			influenceCurren_UpDown--;
			ppMatrix[coreR][coreC] = '!';
			nextRow--;
		}
		//down
		coreR = coreR_origin;
		influenceCurren_UpDown = influence_current_Right;
		while (coreR + 1 < 10 && influenceCurren_UpDown > 0)
		{
			coreR++;
			influenceCurren_UpDown--;
			ppMatrix[coreR][coreC] = '!';
		}
		nextCol++;
		coreC = nextCol;
		influence_current_Right--;
	}
}

void PaintFreely_Up_Down_and_Left(char ** ppMatrix, int rows, int cols, int coreR, int coreC, int influence)
{
	int coreR_origin = coreR;
	int influence_current_Left = influence;
	int influence_origin = influence;

	int nextCol = coreC - 1;
	while (nextCol >= 0 && influence_current_Left >= 0) {
		nextCol = coreC;
		coreR = coreR_origin;
		ppMatrix[coreR][coreC] = '!';

		//up
		coreR = coreR_origin;
		int influenceCurren_UpDown = influence_current_Left;
		int nextRow = coreR - 1;
		while (nextRow >= 0 && influenceCurren_UpDown > 0)
		{
			coreR = nextRow;
			influenceCurren_UpDown--;
			ppMatrix[coreR][coreC] = '!';
			nextRow--;
		}
		//down
		coreR = coreR_origin;
		influenceCurren_UpDown = influence_current_Left;
		while (coreR + 1 < 10 && influenceCurren_UpDown > 0)
		{
			coreR++;
			influenceCurren_UpDown--;
			ppMatrix[coreR][coreC] = '!';
		}
		nextCol--;
		coreC = nextCol;
		influence_current_Left--;
	}
}

//int wallCenterRow = -1, wallCenterCol = -1, wallLength = 0;

void PaintTheShadowUp(char ** ppMatrix, int rows, int cols)
{
	int shadowR = wallCenterRow - 1;
	int shadowC = wallCenterCol;	
	int shadowC_origin = wallCenterCol;
	int shadowHalfLengthRight = 1;	

	if (shadowR >= 0) {
		ppMatrix[shadowR][shadowC] = '@';
	}

	int nextShadRow = shadowR - 1;
	while (nextShadRow >= 0)
	{		
		shadowR = nextShadRow;
		ppMatrix[shadowR][shadowC] = '@';
		//left
		int shadowColLeft = shadowC_origin;
		int shadowHalfLengthCurr = 0;
		while (shadowColLeft >= 0 && shadowHalfLengthCurr <= shadowHalfLengthRight)
		{		
			
			shadowHalfLengthCurr++;
			ppMatrix[shadowR][shadowColLeft] = '@';
			shadowColLeft--;
		}

		//right
		int shadowColRight = shadowC_origin;
		shadowHalfLengthCurr = 0;
		while (shadowColRight < 10 && shadowHalfLengthCurr <= shadowHalfLengthRight)
		{
			ppMatrix[shadowR][shadowColRight] = '@';
			shadowColRight++;
			shadowHalfLengthCurr++;
		}

		shadowHalfLengthRight++;
		nextShadRow--;
	}
}

void PaintTheShadowDown(char ** ppMatrix, int rows, int cols)
{
	int shadowR = wallCenterRow + 1;
	int shadowC = wallCenterCol;	
	int shadowC_origin = wallCenterCol;
	int shadowHalfLengthRight = 1;

	if (shadowR < 10) {
		ppMatrix[shadowR][shadowC] = '@';
	}

	int nextShadRow = shadowR + 1;
	while (nextShadRow < 10)
	{
		shadowR = nextShadRow;
		ppMatrix[shadowR][shadowC] = '@';
		//left
		int shadowColLeft = shadowC_origin;
		int shadowHalfLengthCurr = 0;
		while (shadowColLeft >= 0 && shadowHalfLengthCurr <= shadowHalfLengthRight)
		{
			shadowHalfLengthCurr++;
			ppMatrix[shadowR][shadowColLeft] = '@';
			shadowColLeft--;
		}
		//right
		int shadowColRight = shadowC_origin;
		shadowHalfLengthCurr = 0;
		while (shadowColRight < 10 && shadowHalfLengthCurr <= shadowHalfLengthRight)
		{
			ppMatrix[shadowR][shadowColRight] = '@';
			shadowColRight++;
			shadowHalfLengthCurr++;
		}

		shadowHalfLengthRight++;
		nextShadRow++;
	}
}

void PaintTheShadowLeft(char ** ppMatrix, int rows, int cols)
{
	int shadowR = wallCenterRow;
	int shadowC = wallCenterCol - 1;	
	int shadowR_origin = wallCenterRow;
	int shadowHalfUpDown = 0;

	if (shadowC >= 0) {
		ppMatrix[shadowR][shadowC] = '@';
	}

	int nextShadCol = shadowC - 1;
	while (nextShadCol >= 0)
	{
		shadowC = nextShadCol;
		ppMatrix[shadowR][shadowC] = '@';
		////Up
		int shadowRowUp = shadowR_origin - 1;
		int shadowHalfLengthCurr = 0;
		while (shadowRowUp >= 0 && shadowHalfLengthCurr <= shadowHalfUpDown)
		{

			shadowHalfLengthCurr++;
			ppMatrix[shadowRowUp][shadowC] = '@';
			shadowRowUp--;
		}
		//Down
		int shadowRowDown = shadowR_origin + 1;
		shadowHalfLengthCurr = 0;
		while (shadowRowDown < 10 && shadowHalfLengthCurr <= shadowHalfUpDown)
		{
			ppMatrix[shadowRowDown][shadowC] = '@';
			shadowRowDown++;
			shadowHalfLengthCurr++;
		}
		shadowHalfUpDown++;
		nextShadCol--;
	}
}

void PaintTheShadowRight(char ** ppMatrix, int rows, int cols)
{
	int shadowR = wallCenterRow;
	int shadowC = wallCenterCol + 1;	
	int shadowR_origin = wallCenterRow;
	int shadowHalfUpDown = 0;

	if (shadowC < 10) {
		ppMatrix[shadowR][shadowC] = '@';
	}

	int nextShadCol = shadowC + 1;
	while (nextShadCol < 10)
	{
		shadowC = nextShadCol;
		ppMatrix[shadowR][shadowC] = '@';
		////Up
		int shadowRowUp = shadowR_origin - 1;
		int shadowHalfLengthCurr = 0;
		while (shadowRowUp >= 0 && shadowHalfLengthCurr <= shadowHalfUpDown)
		{

			shadowHalfLengthCurr++;
			ppMatrix[shadowRowUp][shadowC] = '@';
			shadowRowUp--;
		}
		//Down
		int shadowRowDown = shadowR_origin + 1;
		shadowHalfLengthCurr = 0;
		while (shadowRowDown < 10 && shadowHalfLengthCurr <= shadowHalfUpDown)
		{
			ppMatrix[shadowRowDown][shadowC] = '@';
			shadowRowDown++;
			shadowHalfLengthCurr++;
		}
		shadowHalfUpDown++;
		nextShadCol++;
	}
}

void PaintRustUp_AvoidingResistantWallAndItsShadow (char ** ppMatrix, int rows, int cols, int coreR, int coreC, int influence)
{
	int coreR_origin = coreR;
	int coreC_origin = coreC;
	int influence_current_Up = influence;
	int influence_origin = influence;		

	int nextRow = coreR - 1;
	while (nextRow >= 0 && influence_current_Up >= 0) {
		nextRow = coreR;
		coreC = coreC_origin;
		if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
			ppMatrix[coreR][coreC] = '!';
		}
		int influenceCurren_LeftRight = influence_current_Up;
		//left
		while (coreC - 1 >= 0 && influenceCurren_LeftRight > 0)
		{
			coreC--;
			influenceCurren_LeftRight--;
			if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
				ppMatrix[coreR][coreC] = '!';
			}
		}
		//right
		coreC = coreC_origin;
		influenceCurren_LeftRight = influence_current_Up;
		while (coreC + 1 < 10 && influenceCurren_LeftRight > 0)
		{
			coreC++;
			influenceCurren_LeftRight--;
			if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
				ppMatrix[coreR][coreC] = '!';
			}
		}
		nextRow--;
		coreR = nextRow;
		influence_current_Up--;
	}
}
void PaintRustDown_AvoidingResistantWallAndItsShadow(char ** ppMatrix, int rows, int cols, int coreR, int coreC, int influence)
{
	int coreR_origin = coreR;
	int coreC_origin = coreC;
	int influence_current_Down = influence;
	int influence_origin = influence;		

	int nextRow = coreR + 1;
	while (nextRow < 10 && influence_current_Down >= 0) {
		nextRow = coreR;
		coreC = coreC_origin;

		if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
			ppMatrix[coreR][coreC] = '!';
		}
		int influenceCurren_LeftRight = influence_current_Down;
		//left
		while (coreC - 1 >= 0 && influenceCurren_LeftRight > 0)
		{
			coreC--;
			influenceCurren_LeftRight--;
			if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
				ppMatrix[coreR][coreC] = '!';
			}
		}
		//right
		coreC = coreC_origin;
		influenceCurren_LeftRight = influence_current_Down;
		while (coreC + 1 < 10 && influenceCurren_LeftRight > 0)
		{
			coreC++;
			influenceCurren_LeftRight--;
			if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
				ppMatrix[coreR][coreC] = '!';
			}
		}
		nextRow++;
		coreR = nextRow;
		influence_current_Down--;
	}
}
void PaintRustLeft_AvoidingResistantWallAndItsShadow(char ** ppMatrix, int rows, int cols, int coreR, int coreC, int influence)
{
	int coreR_origin = coreR;
	int influence_current_Left = influence;
	int influence_origin = influence;

	int nextCol = coreC - 1;
	while (nextCol >= 0 && influence_current_Left >= 0) {
		nextCol = coreC;
		coreR = coreR_origin;
		if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
			ppMatrix[coreR][coreC] = '!';
		}
		//up
		coreR = coreR_origin;
		int influenceCurren_UpDown = influence_current_Left;
		int nextRow = coreR - 1;
		while (nextRow >= 0 && influenceCurren_UpDown > 0)
		{
			coreR = nextRow;
			influenceCurren_UpDown--;
			if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
				ppMatrix[coreR][coreC] = '!';
			}
			nextRow--;
		}
		//down
		coreR = coreR_origin;
		influenceCurren_UpDown = influence_current_Left;
		while (coreR + 1 < 10 && influenceCurren_UpDown > 0)
		{
			coreR++;
			influenceCurren_UpDown--;
			if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
				ppMatrix[coreR][coreC] = '!';
			}
		}
		nextCol--;
		coreC = nextCol;
		influence_current_Left--;
	}
}
void PaintRustRight_AvoidingResistantWallAndItsShadow(char ** ppMatrix, int rows, int cols, int coreR, int coreC, int influence)
{
	int coreR_origin = coreR;
	int influence_current_Right = influence;
	int influence_origin = influence;

	int nextCol = coreC + 1;
	while (nextCol < 10 && influence_current_Right >= 0) {
		nextCol = coreC;
		coreR = coreR_origin;
		if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
			ppMatrix[coreR][coreC] = '!';
		}

		//up
		coreR = coreR_origin;
		int influenceCurren_UpDown = influence_current_Right;
		int nextRow = coreR - 1;
		while (nextRow >= 0 && influenceCurren_UpDown > 0)
		{
			coreR = nextRow;
			influenceCurren_UpDown--;
			if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
				ppMatrix[coreR][coreC] = '!';
			}
			nextRow--;
		}
		//down
		coreR = coreR_origin;
		influenceCurren_UpDown = influence_current_Right;
		while (coreR + 1 < 10 && influenceCurren_UpDown > 0)
		{
			coreR++;
			influenceCurren_UpDown--;
			if (ppMatrix[coreR][coreC] != '#' && ppMatrix[coreR][coreC] != '@') {
				ppMatrix[coreR][coreC] = '!';
			}
		}
		nextCol++;
		coreC = nextCol;
		influence_current_Right--;
	}
}

void CleanUpShadow(char ** ppMatrix, int rows, int cols)
{
	int shadowR = wallCenterRow - 1;
	int shadowC = wallCenterCol;	
	int shadowC_origin = wallCenterCol;
	int shadowHalfLengthRight = 1;

	if (shadowR >= 0) {
		ppMatrix[shadowR][shadowC] = '.';
	}

	int nextShadRow = shadowR - 1;
	while (nextShadRow >= 0)
	{
		shadowR = nextShadRow;
		ppMatrix[shadowR][shadowC] = '.';
		//left
		int shadowColLeft = shadowC_origin;
		int shadowHalfLengthCurr = 0;
		while (shadowColLeft >= 0 && shadowHalfLengthCurr <= shadowHalfLengthRight)
		{
			shadowHalfLengthCurr++;
			ppMatrix[shadowR][shadowColLeft] = '.';
			shadowColLeft--;
		}
		//right
		int shadowColRight = shadowC_origin;
		shadowHalfLengthCurr = 0;
		while (shadowColRight < 10 && shadowHalfLengthCurr <= shadowHalfLengthRight)
		{
			ppMatrix[shadowR][shadowColRight] = '.';
			shadowColRight++;
			shadowHalfLengthCurr++;
		}
		shadowHalfLengthRight++;
		nextShadRow--;
	}
}
void CleanShadowDown(char ** ppMatrix, int rows, int cols)
{
	int shadowR = wallCenterRow + 1;
	int shadowC = wallCenterCol;
	int shadowC_origin = wallCenterCol;
	int shadowHalfLengthRight = 1;

	if (shadowR < 10) {
		ppMatrix[shadowR][shadowC] = '.';
	}

	int nextShadRow = shadowR + 1;
	while (nextShadRow < 10)
	{
		shadowR = nextShadRow;
		ppMatrix[shadowR][shadowC] = '.';
		//left
		int shadowColLeft = shadowC_origin;
		int shadowHalfLengthCurr = 0;
		while (shadowColLeft >= 0 && shadowHalfLengthCurr <= shadowHalfLengthRight)
		{
			shadowHalfLengthCurr++;
			ppMatrix[shadowR][shadowColLeft] = '.';
			shadowColLeft--;
		}
		//right
		int shadowColRight = shadowC_origin;
		shadowHalfLengthCurr = 0;
		while (shadowColRight < 10 && shadowHalfLengthCurr <= shadowHalfLengthRight)
		{
			ppMatrix[shadowR][shadowColRight] = '.';
			shadowColRight++;
			shadowHalfLengthCurr++;
		}
		shadowHalfLengthRight++;
		nextShadRow++;
	}
}
void CleanShadowLeft(char ** ppMatrix, int rows, int cols)
{
	int shadowR = wallCenterRow;
	int shadowC = wallCenterCol - 1;	
	int shadowR_origin = wallCenterRow;
	int shadowHalfUpDown = 0;

	if (shadowC >= 0) {
		ppMatrix[shadowR][shadowC] = '.';
	}

	int nextShadCol = shadowC - 1;
	while (nextShadCol >= 0)
	{
		shadowC = nextShadCol;
		ppMatrix[shadowR][shadowC] = '.';
		////Up
		int shadowRowUp = shadowR_origin - 1;
		int shadowHalfLengthCurr = 0;
		while (shadowRowUp >= 0 && shadowHalfLengthCurr <= shadowHalfUpDown)
		{
			shadowHalfLengthCurr++;
			ppMatrix[shadowRowUp][shadowC] = '.';
			shadowRowUp--;
		}
		//Down
		int shadowRowDown = shadowR_origin + 1;
		shadowHalfLengthCurr = 0;
		while (shadowRowDown < 10 && shadowHalfLengthCurr <= shadowHalfUpDown)
		{
			ppMatrix[shadowRowDown][shadowC] = '.';
			shadowRowDown++;
			shadowHalfLengthCurr++;
		}
		shadowHalfUpDown++;
		nextShadCol--;
	}
}
void CleanShadowRight(char ** ppMatrix, int rows, int cols)
{
	int shadowR = wallCenterRow;
	int shadowC = wallCenterCol + 1;	
	int shadowR_origin = wallCenterRow;
	int shadowHalfUpDown = 0;

	if (shadowC < 10) {
		ppMatrix[shadowR][shadowC] = '.';
	}

	int nextShadCol = shadowC + 1;
	while (nextShadCol < 10)
	{
		shadowC = nextShadCol;
		ppMatrix[shadowR][shadowC] = '.';
		////Up
		int shadowRowUp = shadowR_origin - 1;
		int shadowHalfLengthCurr = 0;
		while (shadowRowUp >= 0 && shadowHalfLengthCurr <= shadowHalfUpDown)
		{
			shadowHalfLengthCurr++;
			ppMatrix[shadowRowUp][shadowC] = '.';
			shadowRowUp--;
		}
		//Down
		int shadowRowDown = shadowR_origin + 1;
		shadowHalfLengthCurr = 0;
		while (shadowRowDown < 10 && shadowHalfLengthCurr <= shadowHalfUpDown)
		{
			ppMatrix[shadowRowDown][shadowC] = '.';
			shadowRowDown++;
			shadowHalfLengthCurr++;
		}
		shadowHalfUpDown++;
		nextShadCol++;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	char ** ppMatrix = CreateppMatrix();

	int influence = 0;
	ReadInput(ppMatrix, 10, 10, influence);
	int coreR, coreC;
	FindTheCore(ppMatrix, 10, 10, coreR, coreC);
	FindTheWAllCenter(ppMatrix, 10, 10, coreR, coreC); //The wall is symmetrical to the Core
	//wallCenterRow ;
	//wallCenterCol ;
	//wallLength;
	if (wallCenterRow < coreR || wallCenterRow > coreR)
	{
		CountWallLengthHorizontally(ppMatrix, 10, 10);
	}
	else if (wallCenterCol < coreC || wallCenterCol > coreC)
	{
		CountWallLengthVertically(ppMatrix, 10, 10);
	}
	//fill the matrix
	if (wallCenterRow < coreR)
	{
		PaintFreely_Left_Right_and_Down(ppMatrix, 10, 10, coreR, coreC, influence);
		PaintTheShadowUp(ppMatrix, 10, 10);
		PaintRustUp_AvoidingResistantWallAndItsShadow(ppMatrix, 10, 10, coreR, coreC, influence);
		CleanUpShadow(ppMatrix, 10, 10);
	}
	else if (wallCenterRow > coreR)
	{
		PaintFreely_Left_Right_and_Up(ppMatrix, 10, 10, coreR, coreC, influence);
		PaintTheShadowDown(ppMatrix, 10, 10);
		PaintRustDown_AvoidingResistantWallAndItsShadow(ppMatrix, 10, 10, coreR, coreC, influence);
		CleanShadowDown(ppMatrix, 10, 10);
	}
	else if (wallCenterCol < coreC)
	{
		PaintFreely_Up_Down_and_Right(ppMatrix, 10, 10, coreR, coreC, influence);
		PaintTheShadowLeft(ppMatrix, 10, 10);
		PaintRustLeft_AvoidingResistantWallAndItsShadow(ppMatrix, 10, 10, coreR, coreC, influence);
		CleanShadowLeft(ppMatrix, 10, 10);
	}
	else if (wallCenterCol > coreC)
	{
		PaintFreely_Up_Down_and_Left(ppMatrix, 10, 10, coreR, coreC, influence);
		PaintTheShadowRight(ppMatrix, 10, 10);
		PaintRustRight_AvoidingResistantWallAndItsShadow(ppMatrix, 10, 10, coreR, coreC, influence);
		CleanShadowRight(ppMatrix, 10, 10);
	}
	
	PrintppMatrix(ppMatrix, 10, 10);
	delete[] ppMatrix;
	return 0;
}

