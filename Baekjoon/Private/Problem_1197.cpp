#include "Problem_1197.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct tagNetwork
{
    int iX = { };
    int iY = { };

    int iWeight = { };
} NETWORK;

bool Union_1197(unordered_map<int, int>& mapUnionFind, int iX, int iY)
{
    int iUnionX = { iX };
    while (iUnionX != mapUnionFind.find(iUnionX)->second)
        iUnionX = mapUnionFind.find(iUnionX)->second;

    int iUnionY = { iY };
    while (iUnionY != mapUnionFind.find(iUnionY)->second)
        iUnionY = mapUnionFind.find(iUnionY)->second;

    if (iUnionX == iUnionY)
        return false;
    else
    {
        if (iUnionX < iUnionY)
            mapUnionFind.find(iUnionY)->second = iUnionX;
        else
            mapUnionFind.find(iUnionX)->second = iUnionY;

        return true;
    }
}

int CProblem_1197::Solve_Problem()
{
    int iNumVertex = { }, iNumEdge = { };
    cin >> iNumVertex >> iNumEdge;

    vector<NETWORK> vecNetwork;
    unordered_map<int, int> mapUnionFind;

    for (int iVertex = 0; iVertex < iNumVertex; ++iVertex)
        mapUnionFind.emplace(iVertex + 1, iVertex + 1);

    for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
    {
        NETWORK tNetwork = { };
        cin >> tNetwork.iX >> tNetwork.iY >> tNetwork.iWeight;

        vecNetwork.push_back(tNetwork);
    }

    sort(vecNetwork.begin(), vecNetwork.end(),
        [](NETWORK tNetA, NETWORK tNetB) { return tNetA.iWeight > tNetB.iWeight; }
    );

    int iWeightSum = { };
    while (vecNetwork.size() > 0)
    {
        NETWORK tNetwork = vecNetwork.back();
        vecNetwork.pop_back();

        if (Union_1197(mapUnionFind, tNetwork.iX, tNetwork.iY))
            iWeightSum += tNetwork.iWeight;
    }

    cout << iWeightSum << endl;

    return 0;
}
