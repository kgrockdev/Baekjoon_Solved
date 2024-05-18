#include "Problem_1904.h"

#include <iostream>

using namespace std;

int CProblem_1904::Solve_Problem()
{
    int arrContainer[1000000] = { };

    int iQuery = { };
    cin >> iQuery;

    arrContainer[0] = 1;
    arrContainer[1] = 2;

    for (int iIndex = 2; iIndex < iQuery; ++iIndex)
    {
        arrContainer[iIndex] = (arrContainer[iIndex - 1] + arrContainer[iIndex - 2]) % 15746;
    }
    cout << arrContainer[iQuery - 1] << '\n';

    return 0;
}