#include "Problem_15988.h"

#include <iostream>

using namespace std;

int CProblem_15988::Solve_Problem()
{
    int arrContainer[1000000] = { };
    arrContainer[0] = 1;
    arrContainer[1] = 2;
    arrContainer[2] = 4;

    int iNumTC = { };
    cin >> iNumTC;

    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        int iQuery = { };
        cin >> iQuery;

        for (int iIndex = 3; iIndex < iQuery; ++iIndex)
        {
            arrContainer[iIndex] = 
                ((long long)arrContainer[iIndex - 3] + 
                (long long)arrContainer[iIndex - 2] +
                (long long)arrContainer[iIndex - 1]) % 1000000009;
        }

        cout << arrContainer[iQuery - 1] << '\n';
    }
     
    return 0;
}
