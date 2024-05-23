#include "Problem_2407.h"

#include <iostream>

using namespace std;

int CProblem_2407::Solve_Problem()
{
    int iN = { }, iM = { };
    cin >> iN >> iM;

    unsigned long long ullSrc = { 1 };
    for (int iIndex = 0; iIndex < iM; ++iIndex)
        ullSrc *= (iN - iIndex);

    for (int iIndex = 1; iIndex < iM + 1; ++iIndex)
        ullSrc /= iIndex;

    cout << ullSrc  << endl;

    return 0;
}
