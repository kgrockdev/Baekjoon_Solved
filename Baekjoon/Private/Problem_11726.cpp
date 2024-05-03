#include "Problem_11726.h"

using namespace std;

#include <iostream>

int arrCont11726[1001] = { };

int Calc_11726(int iNum)
{
	if (arrCont11726[iNum] != -1)
		return arrCont11726[iNum];
	else
	{
		int iSrc = Calc_11726(iNum - 1) + Calc_11726(iNum - 2);
		arrCont11726[iNum] = iSrc % 10007;

		return arrCont11726[iNum];
	}
}

int CProblem_11726::Solve_Problem()
{
	fill_n(arrCont11726, 1001, -1);

	arrCont11726[1] = 1;
	arrCont11726[2] = 2;

	int iNum = { };
	cin >> iNum;

	cout << Calc_11726(iNum) << '\n';

	return 0;
}
