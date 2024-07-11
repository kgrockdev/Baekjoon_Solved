#include "Problem_2292.h"

#include <iostream>

using namespace std;

int CProblem_2292::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    int iAnswer = { }, iDigit = { 1 };
    while (iNum > 0)
    {
        ++iAnswer;

        iNum = iNum - iDigit;
        
        if (iDigit < 6)
            iDigit = 6;
        else
            iDigit += 6;
    }

    cout << iAnswer << endl;

    return 0;
}