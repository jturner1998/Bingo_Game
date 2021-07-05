#include "BingoCard.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


int numUsed[90];

bool CheckNum(int number)
{
	for (int i = 0; i < sizeof(numUsed) / sizeof(numUsed[0]); i++)
	{
		if (number == numUsed[i])
		{
			return false;
		}
	}
	return true;
}

void AddNum(int number)
{
	for (int i = 0; i < sizeof(numUsed) / sizeof(numUsed[0]); i++)
	{
		if (numUsed[i] == 0)
		{
			numUsed[i] = number;
		}
	}
}

void Sleep()
{
	chrono::seconds snd(2);

	this_thread::sleep_for(snd);
}

int main()
{

	bool bGameOver = false;
	BingoCard* bingoCard = new BingoCard();
	int number;

	bingoCard->PrintCard();

	Sleep();

	srand((unsigned int)time(NULL));

	while (!bGameOver)
	{
		number = rand() % 75 + 1;

		while (!CheckNum(number))
		{
			number = rand() % 75 + 1;
		}

		AddNum(number);

		cout << number << endl << endl;

		Sleep();

		bingoCard->CheckBingoCard(number);

		bingoCard->PrintCard();

		if (bingoCard->CheckForWinner())
		{
			bGameOver = true;
		}
		Sleep();
	}
	return 0;
}

