#include "Problem_25314.h"

#include <iostream>

using namespace std;

int CProblem_25314::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    for (int iIndex = 0; iIndex < iNum / 4; ++iIndex)
        cout << "long ";

    cout << "int";

    return 0;
}
