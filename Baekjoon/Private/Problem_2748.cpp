#include "Problem_2748.h"

using namespace std;

#include <map>
#include <iostream>

map<int, long long> mapMemo;

long long Calc_Fibb(long long iSrc)
{
    auto iter = mapMemo.find(iSrc);
    if (iter != mapMemo.end())
        return iter->second;
    else
    {
        if (iSrc > 1)
        {
            long long iTemp = Calc_Fibb(iSrc - 1) + Calc_Fibb(iSrc - 2);
            mapMemo.emplace(iSrc, iTemp);

            return iTemp;
        }
        else
            return iSrc;
    }
}

int CProblem_2748::Solve_Problem()
{
    int iQuery = { };
    cin >> iQuery;

    cout << Calc_Fibb(iQuery) << '\n';

    return 0;
}
