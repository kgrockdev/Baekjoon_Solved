#include "Problem_1463.h"

using namespace std;

#include <iostream>
#include <unordered_map>

#define INT_MAX 2147483647

int arrContainer[1000001] = { };

int Calc_1463(int iNumber)
{
    if (arrContainer[iNumber] != INT_MAX)
        return arrContainer[iNumber];
    else
    {
        int iDivThr = { INT_MAX }, iDivTwo = { INT_MAX }, iMulOne = { INT_MAX };

        if (iNumber % 3 == 0)
            iDivThr = Calc_1463(iNumber / 3) + 1;

        if (iNumber % 2 == 0)
            iDivTwo = Calc_1463(iNumber / 2) + 1;
        
        iMulOne = Calc_1463(iNumber - 1) + 1;

        int iMin = min(iDivThr, iDivTwo);
        iMin = min(iMin, iMulOne);

        arrContainer[iNumber] = iMin;

        return iMin;
    }

}

int CProblem_1463::Solve_Problem()
{
    fill_n(arrContainer, 1000001, INT_MAX);

    arrContainer[1] = 1;

    int iNumber = { };
    cin >> iNumber;

    cout << Calc_1463(iNumber) - 1 << '\n';

    return 0;
}
