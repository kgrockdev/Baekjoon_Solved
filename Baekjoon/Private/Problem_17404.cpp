#include "Problem_17404.h"

#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_17404::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    int arrContainer[3][1000] = { };
    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        cin >> arrContainer[0][iIndex] >> arrContainer[1][iIndex] >> arrContainer[2][iIndex];
    }

    for (int iIndex = 1; iIndex < iNum; ++iIndex)
    {
        arrContainer[0][iIndex] += min(arrContainer[1][iIndex - 1], arrContainer[2][iIndex - 1]);
        arrContainer[1][iIndex] += min(arrContainer[0][iIndex - 1], arrContainer[2][iIndex - 1]);
        arrContainer[2][iIndex] += min(arrContainer[0][iIndex - 1], arrContainer[1][iIndex - 1]);
    }

    cout << min({ arrContainer[0][iNum - 1], arrContainer[1][iNum - 1], arrContainer[2][iNum - 1] }) << endl;

    return 0;
}
