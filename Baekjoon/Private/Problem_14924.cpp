#include "Problem_14924.h"

#include <iostream>

using namespace std;

int CProblem_14924::Solve_Problem()
{
    int iS = { }, iT = { }, iD = { };
    cin >> iS >> iT >> iD;

    int iSrc = iD / (iS * 2);

    cout << iSrc * iT << endl;

    return 0;
}
