#include "Problem_11053.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_11053::Solve_Problem()
{
    int iNumElem = { };
    cin >> iNumElem;

    vector<int> vecContainer; vecContainer.push_back(0);
    vector<int> vecMemoization; vecMemoization.push_back(0);
    for (int iIndex = 0; iIndex < iNumElem; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        vecContainer.push_back(iSrc);
        vecMemoization.push_back(0);
    }

    int iAnswer = { };
    for (int iElem = 1; iElem < iNumElem + 1; ++iElem)
    {
        int iMemo = { 1 };
        int iMemoValue = { };
        for (; iMemo < iElem; ++iMemo)
        {
            if (vecContainer[iElem] > vecContainer[iMemo])
                iMemoValue = (iMemoValue < vecMemoization[iMemo]) ? vecMemoization[iMemo] : iMemoValue;
        }

        vecMemoization[iElem] = iMemoValue + 1;
        iAnswer = (iAnswer < vecMemoization[iElem]) ? vecMemoization[iElem] : iAnswer;
    }

    cout << iAnswer << endl;

    return 0;
}
