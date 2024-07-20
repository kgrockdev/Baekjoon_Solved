#include "Problem_5582.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int CProblem_5582::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string strSrcA = { }, strSrcB = { };
    cin >> strSrcA >> strSrcB;

    vector<vector<int>> vecLCS;

    for (int iRow = 0; iRow < strSrcA.size() + 1; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < strSrcB.size() + 1; ++iCol)
            vecSrc.push_back(0);

        vecLCS.push_back(vecSrc);
    }

    int iAnswer = { };
    for (int iRow = 1; iRow < strSrcA.size() + 1; ++iRow)
    {
        for (int iCol = 1; iCol < strSrcB.size() + 1; ++iCol)
        {
            if (strSrcA[iRow - 1] == strSrcB[iCol - 1])
            {
                vecLCS[iRow][iCol] = vecLCS[iRow - 1][iCol - 1] + 1;
                iAnswer = iAnswer > vecLCS[iRow][iCol] ? iAnswer : vecLCS[iRow][iCol];
            }
            else
            {
                vecLCS[iRow][iCol] = 0;
            }
        }
    }

    cout << iAnswer << '\n';

    return 0;
}
