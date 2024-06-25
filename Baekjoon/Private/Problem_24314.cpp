#include "Problem_24314.h"

#include <iostream>

using namespace std;

inline int Func_24314(int iA0, int iA1, int iN)
{
    return iA1 * iN + iA0;
}

int CProblem_24314::Solve_Problem()
{
    int iA0 = { }, iA1 = { }, iC = { }, iN0 = { };

    cin >> iA1 >> iA0 >> iC >> iN0;

    for (int iN = iN0; iN < 100000000; ++iN)
    {
        if (iC * iN > Func_24314(iA0, iA1, iN))
        {
            cout << "0" << endl;
            return 0;
        }
    }

    cout << "1" << endl;
    return 0;
}

//  f(n) = a1n + a0