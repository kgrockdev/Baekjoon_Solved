#include "Problem_5426.h"

#include <cmath>
#include <iostream>

using namespace std;

int CProblem_5426::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumTC = { };
    cin >> iNumTC;

    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        string strSrc = { };
        cin >> strSrc;

        int iNumRC = { };
        iNumRC = sqrt(strSrc.length());

        string strRes = { };
        for (int iRow = 0; iRow < iNumRC; ++iRow)
        {
            for (int iCol = 0; iCol < iNumRC; ++iCol)
            {
                int iDigit = { ((iNumRC - 1) - iRow) + (iNumRC * iCol)};
                strRes.push_back(strSrc[iDigit]);
            }
        }

        cout << strRes << '\n';
    }

    return 0;
}

/*
2 5 8
1 4 7
0 3 6
*/