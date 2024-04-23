#include "Problem_1475.h"

using namespace std;

#define CTOI(value) int(value) - '0'

#include <string>
#include <iostream>
#include <unordered_map>

int CProblem_1475::Solve_Problem()
{
    string strInput = { };
    cin >> strInput;

    unordered_map<int, int> mapContainer;
    for (int iIndex = 0; iIndex < 9; ++iIndex)
        mapContainer.emplace(iIndex, 0);

    for (int iIndex = 0; iIndex < strInput.size(); ++iIndex)
    {
        auto iter = mapContainer.find(CTOI(strInput[iIndex]) == 9 ? 6 : CTOI(strInput[iIndex]));
        iter->second++;
    }

    int iMax = { -1 };
    auto iter = mapContainer.begin();
    while (iter != mapContainer.end())
    {
        iMax = max(iMax, (iter->first == 6 ? iter->second / 2 + iter->second % 2 : iter->second));
        iter++;
    }

    cout << iMax << '\n';

    return 0;
}
