#include "Problem_26209.h"

#include <iostream>

using namespace std;

int CProblem_26209::Solve_Problem()
{
    int iSrc = { };
    bool bCheck = { false };

    for (int iIndex = 0; iIndex < 8; ++iIndex)
    {
        cin >> iSrc;
        if (iSrc > 2)
            bCheck = true;
    }

    if (bCheck == true)
        cout << "F" << endl;
    else
        cout << "S" << endl;

    return 0;
}
