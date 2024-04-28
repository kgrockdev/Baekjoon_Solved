#include "Problem_1003.h"

using namespace std;

#include <iostream>
#include <unordered_map>

typedef struct tagFibbValue
{
    int iZero = { };
    int iOne = { };

    tagFibbValue operator+(tagFibbValue tSrc)
    {
        tagFibbValue tTemp = { };

        tTemp.iZero = iZero + tSrc.iZero;
        tTemp.iOne = iOne + tSrc.iOne;
         
        return tTemp;
    }
} FIBV;

unordered_map<int, FIBV> mapFibb1003;

FIBV Calc_Fibb_1003(int iN)
{
    auto iter = mapFibb1003.find(iN);
    if (iter != mapFibb1003.end())
    {
        return iter->second;
    }
    else
    {
        if (iN == 0)
            return FIBV{ 1, 0 };
        else if (iN == 1)
            return FIBV{ 0, 1 };
        else
        {
            FIBV tFibv = Calc_Fibb_1003(iN - 1) + Calc_Fibb_1003(iN - 2);
            mapFibb1003.emplace(iN, tFibv);

            return tFibv;
        }
    }
}

int CProblem_1003::Solve_Problem()
{
    int iNumTC = { };
    cin >> iNumTC;

    for (int iIndex = 0; iIndex < iNumTC; ++iIndex)
    {
        int iNumFibb = { };
        cin >> iNumFibb;

        FIBV iFibv = Calc_Fibb_1003(iNumFibb);
        cout << iFibv.iZero << " " << iFibv.iOne << '\n';
    }

    return 0;
}
