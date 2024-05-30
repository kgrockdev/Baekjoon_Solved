#include "Problem_1068.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_1068::Solve_Problem()
{
    int iNumNode = { }, iNode = { }, iRoot = { }, iRes = { };
    cin >> iNumNode;

    vector<vector<int>> vecTree;
    for (int iIndex = 0; iIndex < iNumNode; ++iIndex)
        vecTree.push_back(vector<int>{ });
    
    for (int iIndex = 0; iIndex < iNumNode; ++iIndex)
    {
        cin >> iNode;
        if (iNode == -1)
            iRoot = iIndex;
        else
            vecTree[iNode].push_back(iIndex);
    }

    cin >> iNode;
    vecTree[iNode].clear();
    vecTree[iNode].push_back(-1);

    vector<int> vecDFS;
    vecDFS.push_back(iRoot);

    while (vecDFS.size() > 0)
    {
        int iSearch = vecDFS.back();
        vecDFS.pop_back();

        if (vecTree[iSearch].size() == 0)
            ++iRes;
        else if (vecTree[iSearch].front() == -1)
        {
            if (vecTree[iNode].size() == 1 && vecTree[iNode][0] == iSearch)
                ++iRes;
            continue;
        }
        else
        {
            for (auto iter : vecTree[iSearch])
                vecDFS.push_back(iter);
        }

        iNode = iSearch;
    }

    cout << iRes << endl;

    return 0;
}
