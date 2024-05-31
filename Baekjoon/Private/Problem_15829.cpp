#include "Problem_15829.h"

#include <string>
#include <iostream>

using namespace std;

int CProblem_15829::Solve_Problem()
{
	int iNum = { };
	long long llAns = { };
	cin >> iNum;

	char chSrc = { };
	string strHash;
	for (int iIndex = 0; iIndex < iNum; ++iIndex)
	{
		cin >> chSrc;
		strHash.push_back(chSrc);
	}

	long long llPow = { 0 };
	for (auto hsIter : strHash)
	{
		long long llSrc = hsIter - 96;

		if (llPow == 0)
			llPow = 1;
		else
			llPow *= 31;
		llPow %= 1234567891;

		llAns += (llSrc * llPow) % 1234567891;
		llAns %= 1234567891;
	}

	cout << llAns << '\n';

	return 0;
}
