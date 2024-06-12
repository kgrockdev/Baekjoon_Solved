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

/*

	vector<int> vecPermutation; vecPermutation.push_back(0);
	for (int iCheck = 1; iCheck < iNumCheck - 2; ++iCheck)
		vecPermutation.push_back(1);

	vector<int> vecSrc;
	for (int iCheck = 0; iCheck < iNumCheck - 2; ++iCheck)
		vecSrc.push_back(iCheck);

	int iAnswer = { INT_MAX };

	do
	{
		vector<int> vecOrder; vecOrder.push_back(0);
		for (int iOrder = 0; iOrder < vecSrc.size(); ++iOrder)
		{
			if (vecPermutation[iOrder] == 1)
				vecOrder.push_back(vecSrc[iOrder] + 1);
		}
		vecOrder.push_back(vecCheckPoint.size() - 1);

		int iSrcMin = { };
		for (auto iter = vecOrder.begin();;)
		{
			pair<int, int> pairA = vecCheckPoint[*(iter++)];
			if (iter == vecOrder.end())
				break;

			pair<int, int> pairB = vecCheckPoint[*(iter)];

			iSrcMin += CalcManhattanDist_10655(pairA, pairB);
		}

		iAnswer = (iAnswer < iSrcMin) ? iAnswer : iSrcMin;

	} while (next_permutation(vecPermutation.begin(), vecPermutation.end()));

	cout << iAnswer << endl;

*/