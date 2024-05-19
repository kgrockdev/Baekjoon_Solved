#include "Problem_9372.h"

#include <iostream>

using namespace std;

int CProblem_9372::Solve_Problem()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int iNumTC = { };
    cin >> iNumTC;

    int iNumNation = { }, iNumFlight = { };
    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        cin >> iNumNation >> iNumFlight;

        int iSrc = { };
        for (int iFlight = 0; iFlight < iNumFlight; ++iFlight)
            cin >> iSrc >> iSrc;

        cout << iNumNation - 1 << '\n';
    }

    return 0;
}
