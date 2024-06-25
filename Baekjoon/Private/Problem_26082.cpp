#include "Problem_26082.h"

#include <iostream>

using namespace std;

int CProblem_26082::Solve_Problem()
{
    int iA = { }, iB = { }, iC = { };
    cin >> iA >> iB >> iC;

    cout << (iB / iA) * 3 * iC << endl;

    return 0;
}
