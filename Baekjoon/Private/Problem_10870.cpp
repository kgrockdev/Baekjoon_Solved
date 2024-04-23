#include "Problem_10870.h"

using namespace std;

#include <iostream>
#include <unordered_map>

unordered_map<int, long long> mapMemo;

long long Calc_Fibb_10870(long long iSrc)
{
    auto iter = mapMemo.find(iSrc);
    if (iter != mapMemo.end())
        return iter->second;
    else
    {
        if (iSrc > 1)
        {
            long long iTemp = Calc_Fibb_10870(iSrc - 1) + Calc_Fibb_10870(iSrc - 2);
            mapMemo.emplace(iSrc, iTemp);

            return iTemp;
        }
        else
            return iSrc;
    }
}

int CProblem_10870::Solve_Problem()
{
    int iQuery = { };
    cin >> iQuery;

    cout << Calc_Fibb_10870(iQuery) << '\n';

    return 0;
}
