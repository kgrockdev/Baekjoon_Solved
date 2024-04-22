#include "Problem_7785.h"

using namespace std;

#include <set>
#include <iostream>
#include <algorithm>

int CProblem_7785::Solve_Problem()
{
	ios::sync_with_stdio(false); cin.tie(0);

	set<string, greater<string>> setContainer;

	int iNum = { };
	cin >> iNum;

	for (int iIndex = 0; iIndex < iNum; ++iIndex)
	{
		string strName = { }, strDivision = { };
		cin >> strName >> strDivision;

		if (strDivision == "enter")
			setContainer.emplace(strName);
		else if (strDivision == "leave")
		{
			auto iter = setContainer.find(strName);

			if (iter != setContainer.end())
				setContainer.erase(iter);
		}
	}

	auto iter = setContainer.begin();
	while (iter != setContainer.end())
	{
		cout << *iter << '\n';
		++iter;
	}

    return 0;
}
