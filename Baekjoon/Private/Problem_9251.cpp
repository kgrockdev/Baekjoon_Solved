#include "Problem_9251.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int CProblem_9251::Solve_Problem()
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

    int iAnswer = { };
    for (int iRow = 1; iRow < strB.size() + 1; ++iRow)
    {
        for (int iCol = 1; iCol < strA.size() + 1; ++iCol)
        {
            if (strA[iCol - 1] == strB[iRow - 1])
            {
                vecLCS[iRow][iCol] = vecLCS[iRow - 1][iCol - 1] + 1;
                iAnswer = (iAnswer > vecLCS[iRow][iCol]) ? iAnswer : vecLCS[iRow][iCol];
            }
            else
            {
                vecLCS[iRow][iCol] = 
                    (vecLCS[iRow - 1][iCol] > vecLCS[iRow][iCol - 1]) ?
                    vecLCS[iRow - 1][iCol] : vecLCS[iRow][iCol - 1];
            }
        }
    }

    cout << iAnswer << endl;

    return 0;
}
