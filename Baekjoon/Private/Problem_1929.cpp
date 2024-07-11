#include "Problem_1929.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_1929::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int iM = { }, iN = { };
	cin >> iM >> iN;

	vector<bool> vecContainer; 
	vecContainer.reserve(1100000);
	for (int iIndex = 0; iIndex < iN + 1; ++iIndex)
		vecContainer.push_back(true);

	vecContainer[0] = false;
	vecContainer[1] = false;

	for (int iIndex = 2; iIndex < iN + 1; ++iIndex)
	{
		int iDigit = { iIndex };
		while (true)
		{
			iDigit += iIndex;
			if (iDigit >= iN + 1)
				break;

			vecContainer[iDigit] = false;
		}
	}

	for (int iIndex = iM; iIndex < iN + 1; ++iIndex)
	{
		if (vecContainer[iIndex] == true)
			cout << iIndex << '\n';
	}

	return 0;
}
