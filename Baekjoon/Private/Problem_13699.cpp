#include "Problem_13699.h"

using namespace std;

#include <iostream>
#include <unordered_map>

unordered_map<int, unsigned long long>mapContainer13699;

unsigned long long Calc_13699(int iNum)
{
    auto iter = mapContainer13699.find(iNum);
    if (iter != mapContainer13699.end())
        return iter->second;
    else
    {
        unsigned long long ullSrc = { };
        for (int iIndex = 0; iIndex < iNum; ++iIndex)
            ullSrc += Calc_13699(iIndex) * Calc_13699(iNum - iIndex - 1);

        mapContainer13699.emplace(iNum, ullSrc);
        return ullSrc;
    }
}

int CProblem_13699::Solve_Problem()
{
    mapContainer13699.emplace(0, 1);

    int iNum = { };
    cin >> iNum;

    cout << Calc_13699(iNum) << '\n';

    return 0;
}
