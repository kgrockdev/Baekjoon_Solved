#include "Problem_9625.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_9625::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    vector<pair<int, int>> vecContainer;
    vecContainer.push_back(pair<int, int> { 0, 1 });
    vecContainer.push_back(pair<int, int> { 1, 1 });

    for (int iIndex = 2; iIndex < iNum; ++iIndex)
    {
        pair<int, int> iter = vecContainer[iIndex - 1];
        vecContainer.push_back(pair<int, int>{ iter.second, iter.first + iter.second });
    }

    cout << vecContainer[iNum - 1].first << " " << vecContainer[iNum - 1].second << '\n';

    return 0;
}