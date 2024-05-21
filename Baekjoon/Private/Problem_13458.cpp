#include "Problem_13458.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_13458::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumTestCenter = { };
    cin >> iNumTestCenter;

    vector<int> vecTC;
    for (int iTC = 0; iTC < iNumTestCenter; ++iTC)
    {
        int iSrc = { };
        cin >> iSrc;
        vecTC.push_back(iSrc);
    }

    int iMainNum = { }, iSubNum = { };
    cin >> iMainNum >> iSubNum;

    unsigned long long ullAns = { };
    for (auto& iter : vecTC)
    {
        int iSrc = { };
        iSrc = max(iter - iMainNum, 0);

        ullAns += iSrc / iSubNum;
        ullAns += (iSrc % iSubNum != 0) ? 1 : 0;
    }

    cout << iNumTestCenter + ullAns << '\n';

    return 0;
}
