#include "Problem_14916.h"

using namespace std;

#include <iostream>

int arrContainer14916[100001] = { };

int Calc_14916(int iNum)
{
	if (arrContainer14916[iNum] != -2)
		return arrContainer14916[iNum];

	arrContainer14916[iNum] = Calc_14916(iNum - 5) + 1;
	return arrContainer14916[iNum];
}

int CProblem_14916::Solve_Problem()
{
	fill_n(arrContainer14916, 100001, -2);

	arrContainer14916[1] = -1;
	arrContainer14916[2] = 1;
	arrContainer14916[3] = -1;
	arrContainer14916[4] = 2;
	arrContainer14916[5] = 1;
	arrContainer14916[6] = 3;
	arrContainer14916[7] = 2;
	arrContainer14916[8] = 4;
	arrContainer14916[9] = 3;
	arrContainer14916[10] = 2;

	int iNum = { };
	cin >> iNum;
	
	cout << Calc_14916(iNum) << '\n';

	return 0;
}
