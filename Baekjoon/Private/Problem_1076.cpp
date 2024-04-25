#include "Problem_1076.h"

using namespace std;

#include <iostream>

int Calc_1076(string strVal)
{
	if (strVal == "black")
		return 0;
	else if (strVal == "brown")
		return 1;
	else if (strVal == "red")
		return 2;
	else if (strVal == "orange")
		return 3;
	else if (strVal == "yellow")
		return 4;
	else if (strVal == "green")
		return 5;
	else if (strVal == "blue")
		return 6;
	else if (strVal == "violet")
		return 7;
	else if (strVal == "grey")
		return 8;
	else if (strVal == "white")
		return 9;
}

int CProblem_1076::Solve_Problem()
{
	string strValA = { }, strValB = { }, strMul = { };
	cin >> strValA >> strValB >> strMul;

	int iValue = Calc_1076(strValA) * 10 + Calc_1076(strValB);
	cout << iValue;

	if (iValue > 0)
	{
		int iNumZero = Calc_1076(strMul);
		for (int iIndex = 0; iIndex < iNumZero; ++iIndex)
			cout << '0';
	}

	return 0;
}
