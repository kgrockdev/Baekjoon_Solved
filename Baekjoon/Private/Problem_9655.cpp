#include "Problem_9655.h"

using namespace std;

#include <iostream>
#include <unordered_map>

unordered_map<int, bool> mapMemo;

bool Calc_Func(int iQuery)
{
	auto iter = mapMemo.find(iQuery);
	if (iter != mapMemo.end())
		return iter->second;
	else
	{

	}
}

int CProblem_9655::Solve_Problem()
{
	int iQuery = { };
	cin >> iQuery;

	cout << Calc_Func(iQuery) << '\n';

	return 0;
}
