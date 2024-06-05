#include "Problem_11006.h"

#include <iostream>

using namespace std;

int CProblem_11006::Solve_Problem()
{
    int iNumTC = { };
    cin >> iNumTC;

    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        int iNumLeg = { }, iNumChik = { };
        cin >> iNumLeg >> iNumChik;

        cout << iNumChik * 2 - iNumLeg << " " << iNumChik - (iNumChik * 2 - iNumLeg) << endl;
    }

    return 0;
}
