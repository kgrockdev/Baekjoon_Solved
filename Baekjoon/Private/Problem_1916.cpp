#include "Problem_1916.h"

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define INT_MAX       2147483647

using namespace std;

int CProblem_1916::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumNode = { }, iNumEdge = { };
    cin >> iNumNode >> iNumEdge;

    const int iMaxNode = 1001;
    
    unordered_map<int, vector<pair<int, int>>> mapNetwork; // Node, Weight, Next
    for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
    {
        int iSrc = { };
        pair<int, int> pairNetwork = { };
        cin >> iSrc >> pairNetwork.second >> pairNetwork.first;

        auto mapIter = mapNetwork.find(iSrc);
        if (mapIter == mapNetwork.end())
            mapNetwork.emplace(iSrc, vector<pair<int, int>>{ pairNetwork });
        else
            mapIter->second.push_back(pairNetwork);
    }

    int iStart = { }, iEnd = { };
    cin >> iStart >> iEnd;

    vector<int> vecDijkstra;
    for (int iNode = 0; iNode < iNumNode + 1; ++iNode)
        vecDijkstra.push_back(INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqContainer;
    pqContainer.emplace(0, iStart);

    while (pqContainer.size() > 0)
    {
        pair<int, int> pairSrc = pqContainer.top(); // Weight, Next (Current)
        pqContainer.pop();

        if (vecDijkstra[pairSrc.second] < pairSrc.first)
            continue;

        vecDijkstra[pairSrc.second] = pairSrc.first;
        
        auto mapIter = mapNetwork.find(pairSrc.second);
        if (mapIter != mapNetwork.end())
        {
            for (auto& iter : mapIter->second) // Weight, Next
            {
                if (vecDijkstra[iter.second] > iter.first + vecDijkstra[pairSrc.second])
                {
                    vecDijkstra[iter.second] = iter.first + vecDijkstra[pairSrc.second];
                    pqContainer.emplace(iter.first + vecDijkstra[pairSrc.second], iter.second);
                }
            }
        }
    }

    cout << vecDijkstra[iEnd] << endl;

    return 0;
}

/*

    int iNumNode = { }, iNumEdge = { };
    cin >> iNumNode >> iNumEdge;

    unordered_map<int, vector<NETWORK1916>> mapNetwork;
    for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
    {
        int iSrc = { };
        NETWORK1916 tNetwork = { };
        cin >> iSrc >> tNetwork.iNext >> tNetwork.iWeight;

        auto mapIter = mapNetwork.find(iSrc);
        if (mapIter == mapNetwork.end())
            mapNetwork.emplace(iSrc, vector<NETWORK1916>{ tNetwork });
        else
            mapIter->second.push_back(tNetwork);
    }

    int iStart = { }, iEnd = { };
    cin >> iStart >> iEnd;

    vector<int> vecRoute;
    for (int iNode = 0; iNode < iNumNode + 1; ++iNode)
    {
        vecRoute.push_back(INT_MAX);
    }
    vecRoute[iStart] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqContainer;
    pqContainer.emplace(0, iStart);

    while (pqContainer.size() > 0)
    {
        pair<int, int> tNetwork = pqContainer.top();
        pqContainer.pop();

        auto mapIter = mapNetwork.find(tNetwork.second);
        if (mapIter != mapNetwork.end())
        {
            for (auto& iter : mapIter->second)
            {
                if (vecRoute[iter.iNext] > iter.iWeight + vecRoute[tNetwork.second])
                {
                    vecRoute[iter.iNext] = iter.iWeight + vecRoute[tNetwork.second];
                    pqContainer.emplace(vecRoute[iter.iNext], iter.iNext);
                }
            }
        }
    }

    cout << vecRoute[iEnd] << endl;

*/

/*
 
    typedef struct tagNetwork
    {
        int iA = { };
        int iB = { };

        int iWeight = { };
    } NETWORK;

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

*/