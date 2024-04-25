#include "Problem_9655.h"

using namespace std;

#define SK true
#define CY false

#include <iostream>
#include <unordered_map>

unordered_map<int, bool> mapMemo;

bool Calc_Func_9655(int iQuery)
{
	auto iter = mapMemo.find(iQuery);
	if (iter != mapMemo.end())
		return iter->second;
	else
	{
		if ((Calc_Func_9655(iQuery - 1) == CY) || (Calc_Func_9655(iQuery - 3) == CY))
		{
			mapMemo.emplace(iQuery, SK);
			return SK;
		}
		else
		{
			mapMemo.emplace(iQuery, CY);
			return CY;
		}
	}
}

int CProblem_9655::Solve_Problem()
{
	mapMemo.emplace(1, SK);
	mapMemo.emplace(2, CY);
	mapMemo.emplace(3, SK);

	int iQuery = { };
	cin >> iQuery;

	cout << (Calc_Func_9655(iQuery) == SK ? "SK" : "CY") << '\n';

	return 0;
}
