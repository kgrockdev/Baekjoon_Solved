#include "Problem_9461.h"

using namespace std;

#include <iostream>

unsigned long long arrContainer9461[101] = { };

unsigned long long Calc_9461(int iNum)
{
	if (arrContainer9461[iNum] != -1)
		return arrContainer9461[iNum];
	else
	{
		unsigned long long ullSrc = Calc_9461(iNum - 2) + Calc_9461(iNum - 3);
		arrContainer9461[iNum] = ullSrc;

		return ullSrc;
	}
}

int CProblem_9461::Solve_Problem()
{
	fill_n(arrContainer9461, 101, -1);

	arrContainer9461[1] = 1;
	arrContainer9461[2] = 1;
	arrContainer9461[3] = 1;

	int iNumTC = { };
	cin >> iNumTC;

	for (int iIndex = 0; iIndex < iNumTC; ++iIndex)
	{
		int iSrc = { };
		cin >> iSrc;

		cout << Calc_9461(iSrc) << '\n';
	}

	return 0;
}
