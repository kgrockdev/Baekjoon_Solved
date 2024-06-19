#include "Problem_27433.h"

#include <iostream>

using namespace std;

unsigned long long Recursive_27433(int iNum)
{
    if (iNum == 0 || iNum == 1)
        return 1;
    else
        return iNum * Recursive_27433(iNum - 1);
}

int CProblem_27433::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    cout << Recursive_27433(iNum) << endl;

    return 0;
}
