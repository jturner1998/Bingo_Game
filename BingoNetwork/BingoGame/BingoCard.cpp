#include "BingoCard.h"

BingoCard::BingoCard()
{
	int randBuffer = 1;
	y = sizeof(bingoNumbers) / sizeof(bingoNumbers[0]);
	x = sizeof(bingoNumbers[0]) / sizeof(int);
	int randNum;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			randNum = rand() % 15 + randBuffer;
			
			while (!CheckNumber(randNum))
			{
				randNum = rand() % 15 + randBuffer;
			}

			SetNumber(i, j, randNum);
			
		}
		randBuffer += 15;
	}
}

BingoCard::~BingoCard()
{
}

void BingoCard::PrintCard()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (j + 1 < x)
			{
				cout << bingoNumbers[i][j] << ",";
			}
			else
			{
				cout << bingoNumbers[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
}

int BingoCard::GetBiggerNumber(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

void BingoCard::SetNumber(int x, int y, int number)
{
	bingoNumbers[y][x] = number;
}

bool BingoCard::CheckNumber(int number)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (number == bingoNumbers[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void BingoCard::CheckBingoCard(int number)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (number == bingoNumbers[i][j])
			{
				SetNumber(j, i, 0);
			}
		}
	}
}

bool BingoCard::CheckForWinner()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (bingoNumbers[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}



