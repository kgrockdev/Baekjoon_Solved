#include "Problem_7568.h"

#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tagInfomation
{
	int iIndex = { };
	int iGrade = { };

	int iWeight = { };
	int iHeight = { };

	tagInfomation() { };
	tagInfomation(int iInputIndex) : iIndex(iInputIndex) { }

	bool operator()(tagInfomation tInfoA, tagInfomation tInfoB)
	{
		if (tInfoA.iWeight == tInfoB.iWeight)
			return tInfoA.iHeight < tInfoB.iHeight;
		else
			return tInfoA.iWeight < tInfoB.iWeight;
	}
} INFO;

int CProblem_7568::Solve_Problem()
{
	int iNum = { };
	cin >> iNum;

	priority_queue<INFO, vector<INFO>, INFO> pqContainer;

	for (int iIndex = 0; iIndex < iNum; ++iIndex)
	{
		INFO tInfo = { iIndex };
		cin >> tInfo.iWeight >> tInfo.iHeight;

		pqContainer.emplace(tInfo);
	}

	vector<INFO> vecContainer;
	while (pqContainer.size() > 0)
	{
		INFO tInfo = pqContainer.top();
		pqContainer.pop();

		int iGrade = { 1 };
		for (auto& iter : vecContainer)
		{
			if (iter.iWeight > tInfo.iWeight && iter.iHeight > tInfo.iHeight)
				++iGrade;
		}

		tInfo.iGrade = iGrade;
		vecContainer.push_back(tInfo);
	}

	sort(vecContainer.begin(), vecContainer.end(), [](INFO tInfoA, INFO tInfoB) { return tInfoA.iIndex < tInfoB.iIndex; });

	for (auto& iter : vecContainer)
		cout << iter.iGrade << " ";
	cout << '\n';

	return 0;
}
