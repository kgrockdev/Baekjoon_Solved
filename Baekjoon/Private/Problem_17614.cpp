#include "Problem_17614.h"

#include <iostream>

using namespace std;

int CProblem_17614::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    int iAnswer = { };
    for (int iIndex = 1; iIndex < iNum + 1; ++iIndex)
    {
        int iSrc = iIndex;
        while (iSrc > 0)
        {
            int iTemp = iSrc % 10;
            if (iTemp != 0 && iTemp % 3 == 0)
                ++iAnswer;

            iSrc /= 10;
        }
    }

    cout << iAnswer << endl;

    return 0;
}