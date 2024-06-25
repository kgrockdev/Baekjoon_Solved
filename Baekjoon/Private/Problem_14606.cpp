#include "Problem_14606.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_14606::Solve_Problem()
{
    int iNum = { }, iScore = { };
    cin >> iNum;

    if (iNum <= 1)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> vecContainer;
    vecContainer.push_back(iNum);

    while (vecContainer.size() > 0)
    {
        int iSrc = vecContainer.back();
        vecContainer.pop_back();

        if (iSrc % 2 == 0)
        {
            int iTemp = iSrc / 2;

            iScore += iTemp * iTemp;

            if (iTemp != 1)
            {
                vecContainer.push_back(iTemp);
                vecContainer.push_back(iTemp);
            }
        }
        else
        {
            int iTempA = iSrc / 2;
            int iTempB = iSrc / 2 + 1;

            iScore += iTempA * iTempB;

            if (iTempA != 1)
                vecContainer.push_back(iTempA);

            if (iTempB != 1)
                vecContainer.push_back(iTempB);
        }
    }

    cout << iScore << endl;

    return 0;
}
