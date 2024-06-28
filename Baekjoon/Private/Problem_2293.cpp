#include "Problem_2293.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_2293::Solve_Problem()
{
    int iN = { }, iK = { };
    cin >> iN >> iK;

    vector<int> vecValue;
    vecValue.reserve(iN);

    for (int iIndex = 0; iIndex < iN; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        vecValue.push_back(iSrc);
    }

    int arrMemo[10001] = { };
    arrMemo[0] = 1;

    for (int iCoin = 0; iCoin <= iN; ++iCoin)
    {
        for (int iValue = 0; iValue < iK; ++iValue)
        {
            arrMemo[iValue] = arrMemo[iValue - vecValue[iCoin]];
        }
    }

    cout << arrMemo[iK] << endl;

    return 0;
}
