#include "Problem_0000.h"

#include <vector>

#include <iostream>

using namespace std;

int CProblem_0000::Solve_Problem()
{
    int iA = { }, iB = { };
    cin >> iA >> iB;

    if (iA == iB)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}
