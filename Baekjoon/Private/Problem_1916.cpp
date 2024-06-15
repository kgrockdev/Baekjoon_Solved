#include "Problem_1916.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

typedef struct tagNetwork
{
    int iA = { };
    int iB = { };

    int iWeight = { };
} NETWORK;

using namespace std;

bool Union_1916(unordered_map<int, int>& mapUnionFind, int iA, int iB)
{
    int iUnionA = { iA };
    while (iUnionA != mapUnionFind.find(iUnionA)->second)
        iUnionA = mapUnionFind.find(iUnionA)->second;

    int iUnionB = { iB };
    while (iUnionB != mapUnionFind.find(iUnionB)->second)
        iUnionB = mapUnionFind.find(iUnionB)->second;

    if (iUnionA == iUnionB)
        return false;
    else
    {
        if (iUnionA < iUnionB)
            mapUnionFind.find(iUnionB)->second = iUnionA;
        else
            mapUnionFind.find(iUnionA)->second = iUnionB;
    }

    return true;
}

int CProblem_1916::Solve_Problem()
{
    while (true)
    {
        int iNumNode = { }, iNumEdge = { };
        cin >> iNumNode >> iNumEdge;

        if (iNumNode == 0 && iNumEdge == 0)
            break;

        unordered_map<int, int> mapUnionFind;
        for (int iNode = 0; iNode < iNumNode; ++iNode)
            mapUnionFind.emplace(iNode, iNode);

        int iWeightSum = { };
        vector<NETWORK> vecNetwork;
        for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
        {
            NETWORK tNetwork = { };
            cin >> tNetwork.iA >> tNetwork.iB >> tNetwork.iWeight;

            vecNetwork.push_back(tNetwork);
        }

        sort(vecNetwork.begin(), vecNetwork.end(), [](NETWORK tNetA, NETWORK tNetB) { return tNetA.iWeight > tNetB.iWeight; });

        while (vecNetwork.size() > 0)
        {
            NETWORK tNetwork = vecNetwork.back();
            vecNetwork.pop_back();

            if (Union_1916(mapUnionFind, tNetwork.iA, tNetwork.iB) == false)
                iWeightSum += tNetwork.iWeight;
        }

        cout << iWeightSum << '\n';
    }

    return 0;
}
