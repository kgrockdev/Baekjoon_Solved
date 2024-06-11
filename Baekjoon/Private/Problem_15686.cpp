#include "Problem_15686.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_15686::Solve_Problem()
{
    int iNumRowCol = { }, iNumStore = { };
    cin >> iNumRowCol >> iNumStore;

    vector<pair<int, int>> vecHome;
    vector<pair<int, int>> vecStore;

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            if (iSrc == 1)
                vecHome.push_back({ iRow, iCol });
            else if (iSrc == 2)
                vecStore.push_back({ iRow, iCol });
        }
    }



    return 0;
}
