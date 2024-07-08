#include "Problem_11054.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_11054::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    vector<int> vecFwContainer;
    vecFwContainer.reserve(iNum + 1);
    vecFwContainer.push_back(0);

    vector<int> vecReContainer;
    vecReContainer.reserve(iNum + 1);

    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        vecFwContainer.push_back(iSrc);
        vecReContainer.push_back(iSrc);
    }

    vecReContainer.push_back(0);
    reverse(vecReContainer.begin(), vecReContainer.end());

    // Memoization - Forawrd
    vector<int> vecForwardMemo;
    vecForwardMemo.reserve(iNum + 1);

    for (int iIndex = 0; iIndex < iNum + 1; ++iIndex)
        vecForwardMemo.push_back(0);

    for (int iMemo = 1; iMemo < iNum + 1; ++iMemo)
    {
        int iElem = { 1 };
        int iElemMemo = { };
        for (; iElem < iMemo; ++iElem)
        {
            if (vecFwContainer[iMemo] > vecFwContainer[iElem])
            {
                iElemMemo = (iElemMemo > vecForwardMemo[iElem]) ? iElemMemo : vecForwardMemo[iElem];
            }
        }

        vecForwardMemo[iMemo] = iElemMemo + 1;
    }

    // Memoization - Reverse
    vector<int> vecReverseMemo;
    vecReverseMemo.reserve(iNum + 1);

    for (int iIndex = 0; iIndex < iNum + 1; ++iIndex)
        vecReverseMemo.push_back(0);

    for (int iMemo = 1; iMemo < iNum + 1; ++iMemo)
    {
        int iElem = { 1 };
        int iElemMemo = { };
        for (; iElem < iMemo; ++iElem)
        {
            if (vecReContainer[iMemo] > vecReContainer[iElem])
            {
                iElemMemo = (iElemMemo > vecReverseMemo[iElem]) ? iElemMemo : vecReverseMemo[iElem];
            }
        }

        vecReverseMemo[iMemo] = iElemMemo + 1;
    }

    reverse(vecReverseMemo.begin(), vecReverseMemo.end());

    int iAnswer = { };
    for (int iMemo = 1; iMemo < iNum + 1; ++iMemo)
    {
        int iSrc = vecForwardMemo[iMemo] + vecReverseMemo[iMemo - 1];
        iAnswer = (iAnswer > iSrc) ? iAnswer : iSrc;
    }

    cout << iAnswer - 1 << endl;

    return 0;
}

// 0 2 3 5 10 5 20 3 15 12 6 3 2 1 0
// 0 1 2 3 4  3 5  2 5  5  4 2 1 1  
//   2 3 4 5  4 7  3 6  5  4 3 2 1 0