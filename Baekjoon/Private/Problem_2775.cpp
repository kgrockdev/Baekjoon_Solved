#include "Problem_2775.h"

#include <iostream>

using namespace std;

int CProblem_2775::Solve_Problem()
{
    int arrNumPeople[15][15] = { };
    for (int iCol = 0; iCol < 15; ++iCol)
    {
        arrNumPeople[0][iCol] = iCol;
    }

    for (int iRow = 1; iRow < 15; ++iRow)
    {
        for (int iCol = 0; iCol < 15; ++iCol)
        {
            arrNumPeople[iRow][iCol] = 
                arrNumPeople[iRow][iCol == 0 ? iCol : iCol - 1] + 
                arrNumPeople[iRow == 0 ? iRow : iRow - 1][iCol];
        }
    }

    int iNumTC = { };
    cin >> iNumTC;

    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        int iQueryRow = { }, iQueryCol = { };
        cin >> iQueryRow >> iQueryCol;

        cout << arrNumPeople[iQueryRow][iQueryCol] << '\n';
    }


    return 0;
}
