#include "Problem_2193.h"

#include <iostream>

using namespace std;

int CProblem_2193::Solve_Problem()
{
    int iQuery = { };
    cin >> iQuery;

    unsigned long long arrContainer[90] = { };
    arrContainer[0] = 1;
    arrContainer[1] = 1;

    for (int iIndex = 2; iIndex < iQuery; ++iIndex)
    {
        arrContainer[iIndex] = arrContainer[iIndex - 1] + arrContainer[iIndex - 2];
    }
    cout << arrContainer[iQuery - 1] << '\n';

    return 0;
}
