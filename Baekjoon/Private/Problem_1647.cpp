#include "Problem_1647.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct tagNetwork
{
    int iWeight = { };

    int iX = { };
    int iY = { };
} NETWORK;

bool Union_1647(unordered_map<int, int>& mapUnionFind, int iNodeA, int iNodeB)
{
    int iUnionA = { iNodeA };
    while (iUnionA != mapUnionFind.find(iUnionA)->second)
        iUnionA = mapUnionFind.find(iUnionA)->second;

    int iUnionB = { iNodeB };
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

        return true;
    }
}

int CProblem_1647::Solve_Problem()
{
    int iNumNode = { }, iNumEdge = { };
    cin >> iNumNode >> iNumEdge;

    unordered_map<int, int> mapUnionFind;
    for (int iNode = 0; iNode < iNumNode; ++iNode)
        mapUnionFind.emplace(iNode + 1, iNode + 1);

    vector<NETWORK> vecNetwork;
    for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
    {
        int iX = { }, iY = { }, iWeight = {};
        cin >> iX >> iY >> iWeight;

        NETWORK tNetwork = { };
        tNetwork.iX = iX;
        tNetwork.iY = iY;
        tNetwork.iWeight = iWeight;

        vecNetwork.push_back(tNetwork);
    }

    sort(vecNetwork.begin(), vecNetwork.end(), 
        [](NETWORK tNetA, NETWORK tNetB) { return tNetA.iWeight > tNetB.iWeight; }
    );

    int iWeightSum = { }, iHighWeight = { };
    while (vecNetwork.size() > 0)
    {
        NETWORK tNetwork = vecNetwork.back();
        vecNetwork.pop_back();

        if (Union_1647(mapUnionFind, tNetwork.iX, tNetwork.iY) == true)
        {
            iWeightSum += tNetwork.iWeight;
            iHighWeight = (iHighWeight < tNetwork.iWeight) ? tNetwork.iWeight : iHighWeight;
        }
    }

    cout << iWeightSum - iHighWeight << endl;

    return 0;
}
