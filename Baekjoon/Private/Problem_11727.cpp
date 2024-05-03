#include "Problem_11727.h"

using namespace std;

#include <iostream>

int arrCont11727[1001] = { };

int Calc_11727(int iNum)
{
    if (arrCont11727[iNum] != -1)
        return arrCont11727[iNum];
    else
    {
        int iSrc = Calc_11727(iNum - 1) + Calc_11727(iNum - 2) * 2;
        arrCont11727[iNum] = iSrc % 10007;

        return arrCont11727[iNum];
    }
}

int CProblem_11727::Solve_Problem()
{
    fill_n(arrCont11727, 1001, -1);

    arrCont11727[0] = 0;
    arrCont11727[1] = 1;
    arrCont11727[2] = 3;

    int iNum = { };
    cin >> iNum;

    cout << Calc_11727(iNum) << '\n';


    return 0;
}
