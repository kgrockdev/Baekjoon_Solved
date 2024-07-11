#include "Problem_1654.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define ULL unsigned long long

int CProblem_1654::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumLan = { }, iReqLan = { };
    cin >> iNumLan >> iReqLan;

    vector<ULL> vecContainer;
    for (int iIndex = 0; iIndex < iNumLan; ++iIndex)
    {
        ULL ullSrc = { };
        cin >> ullSrc;

        vecContainer.push_back(ullSrc);
    }

    sort(vecContainer.begin(), vecContainer.end());

    ULL ullMin = { 1 }, ullMax = { vecContainer.back() };

    while (true)
    {
        ULL ullSrc = (ullMin + ullMax) / 2;
        ULL ullNumSrc = { };

        for (auto iter : vecContainer)
            ullNumSrc += iter / ullSrc;

        if (ullNumSrc > iReqLan)
            ullMin = ullSrc;
        else if (ullNumSrc < iReqLan)
            ullMax = ullSrc;
        else
            break;
    }

    int iAnswer = { };
    for (int iIndex = ullMax; iIndex > ullMin - 1; --iIndex)
    {
        int iNumSrc = { };

        for (auto iter : vecContainer)
            iNumSrc += iter / iIndex;

        if (iNumSrc == iReqLan)
        {
            iAnswer = iIndex;
            break;
        }
    }

    cout << iAnswer << endl;

    return 0;
}