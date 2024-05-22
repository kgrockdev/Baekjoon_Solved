#include "Problem_1253.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_1253::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	vector<int> vecContainer;

	int iNum = { };
	cin >> iNum;

	int iSrc = { };
	for (int iIdx = 0; iIdx < iNum; ++iIdx)
	{
		cin >> iSrc;
		vecContainer.push_back(iSrc);
	}

	sort(vecContainer.begin(), vecContainer.end());

	int iRes = { };
	for (auto iter = vecContainer.begin(); iter != vecContainer.end(); ++iter)
	{
		auto beginIter = vecContainer.begin();
		auto endIter = vecContainer.end();
		--endIter;

		while (distance(vecContainer.begin(), endIter) > distance(vecContainer.begin(), beginIter))
		{
			int iSrc = *beginIter + *endIter;

			if (iSrc == *iter)
			{
				if (beginIter == iter)
				{
					++beginIter;

					if (beginIter == vecContainer.end())
						break;
				}
				else if (endIter == iter)
				{
					if (endIter == vecContainer.begin())
						break;
					else
						--endIter;
				}
				else
				{
					++iRes;
					break;
				}
			}
			else if (iSrc > *iter)
			{
				if (endIter == vecContainer.begin())
					break;
				else
					--endIter;
			}
			else if (iSrc < *iter)
			{
				++beginIter;

				if (beginIter == vecContainer.end())
					break;
			}
		}
	}

	cout << iRes << '\n';

	return 0;
}
