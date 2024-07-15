#include "Problem_9252.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_9252::Solve_Problem()
{
    string strA = { }, strB = { };
    cin >> strA >> strB;

    vector<vector<int>> vecLCS;

    for (int iRow = 0; iRow < strB.size() + 1; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < strA.size() + 1; ++iCol)
            vecSrc.push_back(0);

        vecLCS.push_back(vecSrc);
    }

    for (int iRow = 1; iRow < strB.size() + 1; ++iRow)
    {
        for (int iCol = 1; iCol < strA.size() + 1; ++iCol)
        {
            if (strB[iRow - 1] == strA[iCol - 1])
            {
                vecLCS[iRow][iCol] = vecLCS[iRow - 1][iCol - 1] + 1;
            }
            else
            {
                int iSrc =
                    (vecLCS[iRow - 1][iCol] > vecLCS[iRow][iCol - 1]) ?
                    vecLCS[iRow - 1][iCol] : vecLCS[iRow][iCol - 1];

                vecLCS[iRow][iCol] = iSrc;
            }
        }
    }

    int iRow = strB.size(), iCol = strA.size();
    string strAnsLCS = { };
    while (true)
    {
        if (vecLCS[iRow][iCol] == 0)
            break;

        if (vecLCS[iRow - 1][iCol] == vecLCS[iRow][iCol])
        {
            --iRow;
            continue;
        }

        if (vecLCS[iRow][iCol - 1] == vecLCS[iRow][iCol])
        {
            --iCol;
            continue;
        }

        strAnsLCS.push_back(strA[iCol - 1]);
        --iRow;
        --iCol;
    }

    reverse(strAnsLCS.begin(), strAnsLCS.end());

    cout << vecLCS[strB.size()][strA.size()] << '\n';

    if (vecLCS[strB.size()][strA.size()] > 0)
        cout << strAnsLCS << '\n';

    return 0;
}
