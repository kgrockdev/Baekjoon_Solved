#include "Problem_15486.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_15486::Solve_Problem()
{
    int iDays = { };
    cin >> iDays;

    vector<pair<int, int>> vecMemo;
    vecMemo.reserve(iDays + 10);

    vector<pair<int, int>> vecContainer;
    vecMemo.reserve(iDays + 10);

    for (int iDay = 0; iDay < iDays; ++iDay)
    {
        int iReq = { }, iPay = { };
        cin >> iReq >> iPay;

        vecMemo.push_back({ -1, 0 });
        vecContainer.push_back({ iReq, iPay });
    }

    int iDigit = iDays;
    for (int iDay = iDays - 1; iDay >= 0; --iDay)
    {
        if ((iDay + 1) + vecContainer[iDay].first > iDays)
            continue;

        if (vecMemo[iDay + vecContainer[iDay].first].second <= vecContainer[iDay].second)
        {
            int iSearch = iDigit;
            if (iSearch == iDays)
                iSearch = -1;

            int iAcc = 0;
            // if ()

            for (int iSrcDay = iDay; iSrcDay < iDigit; ++iSrcDay)
            {
                vecMemo[iSrcDay].first = iAcc + iSearch;
                vecMemo[iSrcDay].second = vecContainer[iDay].second;
            }

            iDigit = iDay;
        }
    }

    return 0;
}
