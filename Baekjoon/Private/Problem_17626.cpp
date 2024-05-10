#include "Problem_17626.h"

#define INT_MAX       2147483647

#include <cmath>
#include <iostream>

using namespace std;

int CProblem_17626::Solve_Problem()
{
    int arrContainer17626[50001] = { };

    fill_n(arrContainer17626, 50001, INT_MAX);
    arrContainer17626[0] = 0;
    arrContainer17626[1] = 1;

    int iQuery = { };
    cin >> iQuery;

    for (int iIndex = 2; iIndex <= sqrt(iQuery); ++iIndex)
        arrContainer17626[iIndex * iIndex] = 1;

    for (int iIndex = 2; iIndex <= iQuery; ++iIndex)
    {
        if (arrContainer17626[iIndex] != INT_MAX)
            continue;

        int iNumPow = { 1 }, iSelIdx = { }, iSelMin = { INT_MAX };
        while (true)
        {
            if (iNumPow * iNumPow > iIndex)
                break;

            int iSrc = arrContainer17626[iNumPow * iNumPow] + arrContainer17626[iIndex - iNumPow * iNumPow];
            if (iSelMin > iSrc)
            {
                iSelMin = iSrc;
                iSelIdx = iIndex;
            }

            iNumPow += 1;
        }

        arrContainer17626[iIndex] = iSelMin;
    }

    cout << arrContainer17626[iQuery] << '\n';

    return 0;
}