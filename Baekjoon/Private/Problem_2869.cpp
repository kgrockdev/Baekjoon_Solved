#include "Problem_2869.h"

#include <iostream>

using namespace std;

int CProblem_2869::Solve_Problem()
{
    int iA = { }, iB = { }, iV = { };
    cin >> iA >> iB >> iV;

    int iUp = iA - iB;
    iV -= iA;

    int iAnswer = iV / iUp;
    iAnswer += (iV % iUp > 0) ? 1 : 0;
    cout << iAnswer + 1 << endl;

    return 0;
}