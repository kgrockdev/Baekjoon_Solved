#include "Problem_11724.h"

#include <map>
#include <set>
#include <list>
#include <iostream>

using namespace std;

int CProblem_11724::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    map<int, set<int>> mapGraph;

    int iNumNode = { }, iNumEdge = { };
    cin >> iNumNode >> iNumEdge;

    for (int iNode = 1; iNode <= iNumNode; ++iNode)
        mapGraph.emplace(iNode, set<int>{ });

    int iNodeA = { }, iNodeB = { };
    for (int iEdge = 0; iEdge < iNumEdge; ++iEdge)
    {
        cin >> iNodeA >> iNodeB;

        auto iter = mapGraph.find(iNodeA);
        if (iter != mapGraph.end())
            iter->second.emplace(iNodeB);
        else
            mapGraph.emplace(iNodeA, set<int>{ iNodeB });

        iter = mapGraph.find(iNodeB);
        if (iter != mapGraph.end())
            iter->second.emplace(iNodeA);
        else
            mapGraph.emplace(iNodeB, set<int>{ iNodeA });
    }

    int iAns = { };
    while (mapGraph.size() > 0)
    {
        iAns++;

        list<int> listSearchBFS; listSearchBFS.push_back(mapGraph.begin()->first);
        while (listSearchBFS.size() > 0)
        {
            int iSrc = listSearchBFS.front();

            auto iterSearchBegin = mapGraph.find(iSrc);
            if (iterSearchBegin != mapGraph.end())
            {
                for (auto& iter : iterSearchBegin->second)
                    listSearchBFS.push_back(iter);

                mapGraph.erase(iterSearchBegin);
            }

            listSearchBFS.pop_front();
        }
    }

    cout << iAns << '\n';

    return 0;
}
