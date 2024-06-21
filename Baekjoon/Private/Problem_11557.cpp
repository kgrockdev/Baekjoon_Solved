#include "Problem_11557.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_11557::Solve_Problem()
{
    int iNumTC = { };
    cin >> iNumTC;

    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        vector<pair<int, string>> vecContainer;

        int iNumCollege = { };
        cin >> iNumCollege;

        for (int iCollege = 0; iCollege < iNumCollege; ++iCollege)
        {
            int iSrc = { };
            string strSrc = { };

            cin >> strSrc >> iSrc;

            vecContainer.push_back({ iSrc, strSrc });
        }

        sort(vecContainer.begin(), vecContainer.end(),
            [](pair<int, string> pairA, pair<int, string> pairB) { return pairA.first > pairB.first; }
        );

        cout << vecContainer[0].second << endl;
    }

    return 0;
}
