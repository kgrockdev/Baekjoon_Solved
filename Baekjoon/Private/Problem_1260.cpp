#include "Problem_1260.h"

using namespace std;

#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

int CProblem_1260::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int arrGraph[1000][1000] = { };

	int iNumNode = { }, iNumEdge = { }, iStart = { };
	cin >> iNumNode >> iNumEdge >> iStart;
	iStart--;

	int iNodeA = { }, iNodeB = { };
	for (int iIndex = 0; iIndex < iNumEdge; ++iIndex)
	{
		cin >> iNodeA >> iNodeB;

		arrGraph[iNodeA - 1][iNodeB - 1] = 1;
		arrGraph[iNodeB - 1][iNodeA - 1] = 1;
	}

	// Searched Node
	int arrSearched[1000] = { };
	map<int, int> mapSearchedResDFS, mapSearchedResBFS;

	// DFS : 깊이 우선 탐색, 우선 끝까지 들어간 뒤 탐색할 곳이 없다면 Pop하며 다음 탐색을 찾음
	fill_n(arrSearched, 1000, 0);
	vector<int> vecDFS; vecDFS.push_back(iStart); arrSearched[iStart] = 1;

	while (vecDFS.size() > 0)
	{
		int iCurrNode = vecDFS.back();
		mapSearchedResDFS.emplace(iCurrNode, mapSearchedResDFS.size());

		bool bFind = false;
		for (int iIndex = 0; iIndex < iNumNode; ++iIndex)
		{
			if (arrGraph[iCurrNode][iIndex] == 1 && arrSearched[iIndex] == 0)
			{
				bFind = true;

				vecDFS.push_back(iIndex);
				arrSearched[iIndex] = 1;
				break;
			}
		}

		if (bFind == false)
			vecDFS.pop_back();
	}

	vector<pair<int, int>> vecCompDFS(mapSearchedResDFS.begin(), mapSearchedResDFS.end());
	sort(vecCompDFS.begin(), vecCompDFS.end(), [](pair<int, int> pairA, pair<int, int> pairB) { return pairA.second < pairB.second; });
	for (auto iter : vecCompDFS)
		cout << iter.first + 1 << " ";
	cout << '\n';

	// BFS
	fill_n(arrSearched, 1000, 0);
	list<int> listBFS; listBFS.push_back(iStart); arrSearched[iStart] = 1;
	
	while (listBFS.size() > 0)
	{
		int iCurrNode = listBFS.front();
		listBFS.pop_front();
		mapSearchedResBFS.emplace(iCurrNode, mapSearchedResBFS.size());
	
		for (int iIndex = 0; iIndex < iNumNode; ++iIndex)
		{
			if (arrGraph[iCurrNode][iIndex] == 1 && arrSearched[iIndex] == 0)
			{
				listBFS.push_back(iIndex);
				arrSearched[iIndex] = 1;
			}
		}
	}
	
	vector<pair<int, int>> vecCompBFS(mapSearchedResBFS.begin(), mapSearchedResBFS.end());
	sort(vecCompBFS.begin(), vecCompBFS.end(), [](pair<int, int> pairA, pair<int, int> pairB) { return pairA.second < pairB.second; });
	for (auto iter : vecCompBFS)
		cout << iter.first + 1 << " ";
	cout << '\n';

	return 0;
}
