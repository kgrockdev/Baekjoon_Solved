#include "Problem_4158.h"

using namespace std;

#include <vector>
#include <iostream>
#include <unordered_set>

int CProblem_4158::Solve_Problem()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> vecDupContainer;

    while (true)
    {
        int iNumA = { }, iNumB = { };
        cin >> iNumA >> iNumB;

        if (iNumA == 0 && iNumB == 0)
            break;

        unordered_set<long long> setContainer;

        int iDup = { };
        for (int iIndex = 0; iIndex < iNumA; ++iIndex)
        {
            long long llSrc = { };
            cin >> llSrc;

            setContainer.emplace(llSrc);
        }

        for (int iIndex = 0; iIndex < iNumB; ++iIndex)
        {
            long long llSrc = { };
            cin >> llSrc;

            auto iter = setContainer.find(llSrc);
            if (iter != setContainer.end())
                ++iDup;
        }

        vecDupContainer.push_back(iDup);
    }

    for (auto& iter : vecDupContainer)
        cout << iter << '\n';

    return 0;
}
