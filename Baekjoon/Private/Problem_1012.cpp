#include "Problem_1012.h"

using namespace std;

#include <set>
#include <list>
#include <iostream>

int CProblem_1012::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int iNumTC = { };
	cin >> iNumTC;

	for (int iTC = 0; iTC < iNumTC; ++iTC)
	{
		// Init Answer
		int iNumAns = { };

		// 문제에 필요한 조건
		int arrGraph[50][50] = { };
		int iWidth = { }, iHeight = { }, iNumBechu = { };
		cin >> iWidth >> iHeight >> iNumBechu;

		// Init Graph
		set<pair<int, int>> setNode;
		for (int iBechu = 0; iBechu < iNumBechu; ++iBechu)
		{
			int iPosX = { }, iPosY = { };
			cin >> iPosX >> iPosY;

			arrGraph[iPosX][iPosY] = 1;
			setNode.emplace(pair<int, int>{ iPosX, iPosY });
		}

		// Calc Ans
		list<pair<int, int>> listBFS;
		
		while (setNode.size() > 0)
		{
			++iNumAns;

			// Init Node
			pair<int, int> pairStartNode = *setNode.begin();
			listBFS.push_back(pairStartNode);
			setNode.erase(pairStartNode);

			// Search
			while (listBFS.size() > 0)
			{
				pair<int, int> iSearchNode = listBFS.front(); listBFS.pop_front();
				if (arrGraph[iSearchNode.first + 1][iSearchNode.second] == 1 &&
					setNode.find({ iSearchNode.first + 1, iSearchNode.second }) != setNode.end())
				{
					listBFS.push_back({ iSearchNode.first + 1, iSearchNode.second });
					setNode.erase({ iSearchNode.first + 1, iSearchNode.second });
				}
				if (arrGraph[iSearchNode.first - 1][iSearchNode.second] == 1 &&
					setNode.find({ iSearchNode.first - 1, iSearchNode.second }) != setNode.end())
				{
					listBFS.push_back({ iSearchNode.first - 1, iSearchNode.second });
					setNode.erase({ iSearchNode.first - 1, iSearchNode.second });
				}
				if (arrGraph[iSearchNode.first][iSearchNode.second + 1] == 1 &&
					setNode.find({ iSearchNode.first, iSearchNode.second + 1 }) != setNode.end())
				{
					listBFS.push_back({ iSearchNode.first, iSearchNode.second + 1 });
					setNode.erase({ iSearchNode.first, iSearchNode.second + 1 });
				}
				if (arrGraph[iSearchNode.first][iSearchNode.second - 1] == 1 &&
					setNode.find({ iSearchNode.first, iSearchNode.second - 1 }) != setNode.end())
				{
					listBFS.push_back({ iSearchNode.first, iSearchNode.second - 1 });
					setNode.erase({ iSearchNode.first, iSearchNode.second - 1 });
				}
			}
		}

		cout << iNumAns << '\n';
	}

	return 0;
}


/*

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int iNumTC = { };
	cin >> iNumTC;

	for (int iTC = 0; iTC < iNumTC; ++iTC)
	{
		// Init Answer
		int iNumAns = { };

		// 문제에 필요한 조건
		map<int, set<int>> mapGraph;
		int iWidth = { }, iHeight = { }, iNumBechu = { };
		cin >> iWidth >> iHeight >> iNumBechu;

		// Init Graph
		for (int iBechu = 0; iBechu < iNumBechu; ++iBechu)
		{
			int iPosA = { }, iPosB = { };
			cin >> iPosA >> iPosB;

			auto iterA = mapGraph.find(iPosA);
			if (iterA != mapGraph.end())
				iterA->second.emplace(iPosB);
			else
				mapGraph.emplace(iPosA, set<int>{ iPosB });

			auto iterB = mapGraph.find(iPosB);
			if (iterB != mapGraph.end())
				iterB->second.emplace(iPosA);
			else
				mapGraph.emplace(iPosB, set<int>{ iPosA });
		}

		// Calc Ans
		list<int> listBFS;
		while (mapGraph.size() > 0)
		{
			iNumAns++;

			// Init BFS
			auto iter = mapGraph.begin();
			for (int iSrc : iter->second)
				listBFS.push_back(iSrc);
			mapGraph.erase(iter);

			while (listBFS.size() > 0)
			{
				int iSrc = listBFS.front(); listBFS.pop_front();

				iter = mapGraph.find(iSrc);
				if (iter != mapGraph.end())
				{
					for (int iTemp : iter->second)
						listBFS.push_back(iTemp);
					mapGraph.erase(iter);
				}
			}
		}

		cout << iNumAns << '\n';
	}

*/