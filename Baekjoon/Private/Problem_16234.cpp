#include "Problem_16234.h"

#include <list>
#include <vector>
#include <iostream>

using namespace std;

// 포인터로 접근
int CProblem_16234::Solve_Problem()
{
	int iNumRowCol = { }, iDiffMin = { }, iDiffMax = { };
	cin >> iNumRowCol >> iDiffMin >> iDiffMax;

	vector<vector<int>> vecContainer;
	vector<vector<int>> vecOriginSearch;
	for (int iRow = 0; iRow < iNumRowCol; ++iRow)
	{
		vector<int> vecSrc;
		vector<int> vecSearchSrc;
		for (int iCol = 0; iCol < iNumRowCol; ++iCol)
		{
			int iSrc = { };
			cin >> iSrc;

			vecSrc.push_back(iSrc);
			vecSearchSrc.push_back(0);
		}

		vecContainer.push_back(vecSrc);
		vecOriginSearch.push_back(vecSearchSrc);
	}

	while (true)
	{
		vector<vector<int>> vecSearch = vecOriginSearch;

		for (int iRow = 0; iRow < iNumRowCol; ++iRow)
		{
			for (int iCol = 0; iCol < iNumRowCol; ++iCol)
			{

			}
		}
	}

	return 0;
}
