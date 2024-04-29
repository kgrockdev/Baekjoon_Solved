#include "Problem_9095.h"

using namespace std;

#include <iostream>

int arrContainer9095[11] = { };

int Calc_9095(int iNum)
{
	if (arrContainer9095[iNum] != -1)
		return arrContainer9095[iNum];
	else
	{
		arrContainer9095[iNum] = Calc_9095(iNum - 1) + Calc_9095(iNum - 2) + Calc_9095(iNum - 3);
		return arrContainer9095[iNum];
	}
}

int CProblem_9095::Solve_Problem()
{
	/*
		4의 경우
		1 + 3
		2 + 2
		3 + 1
		로 이루어짐

		5의 경우
		2 + 3
		3 + 2
		4 + 1
		로 이루어짐

	*/

	fill_n(arrContainer9095, 11, -1);

	arrContainer9095[1] = 1;
	arrContainer9095[2] = 2;
	arrContainer9095[3] = 3;

	int iNumTC = { };
	cin >> iNumTC;

	for (int iTC = 0; iTC < iNumTC; ++iTC)
	{
		int iNum = { };
		cin >> iNum;

		cout << Calc_9095(iNum) << '\n';
	}

	return 0;
}
