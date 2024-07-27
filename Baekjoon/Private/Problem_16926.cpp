#include "Problem_16926.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_16926::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRow = { }, iNumCol = { }, iNumRot = { };
    cin >> iNumRow >> iNumCol >> iNumRot;

    vector<vector<int>> vecContainer;

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumRow; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecSrc.push_back(iSrc);
        }

        vecContainer.push_back(vecSrc);
    }

    /* Answer */
    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        for (int iCol = 0; iCol < iNumRow; ++iCol)
        {
            cout << vecContainer[iRow][iCol] << " ";
        }
        cout << '\n';
    }

    return 0;
}

/*

4 5

0   13  12  11  10
1   0   5   4   9
2   1   2   3   8
3   4   5   6   7

(4 + 5) * 2 - 4
(2 + 3) * 2 - 4

*/