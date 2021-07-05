#pragma once
#include <sstream>
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

class BingoCard
{
	int bingoNumbers[5][5];
	int x = 0;
	int y = 0;

public:
	BingoCard();

	~BingoCard();

	void PrintCard();

	void SetNumber(int x, int y, int number);
	int GetNumber(int x, int y, int number) { return bingoNumbers[y][x]; }

	int GetBiggerNumber(int num1, int num2);

	bool CheckNumber(int number);
	void CheckBingoCard(int number);
	bool CheckForWinner();
};

