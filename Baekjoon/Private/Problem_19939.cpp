#include "Problem_19939.h"

#include <iostream>

using namespace std;

int CProblem_19939::Solve_Problem()
{
    int iN = { }, iK = { };
    cin >> iN >> iK;

    int iR = { };
    if (iK % 2 == 0) 
        iR = (1 + iK) * (iK / 2);
    else
        iR = (1 + (iK - 1)) * ((iK - 1) / 2) + iK;

    if (iN < iR)
        cout << -1 << endl;
    else
        cout << (((iN - iR) % iK == 0) ? iK - 1 : iK) << endl;

    return 0;
}
