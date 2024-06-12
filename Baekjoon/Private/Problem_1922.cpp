#include "Problem_1922.h"

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

bool Union_1922(unordered_map<int, int>& mapUnionFind, int iNodeA, int iNodeB)
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

typedef struct tagNetwork
{
    int iNodeA = { };
    int iNodeB = { };

    int iWeight = { };
} NETWORK;

int CProblem_1922::Solve_Problem()
{
    int iNumNode = { }, iNumEdge = { };
    cin >> iNumNode >> iNumEdge;

    unordered_map<int, int> mapUnionFind;
    for (int iNode = 0; iNode < iNumNode; ++iNode)
        mapUnionFind.emplace(iNode + 1, iNode + 1);

    vector<NETWORK> vecNetwork;
    for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
    {
        NETWORK tNetwork = { };
        cin >> tNetwork.iNodeA >> tNetwork.iNodeB >> tNetwork.iWeight;

        vecNetwork.push_back(tNetwork);
    }

    sort(vecNetwork.begin(), vecNetwork.end(),
        [](NETWORK tNetA, NETWORK tNetB) { return tNetA.iWeight > tNetB.iWeight; }
    );

    int iAnswer = { };
    while (vecNetwork.size() > 0)
    {
        NETWORK tNetwork = vecNetwork.back();
        vecNetwork.pop_back();

        if (Union_1922(mapUnionFind, tNetwork.iNodeA, tNetwork.iNodeB) == true)
            iAnswer += tNetwork.iWeight;
    }

    cout << iAnswer << endl;

    return 0;
}
