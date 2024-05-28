#include "Problem_2167.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_2167::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRow = { }, iNumCol = { }, iSrc = { };
    cin >> iNumRow >> iNumCol;

    vector<vector<int>> vecArray;
    vecArray.reserve(iNumRow);

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        vecSrc.reserve(iNumCol + 1);
        vecSrc.push_back(0);
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            cin >> iSrc;
            iSrc += vecSrc.back();

            vecSrc.push_back(iSrc);
        }

        vecArray.push_back(vecSrc);
    }

    int iNumTC = { }, iAX = { }, iAY = { }, iBX = { }, iBY = { };
    cin >> iNumTC;

    int iRes = { };
    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        iRes = { 0 };
        cin >> iAY >> iAX >> iBY >> iBX;

        for (int iY = iAY - 1; iY < iBY; ++iY)
        {
            iRes += vecArray[iY][iBX] - vecArray[iY][iAX - 1];
        }

        cout << iRes << '\n';
    }

    return 0;
}
