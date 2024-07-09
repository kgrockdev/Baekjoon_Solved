#include "Problem_1753.h"

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

#define INF 10000001

using namespace std;

int CProblem_1753::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumNode = { }, iNumEdge = { }, iStartNode = { };
    cin >> iNumNode >> iNumEdge >> iStartNode;

    vector<int> vecWeight;
    unordered_map<int, vector<pair<int, int>>> mapGraph;
    for (int iNode = 0; iNode < iNumNode; ++iNode)
    {
        vecWeight.push_back(INF);
        mapGraph.emplace(iNode + 1, vector<pair<int, int>>{ });
    }
    vecWeight.push_back(INF);

    for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
    {
        int iStart = { }, iEnd = { }, iWeight = { };
        cin >> iStart >> iEnd >> iWeight;

        mapGraph.find(iStart)->second.push_back({ iWeight, iEnd });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqContainer;
    pqContainer.emplace(0, iStartNode);

    while (pqContainer.size() > 0)
    {
        pair<int, int> pairCurrNode = pqContainer.top();
        pqContainer.pop();

        if (vecWeight[pairCurrNode.second] < pairCurrNode.first)
            continue;

        vecWeight[pairCurrNode.second] = pairCurrNode.first;

        auto mapIter = mapGraph.find(pairCurrNode.second);
        if (mapIter != mapGraph.end())
        {
            for (auto& iter : mapIter->second)
            {
                if (vecWeight[iter.second] > vecWeight[pairCurrNode.second] + iter.first)
                {
                    vecWeight[iter.second] = vecWeight[pairCurrNode.second] + iter.first;
                    pqContainer.emplace(vecWeight[pairCurrNode.second] + iter.first, iter.second);
                }
            }
        }
    }

    for (int iIndex = 1; iIndex < iNumNode + 1; ++iIndex)
    {
        if (vecWeight[iIndex] == INF)
            cout << "INF" << '\n';
        else
            cout << vecWeight[iIndex] << '\n';
    }

    return 0;
}