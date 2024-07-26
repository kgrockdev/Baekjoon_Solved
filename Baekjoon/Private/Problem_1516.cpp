#include "Problem_1516.h"

using namespace std;

#include <list>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

typedef struct tagStructInfo1516
{
    int iNum = { };
    int iCost = { };
    int iResCost = { };

    list<int> lstReq;
    list<int> lstLinear;
} STINFO_1516;

// 위상정렬
int CProblem_1516::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { };
    cin >> iNum;

    list<int> lstBFS;
    vector<STINFO_1516> vecStruct;

    for (int iIdx = 0; iIdx < iNum; ++iIdx)
    {
        STINFO_1516 tInfo = { };
        tInfo.iNum = iIdx + 1;
        cin >> tInfo.iCost;

        while (true)
        {
            int iSrc = { };
            cin >> iSrc;

            if (iSrc == -1)
                break;
            else
                tInfo.lstReq.push_back(iSrc);
        }

        if (tInfo.lstReq.size() == 0)
            lstBFS.push_back(tInfo.iNum);

        vecStruct.push_back(tInfo);
    }

    for (auto& iter : vecStruct)
    {
        for (auto nearIter : iter.lstReq)
        {
            vecStruct[nearIter - 1].lstLinear.push_back(iter.iNum);
        }
    }

    while (lstBFS.size() > 0)
    {
        int iNext = lstBFS.front();
        lstBFS.pop_front();

        for (auto nearIter : vecStruct[iNext - 1].lstLinear)
        {
            vecStruct[nearIter - 1].lstReq.remove(iNext);
            vecStruct[nearIter - 1].iResCost =
                max((vecStruct[iNext - 1].iCost + vecStruct[iNext - 1].iResCost), vecStruct[nearIter - 1].iResCost);

            if (vecStruct[nearIter - 1].lstReq.size() == 0)
            {
                lstBFS.push_back(nearIter);
            }
        }
    }

    for (auto& iter : vecStruct)
    {
        cout << iter.iCost + iter.iResCost << "\n";
    }

    return 0;
}