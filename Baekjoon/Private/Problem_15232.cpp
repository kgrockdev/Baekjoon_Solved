#include "Problem_15232.h"

#include <iostream>

using namespace std;

int CProblem_15232::Solve_Problem()
{
    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            cout << "*";
        }

        cout << "\n";
    }

    return 0;
}
