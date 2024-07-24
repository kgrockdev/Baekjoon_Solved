#include "Problem_1193.h"

#include <iostream>

using namespace std;

int CProblem_1193::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    int iDigit = { 1 }, iSum = { 0 };

    while (iNum > iSum)
    {
        iSum += iDigit;
        ++iDigit;
    }

    --iDigit;
    iNum -= (iSum - iDigit);

    if (iDigit % 2 == 0)
        cout << iNum << "/" << (iDigit - iNum + 1) << '\n';
    else
        cout << (iDigit - iNum + 1) << "/" << iNum << '\n';

    //iDigit - iNum + 1

    return 0;
}