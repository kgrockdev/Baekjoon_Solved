#include "Problem_2747.h"

using namespace std;

#include <map>
#include <iostream>

map<int, int> mapMemoization;

int Calc_Fibonacci(int iSrc)
{
	auto iter = mapMemoization.find(iSrc);

	if (iter != mapMemoization.end())
		return iter->second;
	else
	{
		if (iSrc > 1)
		{
			int iTemp = Calc_Fibonacci(iSrc - 1) + Calc_Fibonacci(iSrc - 2);
			mapMemoization.emplace(iSrc, iTemp);
			return iTemp;
		}
		else
			return iSrc;
	}
}

int CProblem_2747::Solve_Problem()
{
	int iQuery = { };
	cin >> iQuery;

	cout << Calc_Fibonacci(iQuery) << '\n';

	return 0;
}
