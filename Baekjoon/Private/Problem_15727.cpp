#include "Problem_15727.h"

#include <iostream>

using namespace std;

int CProblem_15727::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    cout << iNum / 5 + (iNum % 5 > 0 ? 1 : 0) << endl;

    return 0;
}
