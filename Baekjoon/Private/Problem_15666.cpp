#include "Problem_15666.h"

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_15666::Solve_Problem()
{
    int iN = { }, iM = { };
    cin >> iN >> iM;

    vector<int> vecContainer;

    int iSrc = { };
    for (int iIndex = 0; iIndex < iN; ++iIndex)
    {
        cin >> iSrc;
        vecContainer.push_back(iSrc);
    }

    sort(vecContainer.begin(), vecContainer.end());

    set<vector<int>> setAns;
    vector<vector<int>> vecDFS;
    for (int iIndex = 0; iIndex < iN; ++iIndex)
        vecDFS.push_back(vector<int>{ iIndex });
    
    while (vecDFS.size() > 0)
    {
        vector<int> vecSrc = vecDFS.back();
        vecDFS.pop_back();

        if (vecSrc.size() == iM)
        {
            vector<int> vecRes;
            for (auto iter : vecSrc)
            {
                vecRes.push_back(vecContainer[iter]);
            }
            setAns.emplace(vecRes);
            continue;
        }

        if (vecContainer.size() < vecSrc.back())
            continue;

        int iFlag = vecSrc.back();
        for (int iIndex = iFlag; iIndex < iN; ++iIndex)
        {
            vector<int> vecTemp = vecSrc;
            vecTemp.push_back(iIndex);

            vecDFS.push_back(vecTemp);
        }
    }

    for (auto iter : setAns)
    {
        for (auto numIter : iter)
        {
            cout << numIter << " ";
        }
        cout << '\n';
    }

    return 0;
}
