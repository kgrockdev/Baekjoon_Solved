#include "Problem_1504.h"

#include <set>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

typedef struct tagNode
{
    int iCurrNode = { };
    int iSumWeight = { };

    bool bReqNodeA = { false };
    bool bReqNodeB = { false };

    set<int> setSearched;

    bool operator()(tagNode tNodeA, tagNode tNodeB)
    {
        return tNodeA.iSumWeight < tNodeB.iSumWeight;
    }
} NODE;

int CProblem_1504::Solve_Problem()
{
    int iNumNode = { }, iNumEdge = { };
    cin >> iNumNode >> iNumEdge;

    multimap<int, pair<int, int>> mapGraph;
    for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
    {
        int iSNode = { }, iENode = { }, iWeight = { };
        cin >> iSNode >> iENode >> iWeight;

        mapGraph.emplace(iSNode, pair<int, int> { iENode, iWeight });
    }

    int iReqNodeA = { }, iReqNodeB = { };
    cin >> iReqNodeA >> iReqNodeB;

    NODE tNode = { };
    tNode.iCurrNode = 1;
    tNode.iSumWeight = 0;
    tNode.setSearched.emplace(1);

    priority_queue<NODE, vector<NODE>, NODE> pqContainer;
    pqContainer.emplace(tNode);

    while (pqContainer.size() > 0)
    {
        NODE tNode = pqContainer.top();
        pqContainer.pop();

        if (tNode.iCurrNode == iNumNode)
        {
            if (tNode.bReqNodeA && tNode.bReqNodeB)
            {
                cout << tNode.iSumWeight;
                return 0;
            }
            else
                continue;
        }

        for (auto iter = mapGraph.lower_bound(tNode.iCurrNode); iter != mapGraph.upper_bound(tNode.iCurrNode); ++iter)
        {
            int iFindNode = iter->second.first;
            auto findIter = tNode.setSearched.find(iFindNode);
            if (findIter != tNode.setSearched.end())
                continue;

            NODE tSrcNode = tNode;
            tSrcNode.iCurrNode = iFindNode;
            tSrcNode.iSumWeight += iter->second.second;
            tSrcNode.setSearched.emplace(iFindNode);

            if (tSrcNode.iCurrNode == iReqNodeA)
                tSrcNode.bReqNodeA = true;

            if (tSrcNode.iCurrNode == iReqNodeB)
                tSrcNode.bReqNodeB = true;

            pqContainer.emplace(tSrcNode);
        }
    }

    cout << -1;
    return 0;
}