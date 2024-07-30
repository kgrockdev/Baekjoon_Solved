#include "Problem_2467.h"

#include <cmath>
#include <queue>
#include <iostream>

#define INF 2000000010

using namespace std;

typedef struct tagComp2467
{
    int iNum = { };
    bool operator()(tagComp2467& tSrc, tagComp2467& tDst)
    {
        return abs(tSrc.iNum) < abs(tDst.iNum);
    }
} COMP_2467;

int CProblem_2467::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { };
    cin >> iNum;

    priority_queue<COMP_2467, vector<COMP_2467>, COMP_2467> pqContainer;

    for (int iIdx = 0; iIdx < iNum; ++iIdx)
    {
        COMP_2467 tCmp = { };
        cin >> tCmp.iNum;

        pqContainer.emplace(tCmp);
    }

    int iMin = { INF };
    int iAnsA = { }, iAnsB = { };
    while (pqContainer.size() > 0)
    {
        COMP_2467 tSrc = pqContainer.top();
        pqContainer.pop();

        if (pqContainer.size() < 1)
            break;

        int iSrc = tSrc.iNum + pqContainer.top().iNum;
        if (abs(iSrc) < abs(iMin))
        {
            iMin = iSrc;

            iAnsA = min(tSrc.iNum, pqContainer.top().iNum);
            iAnsB = max(tSrc.iNum, pqContainer.top().iNum);
        }
    }

    cout << iAnsA << " " << iAnsB;

    return 0;
}
