#include "Problem_5341.h"

using namespace std;

#include <iostream>
#include <unordered_map>

unordered_map<int, int> mapCont5341;

int Calc_5341(int iNum)
{
	auto iter = mapCont5341.find(iNum);
	if (iter != mapCont5341.end())
		return iter->second;
	else
	{
		int iSrc = Calc_5341(iNum - 1) + iNum;
		mapCont5341.emplace(iNum, iSrc);

		return iSrc;
	}
}

int CProblem_5341::Solve_Problem()
{
	mapCont5341.emplace(1, 1);

	while (true)
	{
		int iNum = { };
		cin >> iNum;

		if (iNum == 0)
			break;

		cout << Calc_5341(iNum) << '\n';
	}

	return 0;
}
