#include "Problem_13301.h"

#include <iostream>

using namespace std;

int CProblem_13301::Solve_Problem()
{
    int iQuery = { };
    cin >> iQuery;

    unsigned long long arrullContainer[80] = {};
    arrullContainer[0] = 1;
    arrullContainer[1] = 1;
    arrullContainer[2] = 2;
    arrullContainer[3] = 3;
    arrullContainer[4] = 5;

    // n + n + n + n + n -1 + n - 1
    // 4n + 2n-1

    for (int iIndex = 5; iIndex < iQuery; ++iIndex)
    {
        arrullContainer[iIndex] = arrullContainer[iIndex - 1] + arrullContainer[iIndex - 2];
    }

    if (iQuery == 1)
        cout << 4;
    else
        cout << 4 * arrullContainer[iQuery - 1] + 2 * arrullContainer[iQuery - 2] << '\n';

    return 0;
}
