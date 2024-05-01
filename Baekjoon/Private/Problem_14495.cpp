#include "Problem_14495.h"

using namespace std;

#define ULL unsigned long long

#include <iostream>

ULL arrContainer14495[116] = { };

ULL Calc_14495(int iNum)
{
	if (arrContainer14495[iNum - 1] != -1)
		return arrContainer14495[iNum - 1];
	else
	{
		ULL ullSrc = Calc_14495(iNum - 1) + Calc_14495(iNum - 3);
		arrContainer14495[iNum - 1] = ullSrc;

		return ullSrc;
	}
}

int CProblem_14495::Solve_Problem()
{
	fill_n(arrContainer14495, 116, -1);

	arrContainer14495[0] = 1;
	arrContainer14495[1] = 1;
	arrContainer14495[2] = 1;

	int iNum = { };
	cin >> iNum;

	cout << Calc_14495(iNum) << '\n';

	return 0;
}
