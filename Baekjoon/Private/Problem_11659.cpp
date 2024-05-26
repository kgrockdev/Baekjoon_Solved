#include "Problem_11659.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_11659::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int iNum = { }, iNumTC = { };
	cin >> iNum >> iNumTC;

	vector<int> vecSum;
	int iSrc = { }, iPrev = { };

	cin >> iSrc;
	vecSum.push_back(iSrc);

	for (int iIndex = 1; iIndex < iNum; ++iIndex)
	{
		cin >> iSrc;
		iPrev = vecSum.back();

		vecSum.push_back(iSrc + iPrev);
	}

	int iStart = { }, iEnd = { };
	int iSumStart = { }, iSumEnd = { };
	for (int iTC = 0; iTC < iNumTC; ++iTC)
	{
		cin >> iStart >> iEnd;

		iSumStart = (iStart == 1) ? 0 : vecSum[iStart - 2];
		iSumEnd = vecSum[iEnd - 1];

		cout << iSumEnd - iSumStart << '\n';
	}

	return 0;
}
