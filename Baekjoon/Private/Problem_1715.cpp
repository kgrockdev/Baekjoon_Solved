#include "Problem_1715.h"

#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_1715::Solve_Problem()
{
    priority_queue<int, vector<int>, greater<int>> pqContainer;

    int iNum = { };
    cin >> iNum;

    for (int iIdx = 0; iIdx < iNum; ++iIdx)
    {
        int iSrc = { };
        cin >> iSrc;

        pqContainer.emplace(iSrc);
    }

    int iAcc = { };
    while (pqContainer.size() > 1)
    {
        int iSrcA = pqContainer.top();
        pqContainer.pop();

        int iSrcB = pqContainer.top();
        pqContainer.pop();

        iAcc += (iSrcA + iSrcB);
        pqContainer.emplace(iSrcA + iSrcB);
    }

    cout << iAcc << '\n';

    return 0;
}
