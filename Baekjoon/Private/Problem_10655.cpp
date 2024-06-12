#include "Problem_10655.h"

#include <vector>
#include <iostream>
#include <algorithm>

#define INT_MAX       2147483647
#define INT_MIN     (-2147483647 - 1)

using namespace std;

inline int CalcManhattanDist_10655(pair<int, int> pairA, pair<int, int> pairB)
{
	return abs(pairA.first - pairB.first) + abs(pairA.second - pairB.second);
}

int CProblem_10655::Solve_Problem()
{
	int iNumCheck = { };
	cin >> iNumCheck;

	vector<pair<int, int>> vecCheckPoint;
	for (int iCheck = 0; iCheck < iNumCheck; ++iCheck)
	{
		pair<int, int> pairSrc = { };
		cin >> pairSrc.first >> pairSrc.second;

		vecCheckPoint.push_back(pairSrc);
	}

	int iAnswer = { };
	for (auto iter = vecCheckPoint.begin();;)
	{
		pair<int, int> pairA = *(iter++);
		if (iter == vecCheckPoint.end())
			break;

		pair<int, int> pairB = *(iter);

		iAnswer += CalcManhattanDist_10655(pairA, pairB);
	}

	int iSkip = { INT_MIN };
	for (int iIndex = 1; iIndex < vecCheckPoint.size() - 1; ++iIndex)
	{
		int iSkipSrc = { };

		iSkipSrc = 
			CalcManhattanDist_10655(vecCheckPoint[iIndex - 1], vecCheckPoint[iIndex]) + 
			CalcManhattanDist_10655(vecCheckPoint[iIndex], vecCheckPoint[iIndex + 1]) -
			CalcManhattanDist_10655(vecCheckPoint[iIndex - 1], vecCheckPoint[iIndex + 1]);

		iSkip = (iSkip < iSkipSrc) ? iSkipSrc : iSkip;
	}

	cout << iAnswer - iSkip << endl;

	return 0;
}
