#include "Problem_7568.h"

using namespace std;

#include <vector>
#include <iostream>
#include <unordered_map>

typedef struct tagPerson
{
	int iWeight = { };
	int iHeight = { };

	int iGrade = { };
	int iScore = { };
} PERSON;

int CProblem_7568::Solve_Problem()
{
	int iNum = { };
	cin >> iNum;

	vector<PERSON> vecContainer;
	vecContainer.reserve(iNum);

	for (int iIndex = 0; iIndex < iNum; ++iIndex)
	{
		PERSON tPerson = { };
		cin >> tPerson.iWeight >> tPerson.iHeight;

		for (auto& iter : vecContainer)
		{
			if (tPerson.iHeight < iter.iHeight &&
				tPerson.iWeight < iter.iWeight)
				iter.iScore++;
			else if (tPerson.iHeight > iter.iHeight &&
				tPerson.iWeight > iter.iWeight)
				tPerson.iScore++;
		}

		vecContainer.push_back(tPerson);
	}

	unordered_map<int, int> mapMemo;
	for (auto& itPerson : vecContainer)
	{
		auto iter = mapMemo.find(itPerson.iScore);
		if (iter != mapMemo.end())
			itPerson.iGrade = iter->second;
		else
		{
			int iGrade = { 1 };
			for (auto& itComp : vecContainer)
			{
				if (itComp.iScore > itPerson.iScore)
					iGrade++;
			}

			itPerson.iScore = iGrade;
			mapMemo.emplace(itPerson.iScore, iGrade);
		}
	}

	for (auto& itPerson : vecContainer)
		cout << itPerson.iGrade << " ";

	return 0;
}
