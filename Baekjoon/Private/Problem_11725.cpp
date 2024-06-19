#include "Problem_11725.h"

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void Union_11725(unordered_map<int, int>& mapUnionFind, int iA, int iB)
{
    if (iA == 1)
        mapUnionFind.find(iB)->second = iA;
    else
    {
        if (iA == mapUnionFind.find(iA)->second)
            mapUnionFind.find(iA)->second = iB;
        else
            mapUnionFind.find(iB)->second = iA;
    }
}

int CProblem_11725::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumNode = { };
    cin >> iNumNode;

    unordered_map<int, int> mapUnionFind;
    for (int iNode = 0; iNode < iNumNode; ++iNode)
        mapUnionFind.emplace(iNode + 1, iNode + 1);

    vector<pair<int, int>> vecEdges;
    for (int iEdge = 0; iEdge < iNumNode - 1; ++iEdge)
    {
        int iA = { }, iB = { };
        cin >> iA >> iB;

        if (iA < iB) vecEdges.push_back({ iA, iB });
        else vecEdges.push_back({ iB, iA });
    }
    
    unordered_set<int> setUnit; setUnit.emplace(1);
    while (vecEdges.size() > 0)
    {
        for (auto iter = vecEdges.begin(); iter != vecEdges.end();)
        {
            if (setUnit.find(iter->first) != setUnit.end() || setUnit.find(iter->second) != setUnit.end())
            {
                setUnit.emplace(iter->first);
                setUnit.emplace(iter->second);
                Union_11725(mapUnionFind, iter->first, iter->second);
                iter = vecEdges.erase(iter);
            }
            else
                ++iter;
        }
    }

    for (int iNode = 1; iNode < iNumNode; ++iNode)
        cout << mapUnionFind.find(iNode + 1)->second << '\n';

    return 0;
}
