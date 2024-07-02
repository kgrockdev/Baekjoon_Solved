#include "Problem_2447.h"

#include <map>
#include <cmath>
#include <iostream>

using namespace std;

map<int, map<pair<int, int>, bool>> mapContainer2447;

bool Calc_2447(int iNumRecursive, int iRecursive, int iRow, int iCol)
{
    if (iRecursive == 1)
    {
        if (iRow == 1 && iCol == 1)
            return false;
        else
            return true;
    }

    auto mapRecursive = mapContainer2447.find(iRecursive);
    if (iNumRecursive != iRecursive)
    {
        if (mapRecursive != mapContainer2447.end())
        {
            auto pairIter = mapRecursive->second.find(pair<int, int>{ iRow, iCol });
            if (pairIter != mapRecursive->second.end())
            {
                return pairIter->second;
            }
        }
        else
        {
            mapContainer2447.emplace(iRecursive, map<pair<int, int>, bool>());
            mapRecursive = mapContainer2447.find(iRecursive);
        }
    }

    bool bCheck = Calc_2447(iNumRecursive, iRecursive - 1, iRow % 3, iCol % 3) && Calc_2447(iNumRecursive, iRecursive - 1, iRow / 3, iCol / 3);

    if (iNumRecursive != iRecursive)
    {
        mapRecursive->second.emplace(pair<int, int>{ iRow, iCol }, bCheck);
    }

    return bCheck;
}

int CProblem_2447::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { }, iSrc = { }, iRecursive = { 0 };
    cin >> iNum; iSrc = iNum;
    while (iSrc != 1)
    {
        iSrc /= 3;
        iRecursive++;
    }

    for (int iRow = 0; iRow < iNum; ++iRow)
    {
        for (int iCol = 0; iCol < iNum; ++iCol)
        {
            cout << ((Calc_2447(iRecursive, iRecursive, iRow, iCol) == true) ? "*" : " ");
        }
        cout << '\n';
    }

    return 0;
}
