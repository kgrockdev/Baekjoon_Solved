#include "Problem_30802.h"

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int CProblem_30802::Solve_Problem()
{
    int iNumEntry = { };
    cin >> iNumEntry;

    vector<int> vecSize;
    for (int iIndex = 0; iIndex < 6; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        vecSize.push_back(iSrc);
    }

    int iBundleT = { }, iBundleP = { };
    cin >> iBundleT >> iBundleP;

    int iAnsT = { };
    for (auto iter : vecSize)
    {
        int iSrc = iter / iBundleT;
        iSrc += (iter % iBundleT > 0) ? 1 : 0;

        iAnsT += iSrc;
    }
    cout << iAnsT << '\n';
    cout << iNumEntry / iBundleP << " " << iNumEntry % iBundleP << '\n';

    return 0;
}
