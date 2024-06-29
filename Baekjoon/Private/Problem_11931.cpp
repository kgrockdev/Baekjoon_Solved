#include "Problem_11931.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_11931::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    vector<int> vecContainer;

    int iNum = { };
    cin >> iNum;

    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        vecContainer.push_back(iSrc);
    }

    sort(vecContainer.begin(), vecContainer.end(), greater<>());

    for (auto& iter : vecContainer)
        cout << iter << '\n';

    return 0;
}
