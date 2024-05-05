#include "Problem_11047.h"

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

int CProblem_11047::Solve_Problem()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int iNum = { }, iTotal = { };
	cin >> iNum >> iTotal;

	vector<int> vecContainer;
	for (int iIndex = 0; iIndex < iNum; ++iIndex)
	{
		int iSrc = { };
		cin >> iSrc;

		vecContainer.push_back(iSrc);
	}

	reverse(vecContainer.begin(), vecContainer.end());

	int iNumCoin = { 0 };
	for (int iIndex = 0; iIndex < iNum; ++iIndex)
	{
		iNumCoin += iTotal / vecContainer[iIndex];
		iTotal = iTotal % vecContainer[iIndex];
	}

	cout << iNumCoin << '\n';

	return 0;
}
