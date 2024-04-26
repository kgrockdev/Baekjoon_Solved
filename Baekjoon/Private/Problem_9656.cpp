#include "Problem_9656.h"

using namespace std;

#define SK true
#define CY false

#include <iostream>
#include <unordered_map>

unordered_map<int, bool> mapMemo9656;

bool Calc_Func_9656(int iQuery)
{
	auto iter = mapMemo9656.find(iQuery);
	if (iter != mapMemo9656.end())
		return iter->second;
	else
	{
		if ((Calc_Func_9656(iQuery - 1) == CY) || (Calc_Func_9656(iQuery - 3) == CY))
		{
			mapMemo9656.emplace(iQuery, SK);
			return SK;
		}
		else
		{
			mapMemo9656.emplace(iQuery, CY);
			return CY;
		}
	}
}

int CProblem_9656::Solve_Problem()
{
	mapMemo9656.emplace(1, SK);
	mapMemo9656.emplace(2, CY);
	mapMemo9656.emplace(3, SK);

	int iQuery = { };
	cin >> iQuery;

	cout << (Calc_Func_9656(iQuery) == SK ? "SK" : "CY") << '\n';

	return 0;
}
