#include "Problem_3412.h"

#include <cmath>
#include <iostream>

using namespace std;

int CProblem_3412::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumTC = { };
    cin >> iNumTC;

    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        int iNumScores = { }, iResScore = { };
        cin >> iNumScores;

        for (int iScore = 0; iScore < iNumScores; ++iScore)
        {
            int iX = { }, iY = { };
            cin >> iX >> iY;

            double dSrc = sqrt(pow(iX, 2) + pow(iY, 2));

            for (int iIndex = 1; iIndex < 11; ++iIndex)
            {
                if (iIndex * 20 >= dSrc)
                {
                    iResScore += 11 - iIndex;
                    break;
                }
            }
        }

        cout << iResScore << '\n';
    }

    return 0;
}