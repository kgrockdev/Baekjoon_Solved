#include "Problem_1018.h"

using namespace std;

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

int CProblem_1018::Solve_Problem()
{
    int iN = { }, iM = { };
    cin >> iN >> iM;

    vector<string> vecContainer;

    for (int iIndex = 0; iIndex < iN; ++iIndex)
    {
        string strSrc = { };
        cin >> strSrc;
        vecContainer.push_back(strSrc);
    }

    int iMinRect = { 2147483647 };
    int iNumRow = { iN - 8 + 1 }, iNumCol = { iM - 8 + 1 };
    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            int iBlack = { }, iWhite = { };
            for (int iSRow = 0; iSRow < 8; ++iSRow)
            {
                for (int iSCol = 0; iSCol < 8; ++iSCol)
                {
                    if (iSRow % 2 == iSCol % 2)
                    {
                        if (vecContainer[iRow + iSRow][iCol + iSCol] == 'W')
                            iBlack++;
                        else
                            iWhite++;
                    }
                    else
                    {
                        if (vecContainer[iRow + iSRow][iCol + iSCol] == 'W')
                            iWhite++;
                        else
                            iBlack++;
                    }

                    if (iMinRect <= iBlack && iMinRect <= iWhite)
                        break;
                }

                if (iMinRect <= iBlack && iMinRect <= iWhite)
                    break;
            }

            iMinRect = min(iMinRect, iBlack);
            iMinRect = min(iMinRect, iWhite);
        }
    }

    cout << iMinRect << '\n';

    return 0;
}