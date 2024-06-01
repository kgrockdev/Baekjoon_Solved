#include "Problem_1043.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void UnionMerge1043(vector<int>& vecUnionFind, int iX, int iY)
{
	int iUFX = { vecUnionFind[iX] };
	int iUFY = { vecUnionFind[iY] };

	while (vecUnionFind[iUFX] != iUFX)
		iUFX = vecUnionFind[iUFX];

	while (vecUnionFind[iUFY] != iUFY)
		iUFY = vecUnionFind[iUFY];

	if (iUFX == iUFY)
		return;

	vecUnionFind[iUFY] = iUFX;
}

int CProblem_1043::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int iNumPeople = { }, iNumTC = { }, iNumLie = { }, iSrc = { };
	cin >> iNumPeople >> iNumTC >> iNumLie;

	unordered_set<int> setLier;

	for (int iLie = 0; iLie < iNumLie; ++iLie)
	{
		cin >> iSrc;
		setLier.emplace(iSrc - 1);
	}
	
	vector<int> vecUnionFind;
	for (int iPerson = 0; iPerson < iNumPeople; ++iPerson)
		vecUnionFind.push_back(iPerson);

	int iNumPartyPeople = { };
	vector<vector<int>> vecParty;
	for (int iTC = 0; iTC < iNumTC; ++iTC)
	{
		cin >> iNumPartyPeople;

		vector<int> vecSrc;
		for (int iIndex = 0; iIndex < iNumPartyPeople; ++iIndex)
		{
			cin >> iSrc;
			vecSrc.push_back(iSrc - 1);
		}

		sort(vecSrc.begin(), vecSrc.end());

		for (auto iter : vecSrc)
			UnionMerge1043(vecUnionFind, vecSrc.front(), iter);

		vecParty.push_back(vecSrc);
	}

	int iRes = { };
	for (auto Party : vecParty)
	{
		for (auto iter : Party)
		{
			bool bFind = { false };
			for (auto Lier : setLier)
			{
				int iUFLier = { vecUnionFind[Lier] };
				int iUFFind = { vecUnionFind[iter] };

				while (vecUnionFind[iUFLier] != iUFLier)
					iUFLier = vecUnionFind[iUFLier];

				while (vecUnionFind[iUFFind] != iUFFind)
					iUFFind = vecUnionFind[iUFFind];

				if (iUFLier == iUFFind)
				{
					++iRes;
					bFind = true;
					break;
				}
			}

			if (bFind == true)
				break;
		}
	}

	cout << vecParty.size() - iRes << endl;

	return 0;
}
