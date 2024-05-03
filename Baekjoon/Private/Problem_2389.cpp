#include "Problem_2389.h"

using namespace std;

#include <iostream>

int arrCont2389[5001] = { };

int Calc_2389(int iNum)
{
	if (arrCont2389[iNum] != -2)
		return arrCont2389[iNum];
	else
	{
		int iSrc = Calc_2389(iNum - 5) + 1;
		arrCont2389[iNum] = iSrc;

		return iSrc;
	}
}

int CProblem_2389::Solve_Problem()
{
	fill_n(arrCont2389, 5001, -2);
	
	arrCont2389[3] = 1;
	arrCont2389[4] = -1;
	arrCont2389[5] = 1;

	arrCont2389[6] = 2;
	arrCont2389[7] = -1;
	arrCont2389[8] = 2;
	arrCont2389[9] = 3;
	arrCont2389[10] = 2;

	arrCont2389[11] = 3;
	arrCont2389[12] = 4;

	int iNum = { };
	cin >> iNum;

	cout << Calc_2389(iNum) << '\n';

	return 0;
}
